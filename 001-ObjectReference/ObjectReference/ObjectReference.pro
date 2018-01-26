QT += core
QT -= gui

CONFIG += c++11

TARGET = ObjectReference
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    time.cpp

HEADERS += \
    time.h
