// Includes class header
#include <sender.hh>

Sender::Sender(QObject *parent) : QObject(parent) {
    _socket = new QUdpSocket(this);
}

void Sender::sendMessage(QString str) {
    QByteArray data;
    data.append(str);
    _socket->writeDatagram(data, QHostAddress::LocalHost, 57301);
}
