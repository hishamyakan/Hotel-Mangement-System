#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QPixmap>
#include <QVector>



LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
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

}

