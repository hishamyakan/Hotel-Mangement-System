#include "checkavailableroom.h"
#include "ui_checkavailableroom.h"
#include"Control/hotelSystem.h"

#include <vector>

#define No     0
#define Type   1
#define Status 2

int numberOfRooms2 = 0;
int numberOfVehicle2 = 0;

CheckAvailableRoom::CheckAvailableRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckAvailableRoom)
{
    ui->setupUi(this);

    this->setFixedSize(673,241);

    ui->Reservable->setColumnCount(3);
    ui->Reservable->setEditTriggers(QAbstractItemView::NoEditTriggers);



    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);



    vector<int>count = AvailabilityCounts();
    ui->lineEdit->setText(QString::number(count[0]));
    ui->lineEdit_2->setText(QString::number(count[1]));
    ui->lineEdit_3->setText(QString::number(count[2]));
    ui->lineEdit_4->setText(QString::number(count[3]));
    ui->lineEdit_5->setText(QString::number(count[4]));
    ui->lineEdit_6->setText(QString::number(count[5]));


}

CheckAvailableRoom::~CheckAvailableRoom()
{
    delete ui;
}

void CheckAvailableRoom::on_RoomStatus_clicked()
{
     QStringList tableHeader = {"Room Number","Room Type", "Room Status"};
     ui->Reservable->setHorizontalHeaderLabels(tableHeader);

     ui->Reservable->setRowCount(NUMBER_OF_SINGLE_ROOMS+NUMBER_OF_DOUBLE_ROOMS+NUMBER_OF_ROYAL_SUITES);
     auto model = ui->Reservable->model();
     vector<ReservableInfo>info = getRooms2();
     numberOfRooms2 = (int)info.size();

     for(int i = 0 ; i<numberOfRooms2; i++)
     {
             model->setData(model->index(i,No),info[i].number);
             model->setData(model->index(i,Type),QString::fromStdString(info[i].type));
             model->setData(model->index(i,Status),QString::fromStdString(info[i].status));

     }



}


void CheckAvailableRoom::on_VehicleStatus_clicked()
{
    QStringList tableHeader = {"Vehicle Number","Vehicle Type" ,"Vehicle Status"};
    ui->Reservable->setHorizontalHeaderLabels(tableHeader);

    ui->Reservable->setRowCount(NUMBER_OF_CARS+NUMBER_OF_BUSSES+NUMBER_OF_LIMOS);
    auto model = ui->Reservable->model();
    vector<ReservableInfo>info = getVehicles2();
    numberOfVehicle2 = (int)info.size();

    for(int i = 0 ; i<numberOfVehicle2; i++)
    {
            model->setData(model->index(i,No),info[i].number);
            model->setData(model->index(i,Type),QString::fromStdString(info[i].type));
            model->setData(model->index(i,Status),QString::fromStdString(info[i].status));

    }

}

