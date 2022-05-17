#include "reservevehicle.h"
#include "ui_reservevehicle.h"
#include "Control/guest.h"
#include "Control/reservation.h"
#include "Control/Date.h"
#include "Control/receptionist_member.h"

#include <string>
#include<QMessageBox>
#include<QDate>

Receptionist_Member r1;
Guest VGuest;

using namespace std;
//Guest VGuest;

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
    string ssn = ui->lineEdit_SSN->text().toStdString();
    string vType = ui->vType->currentText().toStdString();
    QDate resDate =  ui->dateEdit_vDate->date();


     VGuest.setName(name);
     VGuest.setSSN(ssn);


       Vehicle_Reservation myV;
       myV.setGuest(VGuest);
       myV.setStartDate({resDate.day(),resDate.month(),resDate.year()});

       QString temp;

       if(ui->vType->currentText() =="Car" )
       {
           temp  = "Car";
           myV.type = CAR;

       }
       else if(ui->vType->currentText() == "Bus")
       {
           temp  = "Bus";
            myV.type = BUS;
       }
       else{
           temp  = "Limo";
           myV.type = LIMO;
       }




if(r1.reserveVehicle(myV))
{
    QMessageBox::information(this,"Confirmation","A "+ temp + " Is Reserved at " +resDate.toString());
}

else
{
    QMessageBox::information(this,"Confirmation","Unfortunately No "+ temp + " Is Available at " +resDate.toString());
}




}

