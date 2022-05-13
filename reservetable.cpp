#include "reservetable.h"
#include "ui_reservetable.h"

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
