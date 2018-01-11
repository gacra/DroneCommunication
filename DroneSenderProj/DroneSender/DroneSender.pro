QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = DroneSender
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH *= include

SOURCES += \
    sender.cc \
    main.cc

HEADERS += \
    sender.hh
