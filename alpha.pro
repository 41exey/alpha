#-------------------------------------------------
#
# Project created by QtCreator 2013-09-17T10:32:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alpha
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += QCustomPlot

SOURCES += main.cpp\
        mainwindow.cpp \
        QCustomPlot/qcustomplot.cpp \
    Alpha.cpp

HEADERS  += mainwindow.h \
        QCustomPlot/qcustomplot.h \
    Alpha.h

FORMS    += mainwindow.ui
