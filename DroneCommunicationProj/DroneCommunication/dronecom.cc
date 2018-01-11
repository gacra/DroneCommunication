// Includes class header
#include <dronecom.hh>

DroneCom::DroneCom() {
    // Creates the SensorSet object
    _sensorSet = new SensorSet();

    // Creates the Printer object
    _printer = new Printer(_sensorSet);

    // Creates a Thread and moves the printer to it
    _printerThread = new QThread();
    _printer->moveToThread(_printerThread);
    _printerThread->start();

    // Starts printing
    _printer->startPrinting();

    // Creates the Receiver object
    _receiver = new Receiver(_sensorSet);

    // Creates a Thread and moves the receiver to it
    _receiverThread = new QThread();
    _receiver->moveToThread(_receiverThread);
    _receiverThread->start();
}

DroneCom::~DroneCom() {
    _printerThread->quit();
    _receiverThread->quit();
    _printerThread->wait();
    _receiverThread->wait();

    delete _printerThread;
    delete _receiverThread;

    delete _sensorSet;
    delete _printer;
    delete _receiver;
}
