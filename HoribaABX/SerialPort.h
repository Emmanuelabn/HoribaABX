#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#using <System.dll>
using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;


public ref class PortCommunication
{
private:
    static bool _continue;
    static SerialPort^ _serialPort;

public:
    // example to test all methods;
    static void Main();
    //read function
    static void Read();

    // set up the serialPort
    static String^ SetPortName(String^ defaultPortName);
    static Int32 SetPortBaudRate(Int32 defaultPortBaudRate);
    static Parity SetPortParity(Parity defaultPortParity);
    static Int32 SetPortDataBits(Int32 defaultPortDataBits);
    static StopBits SetPortStopBits(StopBits defaultPortStopBits);
    static Handshake SetPortHandshake(Handshake defaultPortHandshake);
};
