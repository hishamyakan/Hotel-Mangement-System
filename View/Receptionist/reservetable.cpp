#include "reservetable.h"
#include "ui_reservetable.h"
#include <QDateTime>
#include <QTime>

#include <string>
#include <QMessageBox>

using namespace std;

ReserveTable::ReserveTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReserveTable)
{
    ui->setupUi(this);
    this->setFixedSize(391,294);
}

ReserveTable::~ReserveTable()
{
    delete ui;
}

void ReserveTable::on_Reserve_clicked()
{
   string guestName = ui->lineEdit_Name->text().toStdString();
   QTime time = ui->dateTimeEdit->time();
}

