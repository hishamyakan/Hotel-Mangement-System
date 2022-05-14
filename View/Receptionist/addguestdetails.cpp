#include "addguestdetails.h"
#include "ui_addguestdetails.h"
#include <string>
#include<QMessageBox>


using namespace std;

AddGuestDetails::AddGuestDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGuestDetails)
{
    ui->setupUi(this);
    this->setFixedSize(524,194);
}

AddGuestDetails::~AddGuestDetails()
{
    delete ui;
}

void AddGuestDetails::on_AddData_clicked()
{
    string name = ui->lineEdit_Name->text().toStdString();
    string SSN = ui->lineEdit_SSN->text().toStdString();
    string phone = ui->lineEdit_Phone->text().toStdString();
    string mail = ui->lineEdit_Mail->text().toStdString();

    QMessageBox::about(this,"Confirmation","Congratulations guest data is added successfully");



    close();

}

