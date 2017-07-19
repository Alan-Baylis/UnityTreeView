#pragma once

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <tuple>
#include "AssetsManager.h"
#include "Extras.h"
#include "AssetsTools\AssetsFileTable.h"

namespace UnityTreeView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	FILE* mainFile = NULL;
	FILE* classFile = NULL;

	/// <summary>
	/// Summary for TreeView
	/// </summary>
	public ref class TreeView : public System::Windows::Forms::Form
	{
	public:
		TreeView(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TreeView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^  fileTree;
	private: System::Windows::Forms::TreeView^  componentTree;
	protected:

	protected: 

	private: System::Windows::Forms::TextBox^  fileTextBox;
	private: System::Windows::Forms::Button^  openFileDialogButton;
	private: System::Windows::Forms::DataGridView^  scriptGrid;




	private: System::Windows::Forms::Button^  openFile;
	private: System::Windows::Forms::Button^  closeFile;





	private: System::Windows::Forms::SplitContainer^  splitsLeft;
	private: System::Windows::Forms::SplitContainer^  splitsRight;
	private: System::Windows::Forms::Button^  loadComponents;





	private: System::Windows::Forms::TextBox^  searchBox;
	private: System::Windows::Forms::Button^  searchStart;



	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  searchForward;

	private: System::Windows::Forms::Button^  searchBackward;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NumberHeader;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NameHeader;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TypeHeader;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ValueHeader;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TreeView::typeid));
			this->fileTree = (gcnew System::Windows::Forms::TreeView());
			this->componentTree = (gcnew System::Windows::Forms::TreeView());
			this->fileTextBox = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialogButton = (gcnew System::Windows::Forms::Button());
			this->scriptGrid = (gcnew System::Windows::Forms::DataGridView());
			this->NumberHeader = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameHeader = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TypeHeader = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ValueHeader = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->openFile = (gcnew System::Windows::Forms::Button());
			this->closeFile = (gcnew System::Windows::Forms::Button());
			this->splitsLeft = (gcnew System::Windows::Forms::SplitContainer());
			this->splitsRight = (gcnew System::Windows::Forms::SplitContainer());
			this->loadComponents = (gcnew System::Windows::Forms::Button());
			this->searchBox = (gcnew System::Windows::Forms::TextBox());
			this->searchStart = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->searchForward = (gcnew System::Windows::Forms::Button());
			this->searchBackward = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scriptGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitsLeft))->BeginInit();
			this->splitsLeft->Panel1->SuspendLayout();
			this->splitsLeft->Panel2->SuspendLayout();
			this->splitsLeft->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitsRight))->BeginInit();
			this->splitsRight->Panel1->SuspendLayout();
			this->splitsRight->Panel2->SuspendLayout();
			this->splitsRight->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fileTree
			// 
			this->fileTree->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->fileTree->Location = System::Drawing::Point(3, 3);
			this->fileTree->Name = L"fileTree";
			this->fileTree->Size = System::Drawing::Size(234, 317);
			this->fileTree->TabIndex = 0;
			this->fileTree->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &TreeView::fileTree_BeforeExpand);
			// 
			// componentTree
			// 
			this->componentTree->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->componentTree->Location = System::Drawing::Point(3, 3);
			this->componentTree->Name = L"componentTree";
			this->componentTree->Size = System::Drawing::Size(235, 295);
			this->componentTree->TabIndex = 1;
			// 
			// fileTextBox
			// 
			this->fileTextBox->Location = System::Drawing::Point(15, 11);
			this->fileTextBox->Name = L"fileTextBox";
			this->fileTextBox->Size = System::Drawing::Size(190, 20);
			this->fileTextBox->TabIndex = 3;
			// 
			// openFileDialogButton
			// 
			this->openFileDialogButton->Location = System::Drawing::Point(211, 11);
			this->openFileDialogButton->Name = L"openFileDialogButton";
			this->openFileDialogButton->Size = System::Drawing::Size(27, 20);
			this->openFileDialogButton->TabIndex = 4;
			this->openFileDialogButton->Text = L"...";
			this->openFileDialogButton->UseVisualStyleBackColor = true;
			this->openFileDialogButton->Click += gcnew System::EventHandler(this, &TreeView::openFileDialogButton_Click);
			// 
			// scriptGrid
			// 
			this->scriptGrid->AllowUserToAddRows = false;
			this->scriptGrid->AllowUserToDeleteRows = false;
			this->scriptGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->scriptGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->scriptGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->scriptGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->NumberHeader,
					this->NameHeader, this->TypeHeader, this->ValueHeader
			});
			this->scriptGrid->Location = System::Drawing::Point(3, 3);
			this->scriptGrid->Name = L"scriptGrid";
			this->scriptGrid->ReadOnly = true;
			this->scriptGrid->Size = System::Drawing::Size(215, 317);
			this->scriptGrid->TabIndex = 2;
			// 
			// NumberHeader
			// 
			this->NumberHeader->FillWeight = 50;
			this->NumberHeader->HeaderText = L"#";
			this->NumberHeader->Name = L"NumberHeader";
			this->NumberHeader->ReadOnly = true;
			// 
			// NameHeader
			// 
			this->NameHeader->HeaderText = L"Name";
			this->NameHeader->Name = L"NameHeader";
			this->NameHeader->ReadOnly = true;
			// 
			// TypeHeader
			// 
			this->TypeHeader->HeaderText = L"Type";
			this->TypeHeader->Name = L"TypeHeader";
			this->TypeHeader->ReadOnly = true;
			// 
			// ValueHeader
			// 
			this->ValueHeader->HeaderText = L"Value";
			this->ValueHeader->Name = L"ValueHeader";
			this->ValueHeader->ReadOnly = true;
			// 
			// openFile
			// 
			this->openFile->Location = System::Drawing::Point(244, 11);
			this->openFile->Name = L"openFile";
			this->openFile->Size = System::Drawing::Size(43, 20);
			this->openFile->TabIndex = 6;
			this->openFile->Text = L"Open";
			this->openFile->UseVisualStyleBackColor = true;
			this->openFile->Click += gcnew System::EventHandler(this, &TreeView::openFile_Click);
			// 
			// closeFile
			// 
			this->closeFile->Location = System::Drawing::Point(293, 11);
			this->closeFile->Name = L"closeFile";
			this->closeFile->Size = System::Drawing::Size(43, 20);
			this->closeFile->TabIndex = 7;
			this->closeFile->Text = L"Close";
			this->closeFile->UseVisualStyleBackColor = true;
			// 
			// splitsLeft
			// 
			this->splitsLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitsLeft->Location = System::Drawing::Point(12, 37);
			this->splitsLeft->Name = L"splitsLeft";
			// 
			// splitsLeft.Panel1
			// 
			this->splitsLeft->Panel1->Controls->Add(this->fileTree);
			// 
			// splitsLeft.Panel2
			// 
			this->splitsLeft->Panel2->Controls->Add(this->splitsRight);
			this->splitsLeft->Size = System::Drawing::Size(710, 323);
			this->splitsLeft->SplitterDistance = 240;
			this->splitsLeft->TabIndex = 8;
			// 
			// splitsRight
			// 
			this->splitsRight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitsRight->Location = System::Drawing::Point(0, 0);
			this->splitsRight->Name = L"splitsRight";
			// 
			// splitsRight.Panel1
			// 
			this->splitsRight->Panel1->Controls->Add(this->loadComponents);
			this->splitsRight->Panel1->Controls->Add(this->componentTree);
			// 
			// splitsRight.Panel2
			// 
			this->splitsRight->Panel2->Controls->Add(this->scriptGrid);
			this->splitsRight->Size = System::Drawing::Size(466, 323);
			this->splitsRight->SplitterDistance = 241;
			this->splitsRight->TabIndex = 0;
			// 
			// loadComponents
			// 
			this->loadComponents->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loadComponents->Location = System::Drawing::Point(3, 300);
			this->loadComponents->Name = L"loadComponents";
			this->loadComponents->Size = System::Drawing::Size(235, 20);
			this->loadComponents->TabIndex = 9;
			this->loadComponents->Text = L"Load Components";
			this->loadComponents->UseVisualStyleBackColor = true;
			// 
			// searchBox
			// 
			this->searchBox->Location = System::Drawing::Point(342, 12);
			this->searchBox->Name = L"searchBox";
			this->searchBox->Size = System::Drawing::Size(152, 20);
			this->searchBox->TabIndex = 9;
			// 
			// searchStart
			// 
			this->searchStart->Location = System::Drawing::Point(0, 6);
			this->searchStart->Name = L"searchStart";
			this->searchStart->Size = System::Drawing::Size(18, 23);
			this->searchStart->TabIndex = 10;
			this->searchStart->Text = L"S";
			this->searchStart->UseVisualStyleBackColor = true;
			this->searchStart->Click += gcnew System::EventHandler(this, &TreeView::searchStart_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->searchForward);
			this->groupBox1->Controls->Add(this->searchBackward);
			this->groupBox1->Controls->Add(this->searchStart);
			this->groupBox1->Location = System::Drawing::Point(504, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(52, 29);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			// 
			// searchForward
			// 
			this->searchForward->Location = System::Drawing::Point(34, 6);
			this->searchForward->Name = L"searchForward";
			this->searchForward->Size = System::Drawing::Size(18, 23);
			this->searchForward->TabIndex = 12;
			this->searchForward->Text = L"F";
			this->searchForward->UseVisualStyleBackColor = true;
			this->searchForward->Click += gcnew System::EventHandler(this, &TreeView::searchForward_Click);
			// 
			// searchBackward
			// 
			this->searchBackward->Location = System::Drawing::Point(17, 6);
			this->searchBackward->Name = L"searchBackward";
			this->searchBackward->Size = System::Drawing::Size(18, 23);
			this->searchBackward->TabIndex = 11;
			this->searchBackward->Text = L"B";
			this->searchBackward->UseVisualStyleBackColor = true;
			this->searchBackward->Click += gcnew System::EventHandler(this, &TreeView::searchBackward_Click);
			// 
			// TreeView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 372);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->searchBox);
			this->Controls->Add(this->splitsLeft);
			this->Controls->Add(this->closeFile);
			this->Controls->Add(this->openFile);
			this->Controls->Add(this->openFileDialogButton);
			this->Controls->Add(this->fileTextBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TreeView";
			this->Text = L"TreeView - Unity 5.6";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scriptGrid))->EndInit();
			this->splitsLeft->Panel1->ResumeLayout(false);
			this->splitsLeft->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitsLeft))->EndInit();
			this->splitsLeft->ResumeLayout(false);
			this->splitsRight->Panel1->ResumeLayout(false);
			this->splitsRight->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitsRight))->EndInit();
			this->splitsRight->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: AssetsManager^ assetManager;
