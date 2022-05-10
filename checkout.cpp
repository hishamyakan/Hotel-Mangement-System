#include "checkout.h"
#include "ui_checkout.h"

CheckOut::CheckOut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckOut)
{
    ui->setupUi(this);

    ui->G_FeedBack->setEnabled(false);


}

CheckOut::~CheckOut()
{
    delete ui;
}

void CheckOut::on_f_yes_clicked()
{

    ui->G_FeedBack->setEnabled(true);

}


void CheckOut::on_radioButton_2_clicked()
{
    ui->G_FeedBack->setEnabled(false);
}


void CheckOut::on_CreditCard_clicked()
{
     ui->CreditCardNumber->setEnabled(true);
}


void CheckOut::on_Cash_clicked()
{
    ui->CreditCardNumber->setEnabled(false);
}

