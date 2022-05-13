QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addguestdetails.cpp \
    addroomreservation.cpp \
    checkavailableroom.cpp \
    checkout.cpp \
    editroomstatus.cpp \
    hr.cpp \
    main.cpp \
    loginscreen.cpp \
    manger.cpp \
    receptionist.cpp \
    reservehall.cpp \
    reserveroom.cpp \
    reservetable.cpp \
    reservevehicle.cpp \
    updatedeleteres.cpp

HEADERS += \
    addguestdetails.h \
    addroomreservation.h \
    checkavailableroom.h \
    checkout.h \
    editroomstatus.h \
    hr.h \
    loginscreen.h \
    manger.h \
    receptionist.h \
    reservehall.h \
    reserveroom.h \
    reservetable.h \
    reservevehicle.h \
    updatedeleteres.h

FORMS += \
    addguestdetails.ui \
    addroomreservation.ui \
    checkavailableroom.ui \
    checkout.ui \
    editroomstatus.ui \
    hr.ui \
    loginscreen.ui \
    manger.ui \
    receptionist.ui \
    reservehall.ui \
    reserveroom.ui \
    reservetable.ui \
    reservevehicle.ui \
    updatedeleteres.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    LoginWindow.qrc