public: System::String^ filePath;
private: int searchEncounter;
private:System::Void openFileDialogButton_Click(System::Object^  sender, System::EventArgs^  e) {
			OpenFileDialog^ ofd = gcnew OpenFileDialog();
			ofd->Filter = "All types (*.*)|*.*|Assets files (*.assets)|*.assets";
			if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				fileTextBox->Text = ofd->FileName;
			}
		}
private:System::Void openFile_Click(System::Object^  sender, System::EventArgs^  e) {
			filePath = fileTextBox->Text;
			this->Text = "TreeView - Unity 5.6 [" + System::IO::Path::GetFileName(filePath) + "]";
			assetManager = gcnew AssetsManager();
			assetManager->LoadAssets(filePath);
			assetManager->LoadClassFile(MarshalManager::StdToSys(Extras::GetExecutablePath()) + "\\highestunity.dat");
			for (int i = 0; i < assetManager->initialTable->assetFileInfoCount; i++) {
				AssetFileInfoEx info = assetManager->initialTable->pAssetFileInfo[i];
				AssetTypeInstance* ati = assetManager->GetATI(assetManager->file, &info);
				System::String^ name = "";

				if (info.inheritedUnityClass == 0x72) {
					AssetsManagerEx::AssetExternal scriptExt = assetManager->GetExtAsset(ati->GetBaseField()->Get("m_Script"));
					//AssetFileInfoEx* scriptInfo = scriptExt.info;
					AssetTypeInstance* scriptAti = scriptExt.instance;
					name = MarshalManager::StdToSys(scriptAti->GetBaseField()->Get("m_Name")->GetValue()->AsString());
				} else if (!ati->GetBaseField()->Get("m_Name")->IsDummy()) {
					name = MarshalManager::StdToSys(ati->GetBaseField()->Get("m_Name")->GetValue()->AsString());
				} else {
					name = "Unnammed asset";
				}
				name = MarshalManager::StdToSys(std::to_string((long double)info.index)) + "|" + name + "(" + MarshalManager::StdToSys(ClassHelper::GetNameById(assetManager->initialClassFile, info.inheritedUnityClass) + ")");
				TreeNode^ tn = fileTree->Nodes->Add(name);
				if (info.curFileType == 1) {
					tn->Nodes->Add("loading...");
				}
			}
		}
