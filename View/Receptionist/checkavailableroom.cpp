#include "checkavailableroom.h"
#include "ui_checkavailableroom.h"



#define No     0
#define Type   1
#define Status 2

CheckAvailableRoom::CheckAvailableRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckAvailableRoom)
{
    ui->setupUi(this);

    this->setFixedSize(673,241);

    ui->Reservable->setColumnCount(3);
    ui->Reservable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->Reservable->setColumnWidth(No,95);
    ui->Reservable->setColumnWidth(Type,150);
    ui->Reservable->setColumnWidth(Status,150);

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);



    ui->lineEdit->setText("30");
    ui->lineEdit_2->setText("20");
    ui->lineEdit_3->setText("10");
    ui->lineEdit_4->setText("10");
    ui->lineEdit_5->setText("3");
    ui->lineEdit_6->setText("4");


}

CheckAvailableRoom::~CheckAvailableRoom()
{
    delete ui;
}

void CheckAvailableRoom::on_RoomStatus_clicked()
{
     QStringList tableHeader = {"Room Number","Room Type", "Room Status"};
     ui->Reservable->setHorizontalHeaderLabels(tableHeader);


}


void CheckAvailableRoom::on_VehicleStatus_clicked()
{
    QStringList tableHeader = {"Vehicle Number","Vehicle Type" ,"Vehicle Status"};
    ui->Reservable->setHorizontalHeaderLabels(tableHeader);


}

