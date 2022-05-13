#include "receptionist.h"
#include "ui_receptionist.h"


#include "loginscreen.h"



Receptionist::Receptionist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Receptionist)
{
    ui->setupUi(this);

     this->setFixedSize(389,300);

    QPixmap myPix(":/Image/LoginImage/1_XUrSasLtkB0VoXcLEMfJKg.jpeg");
    ui->Pic_Label->setPixmap(myPix);
}

Receptionist::~Receptionist()
{
    delete ui;
}

void Receptionist::on_LogOut_clicked()
{
    close();
    LoginScreen *l_ptr = new LoginScreen();
    l_ptr->show();


}


void Receptionist::on_ReserveRoom_clicked()
{

    r = new ReserveRoom();
    r->show();


}


void Receptionist::on_ReserveVehicle_clicked()
{
    v = new ReserveVehicle();
    v->show();

}


void Receptionist::on_ReserveHall_clicked()
{
    h = new ReserveHall();
    h->show();
}


void Receptionist::on_CheckOut_clicked()
{
    c = new CheckOut();
    c->show();
}


void Receptionist::on_updateOrDelete_clicked()
{
    u = new updateDeleteRes();
    u->show();
}


void Receptionist::on_ReserveTable_clicked()
{
    t = new ReserveTable();
    t->show();
}


void Receptionist::on_CheckRes_clicked()
{
    ch = new CheckAvailableRoom();
    ch->show();
}

