#include "updatedeleteres.h"
#include "ui_updatedeleteres.h"

updateDeleteRes::updateDeleteRes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updateDeleteRes)
{
    ui->setupUi(this);
    this->setFixedSize(683,358);

    ui->tableWidget_res->setRowCount(1);
    ui->tableWidget_res->setColumnCount(2);
    ui->tableWidget_res->horizontalHeader()->setStretchLastSection(true);

    QStringList tableHeader = {"Reservation Date","Resrved Item"};
    ui->tableWidget_res->setHorizontalHeaderLabels(tableHeader);

    int h = this->width();
    ui->tableWidget_res->setColumnWidth(0,25*h/100);
    ui->tableWidget_res->setColumnWidth(1,71*h/100);
}

updateDeleteRes::~updateDeleteRes()
{
    delete ui;
}
