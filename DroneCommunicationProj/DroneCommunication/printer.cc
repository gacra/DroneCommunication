// Includes class header
#include <printer.hh>

// Include to print on terminal
#include <iostream>
using namespace std;

Printer::Printer(SensorSet *sensorSet, QObject *parent) : QObject(parent) {
    _sensorSet = sensorSet;

    _timer.setTimerType(Qt::PreciseTimer);
    connect(&_timer, SIGNAL(timeout()), this, SLOT(printSensors()));
}

Printer::~Printer() {
    _timer.stop();
}

void Printer::startPrinting() {
    _timer.start(1000/10);  // 10 Hz
}

void Printer::printSensors() {
    cout << _sensorSet->toString().toStdString() << endl;
}
