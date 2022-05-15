QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Control/maintenance.cpp \
    Control/receptionist_member.cpp \
    Control/reservable_manager.cpp \
    Model/reservable_PBCfg.cpp \
    Model/reservation_PBCfg.cpp \
    View/Receptionist/addguestdetails.cpp \
    View/Receptionist/addroomreservation.cpp \
    View/Receptionist/checkavailableroom.cpp \
    View/Receptionist/checkout.cpp \
    View/MaintenanceOrHouseKeeping/editroomstatus.cpp \
    View/HR/hr.cpp \
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
    View/loginscreen.cpp \
    View/Manger/manger.cpp \
    View/Receptionist/receptionist.cpp \
    View/Receptionist/reservehall.cpp \
    View/Receptionist/reserveroom.cpp \
    View/Receptionist/reservetable.cpp \
    View/Receptionist/reservevehicle.cpp \
    View/Receptionist/updatedeleteres.cpp

HEADERS += \
    Control/maintenance.h \
    Control/receptionist_member.h \
    Control/reservable_manager.h \
    View/Receptionist/addguestdetails.h \
    View/Receptionist/addroomreservation.h \
    View/Receptionist/checkavailableroom.h \
    View/Receptionist/checkout.h \
    View/MaintenanceOrHouseKeeping/editroomstatus.h \
    View/HR/hr.h \
    View/loginscreen.h \
    View/Manger/manger.h \
    View/Receptionist/receptionist.h \
    View/Receptionist/reservehall.h \
    View/Receptionist/reserveroom.h \
    View/Receptionist/reservetable.h \
    View/Receptionist/reservevehicle.h \
    View/Receptionist/updatedeleteres.h \
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
    View/Receptionist/addguestdetails.ui \
    View/Receptionist/addroomreservation.ui \
    View/Receptionist/checkavailableroom.ui \
    View/Receptionist/checkout.ui \
    View/MaintenanceOrHouseKeeping/editroomstatus.ui \
    View/HR/hr.ui \
    View/loginscreen.ui \
    View/Manger/manger.ui \
    View/Receptionist/receptionist.ui \
    View/Receptionist/reservehall.ui \
    View/Receptionist/reserveroom.ui \
    View/Receptionist/reservetable.ui \
    View/Receptionist/reservevehicle.ui \
    View/Receptionist/updatedeleteres.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    LoginWindow.qrc
