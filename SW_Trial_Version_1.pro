QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$PWD/View/Receptionist/addguestdetails.cpp \
    $$PWD/View/Receptionist/addroomreservation.cpp \
    $$PWD/View/Receptionist/checkavailableroom.cpp \
    $$PWD/View/Receptionist/checkout.cpp \
    $$PWD/View/MaintenanceOrHouseKeeping/editroomstatus.cpp \
    $$PWD/View/HR/hr.cpp \
    Control/Date.cpp \
    Control/employee.cpp \
    Control/employee_manager.cpp \
    Control/guest.cpp \
    Control/hr_member.cpp \
    Control/person.cpp \
    Control/reservable.cpp \
    Control/reservation.cpp \
    Model/employee_PBCfg.cpp \
    main.cpp \
    $$PWD/View/loginscreen.cpp \
    $$PWD/View/Manger/manger.cpp \
    $$PWD/View/Receptionist/receptionist.cpp \
    $$PWD/View/Receptionist/reservehall.cpp \
    $$PWD/View/Receptionist/reserveroom.cpp \
    $$PWD/View/Receptionist/reservetable.cpp \
    $$PWD/View/Receptionist/reservevehicle.cpp \
    $$PWD/View/Receptionist/updatedeleteres.cpp

HEADERS += \
    $$PWD/View/Receptionist/addguestdetails.h \
    $$PWD/View/Receptionist/addroomreservation.h \
    $$PWD/View/Receptionist/checkavailableroom.h \
    $$PWD/View/Receptionist/checkout.h \
    $$PWD/View/MaintenanceOrHouseKeeping/editroomstatus.h \
    $$PWD/View/HR/hr.h \
    $$PWD/View/loginscreen.h \
    $$PWD/View/Manger/manger.h \
    $$PWD/View/Receptionist/receptionist.h \
    $$PWD/View/Receptionist/reservehall.h \
    $$PWD/View/Receptionist/reserveroom.h \
    $$PWD/View/Receptionist/reservetable.h \
    $$PWD/View/Receptionist/reservevehicle.h \
    $$PWD/View/Receptionist/updatedeleteres.h \
    Control/Date.h \
    Control/employee.h \
    Control/employee_manager.h \
    Control/guest.h \
    Control/hotelSystem.h \
    Control/hotel_types.h \
    Control/hr_member.h \
    Control/person.h \
    Control/reservable.h \
    Control/reservation.h

FORMS += \
    $$PWD/View/Receptionist/addguestdetails.ui \
    $$PWD/View/Receptionist/addroomreservation.ui \
    $$PWD/View/Receptionist/checkavailableroom.ui \
    $$PWD/View/Receptionist/checkout.ui \
    $$PWD/View/MaintenanceOrHouseKeeping/editroomstatus.ui \
    $$PWD/View/HR/hr.ui \
    $$PWD/View/loginscreen.ui \
    $$PWD/View/Manger/manger.ui \
    $$PWD/View/Receptionist/receptionist.ui \
    $$PWD/View/Receptionist/reservehall.ui \
    $$PWD/View/Receptionist/reserveroom.ui \
    $$PWD/View/Receptionist/reservetable.ui \
    $$PWD/View/Receptionist/reservevehicle.ui \
    $$PWD/View/Receptionist/updatedeleteres.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    LoginWindow.qrc
