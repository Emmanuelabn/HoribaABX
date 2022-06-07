#include "SerialPort.h"

void PortCommunication::Main() {
    String^ DataReceiving;
    String^ message;
    Thread^ readThread = gcnew Thread(gcnew ThreadStart(PortCommunication::Read));

    // Create a new SerialPort object with default settings.
    _serialPort = gcnew SerialPort();

    // Allow the user to set the appropriate properties.
    _serialPort->PortName = SetPortName(_serialPort->PortName);
    _serialPort->BaudRate = SetPortBaudRate(_serialPort->BaudRate);
    _serialPort->Parity = SetPortParity(_serialPort->Parity);
    _serialPort->DataBits = SetPortDataBits(_serialPort->DataBits);
    _serialPort->StopBits = SetPortStopBits(_serialPort->StopBits);
    _serialPort->Handshake = SetPortHandshake(_serialPort->Handshake);

    // Set the read/write timeouts
    _serialPort->ReadTimeout = 5000;
    _serialPort->WriteTimeout = 5000;

    _serialPort->Open();
    _continue = true;
    readThread->Start();

    Console::Write("Data Receiving: ");
    DataReceiving = _serialPort->ReadLine();


    // read data from serial port
    message = Console::ReadLine();
    std::string msg = msclr::interop::marshal_as<std::string>(message);
    std::cout << "KKK" << msg << std::endl;
    std::string buffer;
    Console::WriteLine("Type QUIT to exit");
}

void PortCommunication::Read() {
    while (_continue)
    {
        try
        {
            String^ message = _serialPort->ReadLine();
            Console::WriteLine(message);
        }
        catch (TimeoutException^) {}
    }
}

String^ PortCommunication::SetPortName(String^ defaultPortName)
{
    String^ portName;

    Console::WriteLine("Available Ports:");
    for each (String ^ s in SerialPort::GetPortNames())
    {
        Console::WriteLine("   {0}", s);
    }

    Console::Write("COM port({0}): ", defaultPortName);
    portName = Console::ReadLine();

    if (portName == "")
    {
        portName = defaultPortName;
    }
    return portName;
}
Int32 PortCommunication::SetPortBaudRate(Int32 defaultPortBaudRate)
{
    String^ baudRate;

    Console::Write("Baud Rate({0}): ", defaultPortBaudRate);
    baudRate = Console::ReadLine();

    if (baudRate == "")
    {
        baudRate = defaultPortBaudRate.ToString();
    }

    return Int32::Parse(baudRate);
}
Parity PortCommunication::SetPortParity(Parity defaultPortParity)
{
    String^ parity;

    Console::WriteLine("Available Parity options:");
    for each (String ^ s in Enum::GetNames(Parity::typeid))
    {
        Console::WriteLine("   {0}", s);
    }

    Console::Write("Parity({0}):", defaultPortParity.ToString());
    parity = Console::ReadLine();

    if (parity == "")
    {
        parity = defaultPortParity.ToString();
    }

    return (Parity)Enum::Parse(Parity::typeid, parity);
}
Int32 PortCommunication::SetPortDataBits(Int32 defaultPortDataBits)
{
    String^ dataBits;

    Console::Write("Data Bits({0}): ", defaultPortDataBits);
    dataBits = Console::ReadLine();

    if (dataBits == "")
    {
        dataBits = defaultPortDataBits.ToString();
    }

    return Int32::Parse(dataBits);
}
StopBits PortCommunication::SetPortStopBits(StopBits defaultPortStopBits)
{
    String^ stopBits;

    Console::WriteLine("Available Stop Bits options:");
    for each (String ^ s in Enum::GetNames(StopBits::typeid))
    {
        Console::WriteLine("   {0}", s);
    }

    Console::Write("Stop Bits({0}):", defaultPortStopBits.ToString());
    stopBits = Console::ReadLine();

    if (stopBits == "")
    {
        stopBits = defaultPortStopBits.ToString();
    }

    return (StopBits)Enum::Parse(StopBits::typeid, stopBits);
}
Handshake PortCommunication::SetPortHandshake(Handshake defaultPortHandshake)
{
    String^ handshake;

    Console::WriteLine("Available Handshake options:");
    for each (String ^ s in Enum::GetNames(Handshake::typeid))
    {
        Console::WriteLine("   {0}", s);
    }

    Console::Write("Handshake({0}):", defaultPortHandshake.ToString());
    handshake = Console::ReadLine();

    if (handshake == "")
    {
        handshake = defaultPortHandshake.ToString();
    }

    return (Handshake)Enum::Parse(Handshake::typeid, handshake);
}