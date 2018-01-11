/**
  * Test application for simulation of sending UDP messages by drone.
  *
  * Author: Guilherme Jose Acra
  *
**/

// Include Qt libraries
#include <QCoreApplication>
#include <QThread>
#include <QtGlobal>

// Include to print on terminal
#include <iostream>

// Includes Sender class
#include <sender.hh>

using namespace std;

int main(void) {

    // Creates a sender object
    Sender sender;

    // Sends test messages to the DroneCommunication application
    // with variable frequency and variable number of sensors

    cout << "Sending messages..." << endl;

    for(int i=0; i < 1000; i++) {
        QString msg = "$";
        msg += "A" + QString::number((float) i/10);
        msg += "B" + QString::number((float) i);
        if(i%3 == 0) {
            msg += "C" + QString::number((float) i*2);
            msg += "D" + QString::number((float) i*2.5);
        }
        sender.sendMessage(msg);

        int randomTime = (qrand() % 50) + 50;

        QThread::msleep(randomTime);
    }

    cout << "Messages sent." << endl;
}
