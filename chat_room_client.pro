QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accept_task.cpp \
    deal_task.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    MSG.pb.cc \
    msg.cpp

HEADERS += \
    accept_task.h \
    deal_task.h \
    dialog.h \
    mainwindow.h \
    MSG.pb.h \
    msg.h \
    queue_receive.h \
    queue_send.h


FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lprotobuf
