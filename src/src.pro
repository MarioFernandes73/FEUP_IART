#-------------------------------------------------
#
# Project created by QtCreator 2017-05-07T13:53:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=\
        mainwindow.cpp \
    Algorithm.cpp \
    Auxiliary.cpp \
    Class.cpp \
    Database.cpp \
    Epoch.cpp \
    Exam.cpp \
    IART.cpp \
    Interaction.cpp \
    Menu.cpp \
    Schedule.cpp \
    Student.cpp \
    Subscription.cpp \
    University.cpp \
    sqlite3.c

HEADERS  += mainwindow.h \
    Algorithm.h \
    Auxiliary.h \
    Class.h \
    Database.h \
    Epoch.h \
    Exam.h \
    Interaction.h \
    Menu.h \
    MyExceptions.h \
    Schedule.h \
    sqlite3.h \
    Student.h \
    Subscription.h \
    University.h \
    Utils.h

FORMS    += mainwindow.ui
