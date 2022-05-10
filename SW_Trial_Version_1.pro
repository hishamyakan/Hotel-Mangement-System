QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addguestdetails.cpp \
    addroomreservation.cpp \
    checkout.cpp \
    main.cpp \
    loginscreen.cpp \
    receptionist.cpp \
    reservehall.cpp \
    reserveroom.cpp \
    reservevehicle.cpp \
    updatedeleteres.cpp

HEADERS += \
    addguestdetails.h \
    addroomreservation.h \
    checkout.h \
    loginscreen.h \
    receptionist.h \
    reservehall.h \
    reserveroom.h \
    reservevehicle.h \
    updatedeleteres.h

FORMS += \
    addguestdetails.ui \
    addroomreservation.ui \
    checkout.ui \
    loginscreen.ui \
    receptionist.ui \
    reservehall.ui \
    reserveroom.ui \
    reservevehicle.ui \
    updatedeleteres.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    LoginWindow.qrc
