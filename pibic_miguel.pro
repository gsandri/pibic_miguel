TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        ../dtw-1/src/dtw.cpp

HEADERS += \
        ../dtw-1/include/dtw/dtw.h

INCLUDEPATH += ../dtw-1/include/
