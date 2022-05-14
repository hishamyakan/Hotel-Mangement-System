#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QPixmap>
#include <QMessageBox>
#include <QVector>


QVector<QVector<QString>>myDataBase;

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    this->setFixedSize(647,355);

    QPixmap myPix(":/Image/LoginImage/1_XUrSasLtkB0VoXcLEMfJKg.jpeg");
    ui->Pic_Label->setPixmap(myPix);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}


void LoginScreen::on_Sign_In_clicked()
{
    QString localUserName =  ui->lineEdit_UderName->text();
    QString localPassword =  ui->lineEdit_Password->text();
    QStringList l;
    QString access;

    if(localUserName == "" || localPassword == "")
    {

    }
    else
    {
         l = localUserName.split("@");
          access = l[1].toLower();
    }



    if(access == "manger")
    {
         hide();
         manger = new Manger();
         manger->show();
    }

    else if(access == "receptionist")
    {
        hide();
        rec = new Receptionist();
        rec->show();

    }

    else if (access == "hr")
    {
        hide();
        hr = new HR();
        hr->show();
    }

    else if(access == "maintenance")
    {
        hide();
        me = new EditRoomStatus(nullptr,1);
        me->show();
    }
    else if(access == "housekeeping")
    {
        hide();
        hk = new EditRoomStatus(nullptr,0);
        hk->show();
    }

    else
    {
        QMessageBox::warning(this,"Invalid Login","Wrong user name or password, please try again");
    }

//    rec = new Receptionist();
//    rec->show();
//    hr = new HR();
//    hr->show();





}

