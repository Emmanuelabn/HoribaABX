#pragma once
#include "Packet.h"
#include <msclr\marshal_cppstd.h>

using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace MySql::Data::MySqlClient;

namespace HoribaABX {
	/// <summary>
	/// Summary for mainWindow
	/// </summary>
	public ref class mainWindow : public System::Windows::Forms::Form
	{
		String^ dataIn = "";
		public:
			mainWindow(void) {
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~mainWindow() {
				if (components) {
					delete components;
				}
			}

		private: System::Windows::Forms::GroupBox^ groupBox1;
		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::ComboBox^ cBoxBAUDRATE;
		private: System::Windows::Forms::ComboBox^ cBoxDATABITS;
		private: System::Windows::Forms::ComboBox^ cBoxSTOPBITS;
		private: System::Windows::Forms::ComboBox^ cBoxPARITYBITS;
		private: System::Windows::Forms::ComboBox^ cBoxCOMPORT;
		private: System::Windows::Forms::GroupBox^ groupBox2;
		private: System::Windows::Forms::ProgressBar^ progressBar1;
		private: System::IO::Ports::SerialPort^ serialPort;
		private: System::Windows::Forms::CheckBox^ chBoxRTSEnable;
		private: System::Windows::Forms::CheckBox^ chBoxDTREnable;
		private: System::Windows::Forms::Label^ lblCOMSts;
		private: System::Windows::Forms::MenuStrip^ menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^ serialPortControlToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ exportToDatabaseToolStripMenuItem;
		private: System::Windows::Forms::GroupBox^ groupBox3;
		private: System::Windows::Forms::TextBox^ tBoxDataIn;
		private: System::Windows::Forms::VScrollBar^ vScrollBar1;
		private: System::ComponentModel::IContainer^ components;
		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->chBoxRTSEnable = (gcnew System::Windows::Forms::CheckBox());
			this->chBoxDTREnable = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cBoxBAUDRATE = (gcnew System::Windows::Forms::ComboBox());
			this->cBoxDATABITS = (gcnew System::Windows::Forms::ComboBox());
			this->cBoxSTOPBITS = (gcnew System::Windows::Forms::ComboBox());
			this->cBoxPARITYBITS = (gcnew System::Windows::Forms::ComboBox());
			this->cBoxCOMPORT = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lblCOMSts = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToDatabaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->serialPortControlToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->tBoxDataIn = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chBoxRTSEnable);
			this->groupBox1->Controls->Add(this->chBoxDTREnable);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->cBoxBAUDRATE);
			this->groupBox1->Controls->Add(this->cBoxDATABITS);
			this->groupBox1->Controls->Add(this->cBoxSTOPBITS);
			this->groupBox1->Controls->Add(this->cBoxPARITYBITS);
			this->groupBox1->Controls->Add(this->cBoxCOMPORT);
			this->groupBox1->Location = System::Drawing::Point(12, 38);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(255, 249);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"COM Port Control";
			// 
			// chBoxRTSEnable
			// 
			this->chBoxRTSEnable->AutoSize = true;
			this->chBoxRTSEnable->Location = System::Drawing::Point(134, 219);
			this->chBoxRTSEnable->Name = L"chBoxRTSEnable";
			this->chBoxRTSEnable->Size = System::Drawing::Size(84, 17);
			this->chBoxRTSEnable->TabIndex = 11;
			this->chBoxRTSEnable->Text = L"RTS Enable";
			this->chBoxRTSEnable->UseVisualStyleBackColor = true;
			this->chBoxRTSEnable->CheckedChanged += gcnew System::EventHandler(this, &mainWindow::chBoxRTSEnable_CheckedChanged);
			// 
			// chBoxDTREnable
			// 
			this->chBoxDTREnable->AutoSize = true;
			this->chBoxDTREnable->Location = System::Drawing::Point(19, 219);
			this->chBoxDTREnable->Name = L"chBoxDTREnable";
			this->chBoxDTREnable->Size = System::Drawing::Size(85, 17);
			this->chBoxDTREnable->TabIndex = 10;
			this->chBoxDTREnable->Text = L"DTR Enable";
			this->chBoxDTREnable->UseVisualStyleBackColor = true;
			this->chBoxDTREnable->CheckedChanged += gcnew System::EventHandler(this, &mainWindow::chBoxDTREnable_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(16, 182);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"PARITY BITS";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 146);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"STOP BITS";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 109);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"DATA BITS";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"BAUD RATE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"COM PORT";
			// 
			// cBoxBAUDRATE
			// 
			this->cBoxBAUDRATE->FormattingEnabled = true;
			this->cBoxBAUDRATE->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2400", L"4800", L"9600" });
			this->cBoxBAUDRATE->Location = System::Drawing::Point(97, 69);
			this->cBoxBAUDRATE->Name = L"cBoxBAUDRATE";
			this->cBoxBAUDRATE->Size = System::Drawing::Size(121, 21);
			this->cBoxBAUDRATE->TabIndex = 4;
			this->cBoxBAUDRATE->Text = L"9600";
			// 
			// cBoxDATABITS
			// 
			this->cBoxDATABITS->FormattingEnabled = true;
			this->cBoxDATABITS->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"6", L"7", L"8" });
			this->cBoxDATABITS->Location = System::Drawing::Point(97, 106);
			this->cBoxDATABITS->Name = L"cBoxDATABITS";
			this->cBoxDATABITS->Size = System::Drawing::Size(121, 21);
			this->cBoxDATABITS->TabIndex = 3;
			this->cBoxDATABITS->Text = L"8";
			// 
			// cBoxSTOPBITS
			// 
			this->cBoxSTOPBITS->FormattingEnabled = true;
			this->cBoxSTOPBITS->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"One", L"Two" });
			this->cBoxSTOPBITS->Location = System::Drawing::Point(97, 143);
			this->cBoxSTOPBITS->Name = L"cBoxSTOPBITS";
			this->cBoxSTOPBITS->Size = System::Drawing::Size(121, 21);
			this->cBoxSTOPBITS->TabIndex = 2;
			this->cBoxSTOPBITS->Text = L"One";
			// 
			// cBoxPARITYBITS
			// 
			this->cBoxPARITYBITS->FormattingEnabled = true;
			this->cBoxPARITYBITS->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Odd", L"Even" });
			this->cBoxPARITYBITS->Location = System::Drawing::Point(97, 179);
			this->cBoxPARITYBITS->Name = L"cBoxPARITYBITS";
			this->cBoxPARITYBITS->Size = System::Drawing::Size(121, 21);
			this->cBoxPARITYBITS->TabIndex = 1;
			this->cBoxPARITYBITS->Text = L"None";
			// 
			// cBoxCOMPORT
			// 
			this->cBoxCOMPORT->Cursor = System::Windows::Forms::Cursors::SizeNS;
			this->cBoxCOMPORT->FormattingEnabled = true;
			this->cBoxCOMPORT->Location = System::Drawing::Point(97, 32);
			this->cBoxCOMPORT->Name = L"cBoxCOMPORT";
			this->cBoxCOMPORT->Size = System::Drawing::Size(121, 21);
			this->cBoxCOMPORT->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->lblCOMSts);
			this->groupBox2->Controls->Add(this->progressBar1);
			this->groupBox2->Location = System::Drawing::Point(12, 297);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(255, 64);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"COM Port Status";
			// 
			// lblCOMSts
			// 
			this->lblCOMSts->AutoSize = true;
			this->lblCOMSts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCOMSts->Location = System::Drawing::Point(93, 16);
			this->lblCOMSts->Name = L"lblCOMSts";
			this->lblCOMSts->Size = System::Drawing::Size(49, 24);
			this->lblCOMSts->TabIndex = 0;
			this->lblCOMSts->Text = L"OFF";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(6, 43);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(243, 12);
			this->progressBar1->TabIndex = 2;
			// 
			// serialPort
			// 
			this->serialPort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &mainWindow::serialPort_DataReceived);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->serialPortControlToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(807, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exportToDatabaseToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exportToDatabaseToolStripMenuItem
			// 
			this->exportToDatabaseToolStripMenuItem->Name = L"exportToDatabaseToolStripMenuItem";
			this->exportToDatabaseToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exportToDatabaseToolStripMenuItem->Text = L"Export to Database";
			// 
			// serialPortControlToolStripMenuItem
			// 
			this->serialPortControlToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->closeToolStripMenuItem
			});
			this->serialPortControlToolStripMenuItem->Name = L"serialPortControlToolStripMenuItem";
			this->serialPortControlToolStripMenuItem->Size = System::Drawing::Size(115, 20);
			this->serialPortControlToolStripMenuItem->Text = L"COM Port Control";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->openToolStripMenuItem->Text = L"Open Port";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainWindow::openToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->closeToolStripMenuItem->Text = L"Close Port";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainWindow::closeToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainWindow::exitToolStripMenuItem_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->vScrollBar1);
			this->groupBox3->Controls->Add(this->tBoxDataIn);
			this->groupBox3->Location = System::Drawing::Point(291, 38);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(504, 323);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Raw Data";
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(487, 30);
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(17, 80);
			this->vScrollBar1->TabIndex = 1;
			// 
			// tBoxDataIn
			// 
			this->tBoxDataIn->Location = System::Drawing::Point(0, 19);
			this->tBoxDataIn->Multiline = true;
			this->tBoxDataIn->Name = L"tBoxDataIn";
			this->tBoxDataIn->ReadOnly = true;
			this->tBoxDataIn->Size = System::Drawing::Size(504, 92);
			this->tBoxDataIn->TabIndex = 0;
			// 
			// mainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(807, 376);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(823, 415);
			this->MinimumSize = System::Drawing::Size(823, 415);
			this->Name = L"mainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Horiba ABX";
			this->Load += gcnew System::EventHandler(this, &mainWindow::mainWindow_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region MyRegion
		MySqlConnection dbConnection;
		MySqlCommand query;
#pragma endregion

		public: bool isReceived = false;
		// Refactoring snippets
		private: System::Void connectComPort();
		private: System::Void disconnectComPort();
		private: System::Void sendAck(bool);

		// Actions to be taken on loading
		private: System::Void mainWindow_Load(System::Object^ sender, System::EventArgs^ e);

		// Check boxes to enable/disable DTR and RTS.
		private: System::Void chBoxDTREnable_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void chBoxRTSEnable_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

		// Serial Port Reception Event
		private: System::Void serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e);
		private: System::Void displayData(System::Object^ sender, System::EventArgs^ e);

		// Menu Strip Events
		private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	};
}