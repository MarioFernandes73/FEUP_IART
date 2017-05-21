#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T15:52:09
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
    Schedule.cpp \
    Student.cpp \
    Subscription.cpp \
    University.cpp \
    sqlite3.c \
    mainmenu.cpp \
    dialogcreatestudent.cpp \
    dialogliststudents.cpp \
    dialogcreatecourse.cpp \
    dialoglistcourses.cpp \
    dialoglistenrollments.cpp \
    dialogcurrentschedule.cpp \
    dialogeditexams.cpp \
    dialoggenerateschedule.cpp \
    dialogliststatistics.cpp \
    Statistics.cpp \
    SimulatedAnnealing.cpp \
    Genetic.cpp


HEADERS  += mainwindow.h \
    Algorithm.h \
    Auxiliary.h \
    Class.h \
    Database.h \
    Epoch.h \
    Exam.h \
    MyExceptions.h \
    Schedule.h \
    sqlite3.h \
    Student.h \
    Subscription.h \
    University.h \
    Utils.h \
    mainmenu.h \
    dialogcreatestudent.h \
    dialogliststudents.h \
    dialogcreatecourse.h \
    dialoglistcourses.h \
    dialoglistenrollments.h \
    dialogcurrentschedule.h \
    dialogeditexams.h \
    dialoggenerateschedule.h \
    dialogliststatistics.h \
    Statistics.h \
    SimulatedAnnealing.h \
    Genetic.h

FORMS    += mainwindow.ui \
    mainmenu.ui \
    dialogcreatestudent.ui \
    dialogliststudents.ui \
    dialogcreatecourse.ui \
    dialoglistcourses.ui \
    dialoglistenrollments.ui \
    dialogcurrentschedule.ui \
    dialogeditexams.ui \
    dialoggenerateschedule.ui \
    dialogliststatistics.ui
