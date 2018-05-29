;#-------------------------------------------------
#
# Project created by QtCreator 2016-07-07T15:36:17
#
#-------------------------------------------------

QT+= core gui
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Swidget
TEMPLATE = app


SOURCES += main.cpp\
        swidget.cpp \
    oracledao.cpp \
    table.cpp \
    storethread.cpp \
    serversocket.cpp \
    server.cpp \
    logthread.cpp \
    logqueue.cpp \
    logdao.cpp \
    filedao.cpp \
    clientthread.cpp \
    q_thread.cpp

HEADERS  += swidget.h \
    data.h \
    oracledao.h \
    table.h \
    storethread.h \
    serversocket.h \
    server.h \
    logthread.h \
    logqueue.h \
    logdao.h \
    filedao.h \
    clientthread.h \
    except.h \
    q_thread.h

FORMS    += swidget.ui \
    table.ui

OTHER_FILES += \
    table.o \
    Swidget.pro.user \
    Swidget \
    swidget.o \
    oracledao.o \
    moc_table.o \
    moc_swidget.o \
    Makefile \
    main.o \
    filedao.txt
