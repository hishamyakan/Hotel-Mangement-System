#include "reserveroom.h"
#include "ui_reserveroom.h"
#include "addguestdetails.h"
#include "addroomreservation.h"

ReserveRoom::ReserveRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveRoom)
{
    ui->setupUi(this);
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
    AddRoomReservation newRes;
    newRes.setModal(true);
    newRes.exec();


}

