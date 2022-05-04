#include "reserveroom.h"
#include "ui_reserveroom.h"

ReserveRoom::ReserveRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveRoom)
{
    ui->setupUi(this);
    ui->roomType->addItem("Single Room");
    ui->roomType->addItem("Double Room");
    ui->roomType->addItem("Royal Suite");
}

ReserveRoom::~ReserveRoom()
{
    delete ui;
}
