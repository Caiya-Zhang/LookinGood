QT += core widgets
TARGET = LookinGood
TEMPLATE = app 
SOURCES += sources/main.cpp sources/mainwindow.cpp sources/detect.cpp sources/flip.cpp sources/rotate.cpp sources/filter.cpp sources/zoom.cpp sources/bright.cpp 
HEADERS += headers/mainwindow.h headers/detect.h headers/flip.h headers/rotate.h headers/filter.h headers/zoom.h headers/bright.h
LIBS += -lboost_thread -lpthread
CONFIG += link_pkgconfig
PKGCONFIG += opencv