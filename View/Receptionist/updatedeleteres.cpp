#include "updatedeleteres.h"
#include "ui_updatedeleteres.h"
#include "Control/reservable_manager.h"

#include <vector>
#include <string>

using namespace std;

int myNcol = -1;
int myNrow = -1;

updateDeleteRes::updateDeleteRes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updateDeleteRes)
{
    ui->setupUi(this);
    this->setFixedSize(683,358);

    ui->tableWidget_res->setRowCount(1);
    ui->tableWidget_res->setColumnCount(2);
    ui->tableWidget_res->horizontalHeader()->setStretchLastSection(true);

    QStringList tableHeader = {"Reservation Date","Resrved Item"};
    ui->tableWidget_res->setHorizontalHeaderLabels(tableHeader);

    int h = this->width();
    ui->tableWidget_res->setColumnWidth(0,25*h/100);
    ui->tableWidget_res->setColumnWidth(1,71*h/100);
}

updateDeleteRes::~updateDeleteRes()
{
    delete ui;
}

void updateDeleteRes::on_GetReservationList_clicked()
{
    vector<Guest_ReservationsInfo> s = getGuestReservations(ui->lineEdit_SSN->text().toStdString());
    int size = (int)s.size();
    auto model = ui->tableWidget_res->model();

    ui->tableWidget_res->setRowCount(size);
    for(int i = 0; i<size; i ++)
    {
        model->setData(model->index(i,1), QString::fromStdString( s[i].type) );
        QDate myDate(s[i].reservationDate.year,s[i].reservationDate.month,s[i].reservationDate.day);
        model->setData(model->index(i,0), myDate.toString());
    }



}


void updateDeleteRes::on_Delete_clicked()
{
    ui->tableWidget_res->removeRow(myNrow );

}


void updateDeleteRes::on_tableWidget_res_cellClicked(int row, int column)
{
    myNcol = column;
    myNrow = row;

}

