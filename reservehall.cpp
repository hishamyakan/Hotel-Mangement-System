#include "reservehall.h"
#include "ui_reservehall.h"

ReserveHall::ReserveHall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveHall)
{
    ui->setupUi(this);

    ui->EventType->addItem("Wedding");
    ui->EventType->addItem("Meeting");
    ui->EventType->addItem("Other");

    ui->HallSize->addItem("Small size Hall(up to 80 guests)");
    ui->HallSize->addItem("Medium size Hall(up to 200 guests)");
    ui->HallSize->addItem("Medium size Hall(up to 400 guests)");



    ui->CreditCardNumber->setEnabled(false);

    ui->NoAttend->setMaximum(400);
}

ReserveHall::~ReserveHall()
{
    delete ui;
}

void ReserveHall::on_Reserve_clicked()
{

}


void ReserveHall::on_CreditCard_clicked()
{
    ui->CreditCardNumber->setEnabled(true);
}


void ReserveHall::on_Cash_clicked()
{
    ui->CreditCardNumber->setEnabled(false);
}

