
include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_etst.h

SOURCES +=     main.cpp
