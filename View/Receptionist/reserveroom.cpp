#include "reserveroom.h"
#include "ui_reserveroom.h"
#include "addguestdetails.h"
#include "addroomreservation.h"
#include "Control/guest.h"

#include <QMessageBox>

Guest newGuest;


ReserveRoom::ReserveRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveRoom)
{
    ui->setupUi(this);
    this->setFixedSize(713,269);
    this->setWindowTitle("Reserve a Room");



}

ReserveRoom::~ReserveRoom()
{
    delete ui;
}

void ReserveRoom::on_addGuestData_clicked()
{
    AddGuestDetails newGuestData;
    newGuestData.setModal(true);
    newGuestData.exec();

}


void ReserveRoom::on_AddReservation_clicked()
{


    newGuest.setName(ui->lineEdit_Name->text().toStdString());
    newGuest.setSSN(ui->lineEdit_SSN->text().toStdString());
    newGuest.setMail(ui->lineEdit_Mail->text().toStdString());
    newGuest.setPhoneNumber(ui->lineEdit_Phone->text().toStdString());
    newGuest.setAddress(ui->lineEdit_Address->text().toStdString());


    //QMessageBox::information(this,"data",QString::fromStdString(newGuest.getSSN()));

    AddRoomReservation newRes(nullptr,&newGuest);
    newRes.setModal(true);
    newRes.exec();


}


void ReserveRoom::on_Submit_clicked()
{

}


void ReserveRoom::on_AddNewGuest_clicked()
{



}

