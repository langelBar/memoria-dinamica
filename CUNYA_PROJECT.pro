TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    estructuras.cpp \
    basicas.cpp

include(deployment.pri)
qtcAddDeployment()

