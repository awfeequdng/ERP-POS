#-------------------------------------------------
#
# Project created by QtCreator 2015-03-05T16:25:54
#
#-------------------------------------------------

QT       += core gui sql printsupport axcontainer webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SupermarketPops
TEMPLATE = app

include(basedata/basedata.pri)
INCLUDEPATH += $$PWD/basedata

include(database/database.pri)
INCLUDEPATH += $$PWD/database

include(logicallayer/logicallayer.pri)
INCLUDEPATH += $$PWD/logicallayer

include(ui/ui.pri)
INCLUDEPATH += $$PWD/ui

include(main/main.pri)
INCLUDEPATH += $$PWD/main

RESOURCES += \
    res.qrc

win32:RC_FILE = SmartHome.rc
