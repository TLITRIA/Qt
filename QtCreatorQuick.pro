QT       += core gui core5compat network

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
    QtCreatorQuickStart/mycomposition.cpp \
    QtCreatorQuickStart/mycontainers.cpp \
    QtCreatorQuickStart/mydialog.cpp \
    QtCreatorQuickStart/mydoublebuffers.cpp \
    QtCreatorQuickStart/mydragdrop.cpp \
    QtCreatorQuickStart/mydraw2.cpp \
    QtCreatorQuickStart/mydrawing.cpp \
    QtCreatorQuickStart/mydrawing3.cpp \
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
    QtCreatorQuickStart/mytransformation.cpp \
    QtCreatorQuickStart/myvariant.cpp \
    QtCreatorQuickStart/mywebengine.cpp \
    Spider/spider.cpp \
    Spider/spiderwidget.cpp \
    main.cpp \


HEADERS += \
    QtCreatorQuickStart/futext.h \
    QtCreatorQuickStart/imagedragdrop.h \
    QtCreatorQuickStart/mainwindow.h \
    QtCreatorQuickStart/mybutton.h \
    QtCreatorQuickStart/myclass.h \
    QtCreatorQuickStart/mycomposition.h \
    QtCreatorQuickStart/mycontainers.h \
    QtCreatorQuickStart/mydialog.h \
    QtCreatorQuickStart/mydoublebuffers.h \
    QtCreatorQuickStart/mydragdrop.h \
    QtCreatorQuickStart/mydraw2.h \
    QtCreatorQuickStart/mydrawing.h \
    QtCreatorQuickStart/mydrawing3.h \
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
    QtCreatorQuickStart/mytransformation.h \
    QtCreatorQuickStart/myvariant.h \
    QtCreatorQuickStart/mywebengine.h \
    Spider/spider.h \
    Spider/spiderwidget.h \


FORMS += \
    QtCreatorQuickStart/futext.ui \
    QtCreatorQuickStart/imagedragdrop.ui \
    QtCreatorQuickStart/mainwindow.ui \
    QtCreatorQuickStart/mycomposition.ui \
    QtCreatorQuickStart/mydialog.ui \
    QtCreatorQuickStart/mydoublebuffers.ui \
    QtCreatorQuickStart/mydragdrop.ui \
    QtCreatorQuickStart/mydraw2.ui \
    QtCreatorQuickStart/mydrawing.ui \
    QtCreatorQuickStart/mydrawing3.ui \
    QtCreatorQuickStart/myevent.ui \
    QtCreatorQuickStart/myeventfilter.ui \
    QtCreatorQuickStart/mykeyevent.ui \
    QtCreatorQuickStart/mymouseevent.ui \
    QtCreatorQuickStart/myownership.ui \
    QtCreatorQuickStart/myproperty.ui \
    QtCreatorQuickStart/mysignalslot.ui \
    QtCreatorQuickStart/mysignalslot2.ui \
    QtCreatorQuickStart/mytimerevent.ui \
    QtCreatorQuickStart/mytransformation.ui \
    QtCreatorQuickStart/mywebengine.ui \
    Spider/spiderwidget.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    QtCreatorQuickStart/myimages.qrc \
    myimages.qrc

DISTFILES += \
    .gitignore \
    README.md
