#-------------------------------------------------
#
# Project created by QtCreator 2013-09-07T18:32:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alpha
TEMPLATE = app

INCLUDEPATH += QCustomPlot

SOURCES += main.cpp\
        mainwindow.cpp \
        QCustomPlot/qcustomplot.cpp

HEADERS  += mainwindow.h \
        QCustomPlot/qcustomplot.h

FORMS    += mainwindow.ui
