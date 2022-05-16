#include "addroomreservation.h"
#include "ui_addroomreservation.h"

AddRoomReservation::AddRoomReservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRoomReservation)
{
    ui->setupUi(this);
    this->setFixedSize(481,137);

        ui->roomType->addItem("Single Room");
        ui->roomType->addItem("Double Room");
        ui->roomType->addItem("Royal Suite");


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



    ui->dateEdit_sDate->date().day();
    ui->dateEdit_sDate->date().month();
    ui->dateEdit_sDate->date().year();

    ui->dateEdit_eDate->date().day();
    ui->dateEdit_eDate->date().month();
    ui->dateEdit_eDate->date().year();
}

