#pragma once

#include "AssetsTools\AssetsFileTable.h"
#include "AssetsTools\AssetTypeClass.h"

namespace UnityTreeView {
	public ref class ClassHelper
	{
		public: static ClassDatabaseType* ClassFromInfo(ClassDatabaseFile* classDatabaseFile, AssetFileInfoEx* assetFileInfo) {
			return &classDatabaseFile->classes[findAssetClass(classDatabaseFile, assetFileInfo)];
		}
		//Copy paste from dkb
		public: static int findAssetClass(ClassDatabaseFile* classDatabaseFile, AssetFileInfoEx* assetsFileInfo) {
			int position = 0;
			for (std::vector<ClassDatabaseType>::iterator it2 = classDatabaseFile->classes.begin(); it2 != classDatabaseFile->classes.end(); ++it2) {
				if (it2->classId == assetsFileInfo->inheritedUnityClass) {
					return position;
				}
				position++;
			}
			return -1;
		}
		public: static std::string GetNameById(ClassDatabaseFile* classDatabaseFile, int id) {
			int position = 0;
			for (std::vector<ClassDatabaseType>::iterator it2 = classDatabaseFile->classes.begin(); it2 != classDatabaseFile->classes.end(); ++it2) {
				if (it2->classId == id) {
					return it2->name.GetString(classDatabaseFile);
				}
				position++;
			}
			return "";
		}
	};
}

