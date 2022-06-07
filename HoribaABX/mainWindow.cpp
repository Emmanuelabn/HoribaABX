#include "mainWindow.h"

System::Void HoribaABX::mainWindow::sendAck(bool b) {
	// 6(ACK) - 21(NAK) Other values just for testing on visible characters
	Char tmp = b ? 't' : 'f';
	String^ toSend;
	toSend += tmp;
	this->serialPort->Write(toSend);
	return;
}
System::Void HoribaABX::mainWindow::disconnectComPort()
{
	try {
		this->serialPort->Close();
		progressBar1->Value = 0;
		this->lblCOMSts->Text = "OFF";
		this->openToolStripMenuItem->Enabled = true;
		this->closeToolStripMenuItem->Enabled = false;
		this->lblCOMSts->Text = "OFF";
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->openToolStripMenuItem->Enabled = false;
		this->closeToolStripMenuItem->Enabled = true;
	}
	return System::Void();
}
System::Void HoribaABX::mainWindow::connectComPort() {
	try {
		this->serialPort->PortName = this->cBoxCOMPORT->Text;
		this->serialPort->BaudRate = Int32::Parse(this->cBoxBAUDRATE->Text);
		this->serialPort->DataBits = Int32::Parse(this->cBoxDATABITS->Text);
		this->serialPort->StopBits = (StopBits)Enum::Parse(StopBits::typeid, this->cBoxSTOPBITS->Text);
		this->serialPort->Parity = (Parity)Enum::Parse(Parity::typeid, this->cBoxPARITYBITS->Text);

		this->serialPort->Open();
		this->progressBar1->Value = 100;
		this->lblCOMSts->Text = "ON";
		this->openToolStripMenuItem->Enabled = false;
		this->closeToolStripMenuItem->Enabled = true;
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->openToolStripMenuItem->Enabled = true;
		this->closeToolStripMenuItem->Enabled = false;
	}
}


System::Void HoribaABX::mainWindow::mainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	cli::array<System::String^, 1>^ ports = SerialPort::GetPortNames();
	this->cBoxCOMPORT->Items->AddRange(ports);
	this->chBoxDTREnable->Checked = false;
	this->serialPort->DtrEnable = false;
	this->chBoxRTSEnable->Checked = false;
	this->serialPort->RtsEnable = false;
	this->openToolStripMenuItem->Enabled = true;
	this->closeToolStripMenuItem->Enabled = false;
}

System::Void HoribaABX::mainWindow::chBoxDTREnable_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->chBoxDTREnable->Checked) this->serialPort->DtrEnable = true;
	else this->serialPort->DtrEnable = false;
}
System::Void HoribaABX::mainWindow::chBoxRTSEnable_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->chBoxRTSEnable->Checked) this->serialPort->RtsEnable = true;
	else this->serialPort->RtsEnable = false;
}

System::Void HoribaABX::mainWindow::serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
	try {
		this->dataIn = this->serialPort->ReadExisting(); // save the received in a global var
		msclr::interop::marshal_context context;
		std::string message = context.marshal_as<std::string>(this->dataIn); // System::String^ ---> std::string
		this->Invoke(gcnew EventHandler(this, &mainWindow::displayData));
		// display received data (dataIN) --TODO-- Remove
		Console::WriteLine(this->dataIn);
		Packet p(message);
		// p.display();
		if (p.isCorrupt()) {
			isReceived = false;
			this->sendAck(false);
		}
		else {
			isReceived = true;
			this->sendAck(true);
		}
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void HoribaABX::mainWindow::displayData(System::Object^ sender, System::EventArgs^ e) {
	try {
		this->tBoxDataIn->Text += dataIn + "\n";
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void HoribaABX::mainWindow::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->connectComPort();
	return System::Void();
}
System::Void HoribaABX::mainWindow::closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->disconnectComPort();
	return System::Void();
}
System::Void HoribaABX::mainWindow::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	exit(0);
	return System::Void();
}
