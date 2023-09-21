#-------------------------------------------------
#
# Project created by QtCreator 2023-04-01T21:49:49
#
#-------------------------------------------------

QT       += core gui
QT +=sql
Qt+=axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homeword
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    loginwidget.cpp \
    get_grade.cpp \
    student.cpp \
    selectcourse.cpp \
    teacher.cpp \
    manager.cpp \
    coursestart.cpp \
    stucon.cpp \
    studig.cpp \
    teccon.cpp


HEADERS += \
        mainwindow.h \
    loginwidget.h \
    get_grade.h \
    student.h \
    selectcourse.h \
    teacher.h \
    manager.h \
    coursestart.h \
    stucon.h \
    studig.h \
    teccon.h

FORMS += \
        mainwindow.ui \
       loginwidget.ui \
    get_grade.ui \
    student.ui \
    selectcourse.ui \
    teacher.ui \
    mypushbtm.ui \
    manager.ui \
    coursestart.ui \
    stucon.ui \
    studig.ui \
    teccon.ui

RESOURCES += \
    resfile.qrc
