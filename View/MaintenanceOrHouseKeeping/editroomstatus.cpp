#include "editroomstatus.h"
#include "ui_editroomstatus.h"

#include "View/loginscreen.h"


#define No     0
#define Type   1
#define Status 2

#define CALLER_HK 0
#define CALLER_M  1

int ncol, nrow;

bool edit = true;

EditRoomStatus::EditRoomStatus(QWidget *parent, int caller) :
    QMainWindow(parent),
    ui(new Ui::EditRoomStatus)
{
    ui->setupUi(this);
    this->setFixedSize(715,355);

    ui->Reservable->setColumnCount(3);
    ui->Reservable->horizontalHeader()->setStretchLastSection(true);
    ui->Reservable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    ui->Reservable->setColumnWidth(No,95);
    ui->Reservable->setColumnWidth(Type,150);
    ui->Reservable->setColumnWidth(Status,150);

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);

    ui->lineEdit_RoomNo->setReadOnly(true);
    ui->lineEdit_RoomType->setReadOnly(true);
    ui->lineEdit_VehicleNo->setReadOnly(true);
    ui->lineEdit_VehicleType->setReadOnly(true);

    QStringList status = {"Available", "UnAvailable"};
    ui->comboBox_RoomStatus->addItems(status);
    ui->comboBox_VehicleStatus->addItems(status);

    if(caller == CALLER_HK)
    {
        ui->groupBox_Vehicle->setEnabled(false);
        ui->editVehicle->setEnabled(false);
    }


    ui->lineEdit->setText("30");
    ui->lineEdit_2->setText("20");
    ui->lineEdit_3->setText("10");
    ui->lineEdit_4->setText("10");
    ui->lineEdit_5->setText("3");
    ui->lineEdit_6->setText("4");





}

EditRoomStatus::~EditRoomStatus()
{
    delete ui;
}

void EditRoomStatus::on_editRoom_clicked()
{
    QStringList tableHeader = {"Room Number","Room Type", "Room Status"};
    ui->Reservable->setHorizontalHeaderLabels(tableHeader);
    edit = true;

    ui->Reservable->setRowCount(1);
    auto model = ui->Reservable->model();
    model->setData(model->index(0,No),"1");
    model->setData(model->index(0,Type),"single");
    model->setData(model->index(0,Status),"UnAvailable");



}


void EditRoomStatus::on_editStatus_clicked()
{

}


void EditRoomStatus::on_Reservable_cellClicked(int row, int column)
{
    nrow = row;
    ncol = column;

    auto model = ui->Reservable->model();

    if(edit)
    {
        QString data = model->data(model->index(row,No)).toString();
        ui->lineEdit_RoomNo->setText(data);

        data = model->data(model->index(row,Type)).toString();
        ui->lineEdit_RoomType->setText(data);

        data = model->data(model->index(row,Status)).toString();
        int index = ui->comboBox_RoomStatus->findText(data);
        ui->comboBox_RoomStatus->setCurrentIndex(index);


    }

    else
    {
        QString data = model->data(model->index(row,No)).toString();
        ui->lineEdit_VehicleNo->setText(data);

        data = model->data(model->index(row,Type)).toString();
        ui->lineEdit_VehicleType->setText(data);

        data = model->data(model->index(row,Status)).toString();
        int index = ui->comboBox_VehicleStatus->findText(data);
        ui->comboBox_VehicleStatus->setCurrentIndex(index);

    }


}


void EditRoomStatus::on_editVehicle_clicked()
{
    QStringList tableHeader = {"Vehicle Number","Vehicle Type" ,"Vehicle Status"};
    ui->Reservable->setHorizontalHeaderLabels(tableHeader);
    edit = false;




}


void EditRoomStatus::on_LogOut_clicked()
{
    close();
    LoginScreen *l_ptr = new LoginScreen();
    l_ptr->show();
}


void EditRoomStatus::on_Update_clicked()
{

}

