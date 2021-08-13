#version 1.0
#version 1.1

QT       += core gui multimedia multimediawidgets winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_NO_DEBUG_OUTPUT
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    playlistwidget/playlistwidget.cpp \
    setting/setting.cpp \
    traymenu/traymenu.cpp

HEADERS += \
    mainwindow.h \
    playlistwidget/playlistwidget.h \
    setting/setting.h \
    traymenu/traymenu.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
RC_ICONS = bit.ico
#INCLUDEPATH +=D:/lib/opencv0/build/include
#LIBS += D:/lib/opencv420/build/x64/mingw/lib/libopencv_world420.dll.a
#INCLUDEPATH +=D:/lib/opencv420/build/include
#LIBS += D:/lib/opencv420/sources/build/install/x86/mingw/lib/libopencv_world420.dll.a

android {
    TEMPLATE = app  # for Android this is an "app"
}

#DESTDIR = $$PWD/bin
#UI_DIR =$$PWD/ui
#OBJECTS_DIR = $$PWD/object



