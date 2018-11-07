QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += sdk_no_version_check

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    data_requester.cpp

HEADERS += \
    data_requester.h
