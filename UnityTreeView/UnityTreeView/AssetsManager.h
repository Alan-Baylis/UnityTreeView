#pragma once

#include <stdio.h>
#include <map>
#include <tuple>
#include "MarshalManager.h"
#include "ClassHelper.h"
#include "Extras.h"
#include "AssetsTools\AssetsFileFormat.h"
#include "AssetsTools\AssetsFileTable.h"
#include "AssetsTools\AssetsFileReader.h"
#include "AssetsTools\AssetTypeClass.h"

namespace UnityTreeView {
	public class AssetsManagerEx {
		public: static struct AssetExternal {
			AssetFileInfoEx* info;
			AssetTypeInstance* instance;
		};
	};
	public ref class AssetsManager
	{
		public:
			FILE* file;
			FILE* classFile;
			AssetsFile* initialFile;
			AssetsFileTable* initialTable;
			ClassDatabaseFile* initialClassFile;
			std::vector<std::tuple<std::string, FILE*, AssetsFile*, AssetsFileTable*>>* dependencies;
			std::vector<AssetTypeTemplateField*>* attfs;
		public: AssetsManager() {
			attfs = new std::vector<AssetTypeTemplateField*>();
			dependencies = new std::vector<std::tuple<std::string, FILE*, AssetsFile*, AssetsFileTable*>>();
		}
		public: void LoadAssets(System::String^ path) {
			file = fopen(MarshalManager::SysToStd(path).c_str(), "rb");
			initialFile = new AssetsFile(AssetsReaderFromFile, (LPARAM)file);
			initialTable = new AssetsFileTable(initialFile);

			std::string pathString = MarshalManager::SysToStd(path);
			std::string containingFolder = pathString.substr(0, pathString.find_last_of("/\\"));

			for (int i = 0; i < initialFile->dependencies.dependencyCount; i++) {
				std::tuple<std::string, FILE*, AssetsFile*, AssetsFileTable*> assetDependency;
				std::string depName = initialFile->dependencies.pDependencies[i].assetPath;
				FILE* depFile = fopen((containingFolder + "\\" + Extras::ReplaceAll(depName, "library/", "Resources\\")).c_str(), "rb");
				AssetsFile* depAssetsFile = new AssetsFile(AssetsReaderFromFile, (LPARAM)depFile);
				AssetsFileTable* depAssetsFileTable = new AssetsFileTable(depAssetsFile);
				assetDependency = make_tuple(depName, depFile, depAssetsFile, depAssetsFileTable);
				dependencies->push_back(assetDependency);
			}
		}
		public: void LoadClassFile(System::String^ path) {
			classFile = fopen(MarshalManager::SysToStd(path).c_str(), "rb");
			initialClassFile = new ClassDatabaseFile();
			initialClassFile->Read(AssetsReaderFromFile, (LPARAM)classFile);
		}
		public: AssetTypeInstance* GetATI(FILE* file, AssetFileInfoEx* info) {
			size_t index;
			bool foundInList = false;
			for (size_t i = 0; i < attfs->size(); i++) {
				if (attfs->at(i)->name == info->name) {
					index = i;
					foundInList = true;
				}
			}
			if (foundInList) {
				AssetTypeInstance* ati = new AssetTypeInstance(1, &attfs->at(index), AssetsReaderFromFile, (LPARAM)file, false, info->absolutePos);
				return ati; //todo refactor one variable                ^
			} else {
				AssetTypeTemplateField* pBaseField = new AssetTypeTemplateField();
				pBaseField->FromClassDatabase(initialClassFile, ClassHelper::ClassFromInfo(initialClassFile, info), (DWORD)0);
				attfs->push_back(pBaseField);
				AssetTypeInstance* ati = new AssetTypeInstance(1, &attfs->back(), AssetsReaderFromFile, (LPARAM)file, false, info->absolutePos);
				return ati;
			}
		}
		public: AssetsManagerEx::AssetExternal GetExtAsset(AssetTypeValueField* atvf) {
			AssetsManagerEx::AssetExternal ext;
			if (atvf->Get("m_FileID")->GetValue()->AsInt() != 0) {
				std::tuple<std::string, FILE*, AssetsFile*, AssetsFileTable*> dep = this->dependencies->at(atvf->Get("m_FileID")->GetValue()->AsInt() - 1);
				ext.info = std::get<3>(dep)->getAssetInfo(atvf->Get("m_PathID")->GetValue()->AsInt64());
				ext.instance = this->GetATI(std::get<1>(dep), ext.info);
			} else {
				ext.info = initialTable->getAssetInfo(atvf->Get("m_PathID")->GetValue()->AsInt64());
				ext.instance = this->GetATI(file, ext.info);
			}
			return ext;
		}
	};
}