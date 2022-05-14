#include "reservevehicle.h"
#include "ui_reservevehicle.h"
#include <string>
#include<QMessageBox>
#include<QDate>

using namespace std;


ReserveVehicle::ReserveVehicle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveVehicle)
{
    ui->setupUi(this);
    this->setFixedSize(555,152);
    this->setWindowTitle("Reserve a vehicle");

    ui->vType->addItem("Car");
    ui->vType->addItem("Bus");
    ui->vType->addItem("Limousine car");

    ui->dateEdit_vDate->setMaximumDate(QDate::currentDate().addYears(2));
    ui->dateEdit_vDate->setMinimumDate(QDate::currentDate());
    ui->dateEdit_vDate->setDate(QDate::currentDate());
}

ReserveVehicle::~ReserveVehicle()
{
    delete ui;
}

void ReserveVehicle::on_Reserve_clicked()
{
     string name = ui->lineEdit_Name->text().toStdString();
     string roomNumber = ui->lineEdit_RoomNumber->text().toStdString();
     string vType = ui->vType->currentText().toStdString();
     QDate resDate =  ui->dateEdit_vDate->date();



     QMessageBox::about(this,"Confirmation",ui->vType->currentText());

}