private:System::Void fileTree_BeforeExpand(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) {
			TreeNode^ tn = e->Node;
			if (tn->Nodes[0]->Text == "loading...") {
				tn->Nodes[0]->Remove();
				AssetFileInfoEx* info = assetManager->initialTable->getAssetInfo(std::stoi(MarshalManager::SysToStd(tn->Text->Split('|')[0])));
				AssetTypeInstance* ati = assetManager->GetATI(assetManager->file, info);
				
				AssetsManagerEx::AssetExternal transformExt = assetManager->GetExtAsset(ati->GetBaseField()->Get("m_Component")->Get("Array")->Get(0U)->Get("component"));
				AssetTypeInstance* transformAti = transformExt.instance;

				AssetTypeValueField* children = transformAti->GetBaseField()->Get("m_Children")->Get("Array");
				for (unsigned int i = 0; i < children->GetValue()->AsArray()->size; i++) {
					AssetsManagerEx::AssetExternal childExt = assetManager->GetExtAsset(children->Get(i));
					AssetTypeInstance* childAti = childExt.instance;

					AssetsManagerEx::AssetExternal goExt = assetManager->GetExtAsset(childAti->GetBaseField()->Get("m_GameObject"));
					AssetFileInfoEx* goInfo = goExt.info;
					AssetTypeInstance* goAti = goExt.instance;

					TreeNode^ childTn = tn->Nodes->Add(goInfo->index + "|" + MarshalManager::StdToSys(goAti->GetBaseField()->Get("m_Name")->GetValue()->AsString()) + "(" + MarshalManager::StdToSys(ClassHelper::GetNameById(assetManager->initialClassFile, goInfo->inheritedUnityClass)) + ")"); //redundant to check class but whatever

					AssetsManagerEx::AssetExternal transformExt2 = assetManager->GetExtAsset(goAti->GetBaseField()->Get("m_Component")->Get("Array")->Get(0U)->Get("component"));
					AssetTypeInstance* transformAti2 = transformExt2.instance;

					if (transformAti2->GetBaseField()->Get("m_Children")->Get("Array")->GetValue()->AsArray()->size != 0) {
						childTn->Nodes->Add("loading...");
					}
				}

				/*for (unsigned int i = 0; i < contentArray->GetValue()->AsArray()->size; i++) {
					AssetFileInfoEx* childInfo = assetManager->initalTable->getAssetInfo(contentArray->Get(i)->Get("component")->Get("m_PathID")->GetValue()->AsInt64());
					AssetTypeInstance* childAti = assetManager->GetATI(assetManager->file, childInfo);

					System::String^ name = "";
					if (childInfo->inheritedUnityClass == 0x72) {
						std::tuple<std::string, FILE*, AssetsFile*, AssetsFileTable*> dep = assetManager->dependencies->at(childAti->GetBaseField()->Get("m_Script")->Get("m_FileID")->GetValue()->AsInt() - 1);
						AssetFileInfoEx* info2 = std::get<3>(dep)->getAssetInfo(childAti->GetBaseField()->Get("m_Script")->Get("m_PathID")->GetValue()->AsInt64()); //todo make function
						AssetTypeInstance* scriptAti = assetManager->GetATI(std::get<1>(dep), info2);
						name = MarshalManager::StdToSys(scriptAti->GetBaseField()->Get("m_Name")->GetValue()->AsString());
					} else if (!childAti->GetBaseField()->Get("m_Name")->IsDummy()) {
						name = MarshalManager::StdToSys(childAti->GetBaseField()->Get("m_Name")->GetValue()->AsString());
					} else {
						name = "Unnammed asset";
					}
					name = MarshalManager::StdToSys(std::to_string((long double)childInfo->index)) + "|" + name;
					TreeNode^ childTn = tn->Nodes->Add(name);
					if (childInfo->curFileType == 1) {
						childTn->Nodes->Add("loading...");
					}
				}*/
			}
		}
private:System::Void searchStart_Click(System::Object^  sender, System::EventArgs^  e) {
			searchEncounter = 0;
			search(0);
		}
private:System::Void searchBackward_Click(System::Object^  sender, System::EventArgs^  e) {
			if (searchEncounter <= 0) {
				MessageBox::Show("You cannot go back further!");
			} else {
				searchEncounter--;
				search(searchEncounter);
			}
		}
private: System::Void searchForward_Click(System::Object^  sender, System::EventArgs^  e) {
			searchEncounter++;
			search(searchEncounter);
		}
private:System::Void search(int index) {
			int searchesLeft = index;
			for each (TreeNode^ n in fileTree->Nodes)
			{
				if (n->Text->ToLower()->Contains(searchBox->Text->ToLower())) {
					if (searchesLeft == 0) {
						fileTree->Focus();
						fileTree->SelectedNode = n;
						return;
					}
					searchesLeft--;
				}
			}
			MessageBox::Show("Could not find asset!");
			if (searchEncounter > 0) {
				searchEncounter--;
			}
		}
};
}

