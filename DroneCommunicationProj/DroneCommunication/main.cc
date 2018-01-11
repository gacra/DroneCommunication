/**
  * Application for communication with a drone using udp socket.
  *
  * Author: Guilherme Jose Acra
  *
**/

// Includes Qt library
#include <QCoreApplication>

// Includes DroneCommunication class
#include <dronecom.hh>

int main(int argc, char *argv[]) {
    // Creates the Qt application
    QCoreApplication a(argc, argv);

    // Creates and starts DroneCommunication
    DroneCom *droneCom = new DroneCom();

    // Starts the application
    int error = a.exec();

    // Deletes DroneCommunication at the end of the application
    delete droneCom;

    // Returns the application error code
    return error;
}
