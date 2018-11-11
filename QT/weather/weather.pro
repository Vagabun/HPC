QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += sdk_no_version_check

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    data_requester.cpp \
    json_parser.cpp \
    output_handler.cpp

HEADERS += \
    data_requester.h \
    header.h \
    json_parser.h \
    weather_info.h \
    output_handler.h
