#include "updatedeleteres.h"
#include "ui_updatedeleteres.h"

updateDeleteRes::updateDeleteRes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updateDeleteRes)
{
    ui->setupUi(this);
}

updateDeleteRes::~updateDeleteRes()
{
    delete ui;
}
