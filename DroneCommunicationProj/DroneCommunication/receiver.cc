// Includes class header
#include <receiver.hh>

// Include to print on terminal
#include <iostream>

// Include to use static method
#include <decoder.hh>

using namespace std;

Receiver::Receiver(SensorSet *sensorSet, QObject *parent) : QObject(parent) {
    _sensorSet = sensorSet;

    _socket = new QUdpSocket(this);
    _socket->bind(QHostAddress::LocalHost, 57301);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readRedy()));
    cout << "Listening on LocalHost, port 57301\n" << endl;
}

Receiver::~Receiver() {
    _socket->close();
    delete _socket;
}

void Receiver::readRedy() {
    QByteArray buffer;

    // In case messages are arriving faster than they can be processed,
    // accumulated messages are discarded and only the most current one is used
    while (_socket->hasPendingDatagrams()) {
        buffer.resize(_socket->pendingDatagramSize());

        // Informations that can be used for verification
        QHostAddress sender;
        quint16 senderPort;

        _socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    }

    // To be sure something was received
    if(buffer.size() > 0) {
        Decoder::decode(buffer, _sensorSet);
    }
}
