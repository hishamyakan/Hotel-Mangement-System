#include "addroomreservation.h"
#include "ui_addroomreservation.h"
#include "Control/Date.h"
#include "Control/reservation.h"
#include "Control/receptionist_member.h"
#include <QMessageBox>
AddRoomReservation::AddRoomReservation(QWidget *parent,Guest *myGuest) :
    QDialog(parent),
    ui(new Ui::AddRoomReservation)
{
    ui->setupUi(this);
    this->setFixedSize(481,137);
    this->myGuest = myGuest;



        ui->roomType->addItem("Royal Suite",0);
        ui->roomType->addItem("Single Room",1);
        ui->roomType->addItem("Double Room",2);



        ui->dateEdit_sDate->setMaximumDate(QDate::currentDate().addYears(2));
        ui->dateEdit_sDate->setMinimumDate(QDate::currentDate());
        ui->dateEdit_sDate->setDate(QDate::currentDate());


        ui->dateEdit_eDate->setMaximumDate(QDate::currentDate().addYears(2));
        ui->dateEdit_eDate->setMinimumDate(QDate::currentDate());
        ui->dateEdit_eDate->setDate(QDate::currentDate());



}

AddRoomReservation::~AddRoomReservation()
{
    delete ui;
}

void AddRoomReservation::on_Reserve_clicked()
{

    Date sDate;
    Date eDate;


    sDate.day = ui->dateEdit_sDate->date().day();
    sDate.month = ui->dateEdit_sDate->date().month();
    sDate.year = ui->dateEdit_sDate->date().year();

    eDate.day =  ui->dateEdit_eDate->date().day();
    eDate.month =ui->dateEdit_eDate->date().month();
    eDate.year =ui->dateEdit_eDate->date().year();

    Room_Reservation res;
    res.setEndDate(eDate);
    res.setStartDate(sDate);
 res.setGuest(*this->myGuest);
    if(ui->roomType->currentText() == "Single Room")
    {
        res.type = SINGLE_ROOM;
        QMessageBox::information(this,"data","You are reserving a single room") ;
    }
    else if (ui->roomType->currentText() == "Double Room")
    {
         res.type = DOUBLE_ROOM;
         QMessageBox::information(this,"data","You are reserving a double room") ;
    }

    else if (ui->roomType->currentText() == "Royal Suite")
    {
        res.type = ROYAL_SUITE;
        QMessageBox::information(this,"data","You are reserving a royal suite") ;
    }

    Receptionist_Member receptionist;

    bool result = receptionist.reserveRoom(res);

    if(result == false){
    QMessageBox::warning(this,"Warning","Unfortunately No halls are available during this date");
    }

    else{

 QMessageBox::information(this,"data","Reservation wase made") ;
close();
    }
}

