######################################################################
# Automatically generated by qmake (2.01a) Sun Mar 13 12:45:58 2011
######################################################################

TEMPLATE = app
TARGET = glQtApp
QT += core gui opengl
DEPENDPATH += . gui
INCLUDEPATH += . gui
LIBS += -lGLEW

# Input
HEADERS += gui/mainwindow.h gui/sketchglwidget.h
FORMS += gui/mainwindow.ui
SOURCES += main.cpp gui/mainwindow.cpp gui/sketchglwidget.cpp