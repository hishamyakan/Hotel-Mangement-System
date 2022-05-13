#include "manger.h"
#include "ui_manger.h"
#include "loginscreen.h"
#include <QPixmap>



Manger::Manger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manger)
{
    ui->setupUi(this);
    this->setFixedSize(558,222);

    QPixmap myPix(":/Image/LoginImage/1_XUrSasLtkB0VoXcLEMfJKg.jpeg");
    ui->label->setPixmap(myPix);
}

Manger::~Manger()
{
    delete ui;
}

void Manger::on_EditEmpolyeeData_clicked()
{

    hr = new HR(this,1);
    hr->setWindowModality(Qt::WindowModal);
    hr->show();
}


void Manger::on_ViewResStatus_clicked()
{
    ch = new CheckAvailableRoom(this);
    ch->setWindowModality(Qt::WindowModal);
    ch->show();
}


void Manger::on_LogOut_clicked()
{
    close();
    LoginScreen *l_ptr = new LoginScreen();
    l_ptr->show();
}

