QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminacceptedcomplaints.cpp \
    adminallcomplaints.cpp \
    admindialog.cpp \
    adminloginwindow.cpp \
    adminregisterdialog.cpp \
    complaint.cpp \
    filecomp.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    adminacceptedcomplaints.h \
    adminallcomplaints.h \
    admindialog.h \
    adminloginwindow.h \
    adminregisterdialog.h \
    complaint.h \
    filecomp.h \
    mainwindow.h

FORMS += \
    adminacceptedcomplaints.ui \
    adminallcomplaints.ui \
    admindialog.ui \
    adminloginwindow.ui \
    adminregisterdialog.ui \
    filecomp.ui \
    mainwindow.ui

TRANSLATIONS += \
    ComplaintManagement_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
