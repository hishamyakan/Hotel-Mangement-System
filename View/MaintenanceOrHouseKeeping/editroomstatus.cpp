#include "editroomstatus.h"
#include "ui_editroomstatus.h"

#include "View/loginscreen.h"
#include "Control/hotelSystem.h"

#include <vector>
#include <string>


#define No     0
#define Type   1
#define Status 2

#define CALLER_HK 0
#define CALLER_M  1

int ncol, nrow;

bool edit = true;

int numberOfRooms = 0;
int numberOfVehicle = 0;

bool roomIsPressed = true;

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

    vector<int>count = MaintenanceCounts();
    ui->lineEdit->setText(QString::number(count[0]));
    ui->lineEdit_2->setText(QString::number(count[1]));
    ui->lineEdit_3->setText(QString::number(count[2]));
    ui->lineEdit_4->setText(QString::number(count[3]));
    ui->lineEdit_5->setText(QString::number(count[4]));
    ui->lineEdit_6->setText(QString::number(count[5]));





}

EditRoomStatus::~EditRoomStatus()
{
    delete ui;
}

void EditRoomStatus::on_editRoom_clicked()
{
    roomIsPressed = true;
    QStringList tableHeader = {"Room Number","Room Type", "Room Status"};
    ui->Reservable->setHorizontalHeaderLabels(tableHeader);
    edit = true;

    ui->Reservable->setRowCount(NUMBER_OF_SINGLE_ROOMS+NUMBER_OF_DOUBLE_ROOMS+NUMBER_OF_ROYAL_SUITES);
    auto model = ui->Reservable->model();
    vector<ReservableInfo>info = getRooms();
    numberOfRooms = (int)info.size();

    for(int i = 0 ; i<numberOfRooms; i++)
    {
            model->setData(model->index(i,No),info[i].number);
            model->setData(model->index(i,Type),QString::fromStdString(info[i].type));
            model->setData(model->index(i,Status),QString::fromStdString(info[i].status));

    }


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
    roomIsPressed = false;
    QStringList tableHeader = {"Vehicle Number","Vehicle Type" ,"Vehicle Status"};
    ui->Reservable->setHorizontalHeaderLabels(tableHeader);
    edit = false;

    ui->Reservable->setRowCount(NUMBER_OF_CARS+NUMBER_OF_BUSSES+NUMBER_OF_LIMOS);
    auto model = ui->Reservable->model();
    vector<ReservableInfo>info = getVehicles();
    numberOfVehicle = (int)info.size();

    for(int i = 0 ; i<numberOfVehicle; i++)
    {
            model->setData(model->index(i,No),info[i].number);
            model->setData(model->index(i,Type),QString::fromStdString(info[i].type));
            model->setData(model->index(i,Status),QString::fromStdString(info[i].status));

    }




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


void EditRoomStatus::on_UpdateRooms_clicked()
{
    auto model = ui->Reservable->model();
    model->setData(model->index(nrow,Status),ui->comboBox_RoomStatus->currentText());

}


void EditRoomStatus::on_Save_clicked()
{
    vector<string>statusCollected ;
     auto model = ui->Reservable->model();

    if(true == roomIsPressed)
    {
        for(int row = 0; row<numberOfRooms; row++)
        {

            statusCollected.push_back( model->data(model->index(row,Status)).toString().toStdString());
        }

        Maintenance_Member member;
        member.setRoomsAvailability(statusCollected);
    }

    else
    {
        for(int row = 0; row<numberOfVehicle; row++)
        {

            statusCollected.push_back( model->data(model->index(row,Status)).toString().toStdString());
        }

        Maintenance_Member member;
        member.setVehiclesAvailability(statusCollected);
    }


    vector<int>count = MaintenanceCounts();
    ui->lineEdit->setText(QString::number(count[0]));
    ui->lineEdit_2->setText(QString::number(count[1]));
    ui->lineEdit_3->setText(QString::number(count[2]));
    ui->lineEdit_4->setText(QString::number(count[3]));
    ui->lineEdit_5->setText(QString::number(count[4]));
    ui->lineEdit_6->setText(QString::number(count[5]));


}


void EditRoomStatus::on_UpdateVehicle_clicked()
{
    auto model = ui->Reservable->model();
    model->setData(model->index(nrow,Status),ui->comboBox_VehicleStatus->currentText());
}

