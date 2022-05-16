#include "reservehall.h"
#include "ui_reservehall.h"

#include <string>
#include <QMessageBox>

using namespace std;

bool creditCard = false;

ReserveHall::ReserveHall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveHall)
{
    ui->setupUi(this);
    this->setFixedSize(692,274);

    ui->EventType->addItem("Wedding");
    ui->EventType->addItem("Meeting");
    ui->EventType->addItem("Other");

    ui->HallSize->addItem("Small size Hall(up to 80 guests)",0);
    ui->HallSize->addItem("Medium size Hall(up to 200 guests)",1);
    ui->HallSize->addItem("Large size Hall(up to 400 guests)",2);



    ui->CreditCardNumber->setEnabled(false);

    ui->NoAttend->setMaximum(400);


    ui->dateEdit->setMaximumDate(QDate::currentDate().addYears(2));
    ui->dateEdit->setMinimumDate(QDate::currentDate());
    ui->dateEdit->setDate(QDate::currentDate());
}

ReserveHall::~ReserveHall()
{
    delete ui;
}

void ReserveHall::on_Reserve_clicked()
{
    string guestName = ui->Name->text().toStdString();
    string guestSSN  = ui->SSN->text().toStdString();
    string guestMail = ui->Mail->text().toStdString();
    string guestAddress = ui->Adress->text().toStdString();
    int guestNoAttend = ui->NoAttend->text().toInt();

    QDate guestDate = ui->dateEdit->date();

    if(true == creditCard)
    {
        string guestCreditCard= ui->CreditCardNumber->text().toStdString();
    }
    else
    {
        //do Nothing
    }

    if(ui->HallSize->currentIndex() == 0)
    {

    }
    else if (ui->HallSize->currentIndex() == 1)
    {

    }

    else if(ui->HallSize->currentIndex() == 2)
    {

    }


    QMessageBox::information(this,"Hall Reserrvation","Hall was reserved successfully");
    QMessageBox::information(this,"Unfortunately","Unfortunately No halls are available during this date");

}


void ReserveHall::on_CreditCard_clicked()
{
    ui->CreditCardNumber->setEnabled(true);
    creditCard = true;
}


void ReserveHall::on_Cash_clicked()
{
    ui->CreditCardNumber->setEnabled(false);
    creditCard = false;
}

