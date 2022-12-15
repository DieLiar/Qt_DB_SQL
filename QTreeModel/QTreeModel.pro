#-------------------------------------------------
#
# Project created by QtCreator 2017-04-28T12:31:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTreeModel
TEMPLATE = app


SOURCES += main.cpp\
    qsqlite.cpp \
    treeitem.cpp \
    treemodel.cpp \
    widget.cpp

HEADERS  += \
    qsqlite.h \
    treeitem.h \
    treemodel.h \
    widget.h

FORMS    += widget.ui

RESOURCES +=

OTHER_FILES +=
