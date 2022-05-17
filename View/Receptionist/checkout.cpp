#include "checkout.h"
#include "ui_checkout.h"
#include <QMessageBox>

#include "Control/guest.h"
#include "Control/receptionist_member.h"

CheckOut::CheckOut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckOut)
{
    ui->setupUi(this);

    ui->G_FeedBack->setEnabled(false);
    this->setFixedSize(783,557);


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


void CheckOut::on_addFeedBack_clicked()
{
    QMessageBox::information(this,"FeedBack","Congratulations, FeedBack added successfully.");

}


void CheckOut::on_CalcPay_clicked()
{

    Receptionist_Member r;
    string name = ui->lineEdit_Name->text().toStdString();
    string ssn = ui->lineEdit_ssn->text().toStdString();

    long long k = r.getPayment(ssn);

    QMessageBox::information(this,"Payment","The total amount to pay in EGP "+QString::number(k)+"EGP");

}


void CheckOut::on_CheckOut_2_clicked()
{
    if(ui->CreditCardNumber->text() == "" && ui->CreditCard->isChecked() == true)
    {
         QMessageBox::information(this,"Warning","Please enter Credit Card Number");
    }
    else  if( ui->Cash->isChecked() == true)
    {
    QMessageBox::information(this,"Congratulations","Payment is Done");
    }

    else{
        QMessageBox::information(this,"Congratulations","Payment is Done");
    }

}

