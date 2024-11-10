QT       += core gui core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QtCreatorQuickStart/futext.cpp \
    QtCreatorQuickStart/imagedragdrop.cpp \
    QtCreatorQuickStart/mainwindow.cpp \
    QtCreatorQuickStart/mybutton.cpp \
    QtCreatorQuickStart/myclass.cpp \
    QtCreatorQuickStart/mycontainers.cpp \
    QtCreatorQuickStart/mydialog.cpp \
    QtCreatorQuickStart/mydragdrop.cpp \
    QtCreatorQuickStart/myevent.cpp \
    QtCreatorQuickStart/myeventfilter.cpp \
    QtCreatorQuickStart/myfile.cpp \
    QtCreatorQuickStart/mykeyevent.cpp \
    QtCreatorQuickStart/mylineedit.cpp \
    QtCreatorQuickStart/mymouseevent.cpp \
    QtCreatorQuickStart/myownership.cpp \
    QtCreatorQuickStart/myproperty.cpp \
    QtCreatorQuickStart/myre.cpp \
    QtCreatorQuickStart/mysignalslot.cpp \
    QtCreatorQuickStart/mysignalslot2.cpp \
    QtCreatorQuickStart/mystring.cpp \
    QtCreatorQuickStart/mysyntaxhighlighter.cpp \
    QtCreatorQuickStart/mytimerevent.cpp \
    QtCreatorQuickStart/myvariant.cpp \
    Spider/spiderwidget.cpp \
    main.cpp \


HEADERS += \
    QtCreatorQuickStart/futext.h \
    QtCreatorQuickStart/imagedragdrop.h \
    QtCreatorQuickStart/mainwindow.h \
    QtCreatorQuickStart/mybutton.h \
    QtCreatorQuickStart/myclass.h \
    QtCreatorQuickStart/mycontainers.h \
    QtCreatorQuickStart/mydialog.h \
    QtCreatorQuickStart/mydragdrop.h \
    QtCreatorQuickStart/myevent.h \
    QtCreatorQuickStart/myeventfilter.h \
    QtCreatorQuickStart/myfile.h \
    QtCreatorQuickStart/mykeyevent.h \
    QtCreatorQuickStart/mylineedit.h \
    QtCreatorQuickStart/mymouseevent.h \
    QtCreatorQuickStart/myownership.h \
    QtCreatorQuickStart/myproperty.h \
    QtCreatorQuickStart/myre.h \
    QtCreatorQuickStart/mysignalslot.h \
    QtCreatorQuickStart/mysignalslot2.h \
    QtCreatorQuickStart/mystring.h \
    QtCreatorQuickStart/mysyntaxhighlighter.h \
    QtCreatorQuickStart/mytimerevent.h \
    QtCreatorQuickStart/myvariant.h \
    Spider/spiderwidget.h \


FORMS += \
    QtCreatorQuickStart/futext.ui \
    QtCreatorQuickStart/imagedragdrop.ui \
    QtCreatorQuickStart/mainwindow.ui \
    QtCreatorQuickStart/mydialog.ui \
    QtCreatorQuickStart/mydragdrop.ui \
    QtCreatorQuickStart/myevent.ui \
    QtCreatorQuickStart/myeventfilter.ui \
    QtCreatorQuickStart/mykeyevent.ui \
    QtCreatorQuickStart/mymouseevent.ui \
    QtCreatorQuickStart/myownership.ui \
    QtCreatorQuickStart/myproperty.ui \
    QtCreatorQuickStart/mysignalslot.ui \
    QtCreatorQuickStart/mysignalslot2.ui \
    QtCreatorQuickStart/mytimerevent.ui \
    Spider/spiderwidget.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    QtCreatorQuickStart/myimages.qrc \
    myimages.qrc

DISTFILES += \
    README.md
