# DroneCommunication
Application for communication with a drone using udp socket. Made using C++ and Qt.

Author: Guilherme José Acra

## Dependencies:

The software uses the Qt5 (v5.6.2) framework libraries. It can be found in the link: http://bit.ly/2BnnI10

## Compilation and run:

In the "/DroneCommunicationProj/DroneCommunication" folder, generate the MakeFile:

$ qmake

Run the MakeFile:

$ make

Run the application:

$ ./DroneCommunication

To quit the application use 'Ctrl + C'.

Alternatively, you can compile the project through the QtCreator IDE.

## Application for tests:

In the "/DroneSenderProj" folder there is a test application that simulates the drone sending messages. It can be compiled and run in the same way as the main application.

## Development environment:

The application was developed in Linux (Fedora 24).