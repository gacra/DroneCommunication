QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = DroneCommunication
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH *= include

SOURCES += \
    main.cc \
    receiver.cc \
    decoder.cc \
    sensorset.cc \
    printer.cc \
    dronecom.cc

HEADERS += \
    receiver.hh \
    decoder.hh \
    sensorset.hh \
    printer.hh \
    dronecom.hh
