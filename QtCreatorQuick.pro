QT       += core gui core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    futext.cpp \
    imagedragdrop.cpp \
    main.cpp \
    mainwindow.cpp \
    myclass.cpp \
    mydialog.cpp \
    mydragdrop.cpp \
    myevent.cpp \
    myeventfilter.cpp \
    mykeyevent.cpp \
    mylineedit.cpp \
    mymouseevent.cpp \
    myproperty.cpp \
    mysignalslot.cpp \
    mysignalslot2.cpp \
    mysyntaxhighlighter.cpp \
    mytimerevent.cpp

HEADERS += \
    futext.h \
    imagedragdrop.h \
    mainwindow.h \
    myclass.h \
    mydialog.h \
    mydragdrop.h \
    myevent.h \
    myeventfilter.h \
    mykeyevent.h \
    mylineedit.h \
    mymouseevent.h \
    myproperty.h \
    mysignalslot.h \
    mysignalslot2.h \
    mysyntaxhighlighter.h \
    mytimerevent.h

FORMS += \
    futext.ui \
    imagedragdrop.ui \
    mainwindow.ui \
    mydialog.ui \
    mydragdrop.ui \
    myevent.ui \
    myeventfilter.ui \
    mykeyevent.ui \
    mymouseevent.ui \
    myproperty.ui \
    mysignalslot.ui \
    mysignalslot2.ui \
    mytimerevent.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myimages.qrc
