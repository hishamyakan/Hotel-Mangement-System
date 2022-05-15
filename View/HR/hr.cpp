#include "hr.h"
#include "ui_hr.h"
#include <QTableWidget>
#include <QStringList>
#include "View/loginscreen.h"

#include "Control/hotelSystem.h"
#include <vector>
#include<iostream>
using namespace std;

/*These pre procesors are used for determining the col number*/

#define NAME       0
#define SSN_Index        1
#define DEPARTMENT 2
#define SALARY     3

#define CALLER_HR  0
#define CALLER_MR  1


int colNum, rowNum;
int sortBy = NAME;


HR::HR(QWidget *parent , int caller) :
    QMainWindow(parent),
    ui(new Ui::HR)
{
    ui->setupUi(this);
    this->setFixedSize(680,447);

    if(caller == CALLER_HR)
    {
        //Do Nothing
    }
    else if(caller == CALLER_MR)
    {
        ui->LogOut->deleteLater();
    }

    rowNum = -1;
    colNum = -1;

    HR_Member newHrMeb;
    vector<EmployeeInfo>Data = newHrMeb.getEmployeeData();
    int x = (int)Data.size();
    ui->tableWidget->setRowCount(x);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    QStringList tableHeader = {"Name", "SSN","Department","Salary"};
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    int h = this->width();

    ui->tableWidget->setColumnWidth(0,40*h/100);
    ui->tableWidget->setColumnWidth(1,20*h/100);
    ui->tableWidget->setColumnWidth(2,20*h/100);
    ui->tableWidget->setColumnWidth(3,10*h/100);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList Dep = {"HR", "Maintenance","Receptionist","HouseKeeping","Service"};
    ui->comboBox_Dep->addItems(Dep);


    QStringList sort = {"Name","Department"};
     ui->comboBox_SortBy->addItems(sort);


    auto model = ui->tableWidget->model();


    for(int i = 0; i <x ; i++)
    {

        cout <<Data[i].name<<endl;

        model->setData(model->index(i,NAME),QString::fromStdString(Data[i].name));

        model->setData(model->index(i,SSN_Index),QString::fromStdString(Data[i].SSN));

        model->setData(model->index(i,DEPARTMENT),QString::fromStdString(Data[i].department));
        QString temp;
        temp = QString::number(Data[i].salary);
        model->setData(model->index(i,SALARY),temp);

    }



//    model->setData(model->index(0,NAME),"Hisham Yakan");
//    model->setData(model->index(0,SSN),"30002012100792");
//    model->setData(model->index(0,DEPARTMENT),"HR");
//    model->setData(model->index(0,SALARY),"1000");
     ui->tableWidget->sortItems(sortBy);




}

HR::~HR()
{
    delete ui;
}

void HR::on_tableWidget_cellActivated(int row, int column)
{
     auto model = ui->tableWidget->model();

     QString data = model->data(model->index(row,NAME)).toString();
     ui->lineEdit_Name->setText(data);

     data = model->data(model->index(row,SALARY)).toString();
     ui->lineEdit_Salary->setText(data);

     data = model->data(model->index(row,SSN_Index)).toString();
     ui->lineEdit_SSN->setText(data);



}


void HR::on_tableWidget_cellClicked(int row, int column)
{
    rowNum = row;
    colNum = column;

    auto model = ui->tableWidget->model();

    QString data = model->data(model->index(row,NAME)).toString();
    ui->lineEdit_Name->setText(data);

    data = model->data(model->index(row,SALARY)).toString();
    ui->lineEdit_Salary->setText(data);

    data = model->data(model->index(row,SSN_Index)).toString();
    ui->lineEdit_SSN->setText(data);

     data = model->data(model->index(row,DEPARTMENT)).toString();
    int index = ui->comboBox_Dep->findText(data);
    ui->comboBox_Dep->setCurrentIndex(index);


}


void HR::on_Update_clicked()
{

    auto model = ui->tableWidget->model();
    model->setData(model->index(rowNum,NAME),ui->lineEdit_Name->text());
    model->setData(model->index(rowNum,SSN_Index),ui->lineEdit_SSN->text());
    model->setData(model->index(rowNum,DEPARTMENT),ui->comboBox_Dep->currentText());
    model->setData(model->index(rowNum,SALARY),ui->lineEdit_Salary->text());

    ui->tableWidget->sortItems(sortBy);

}


void HR::on_AddNewEmp_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    auto model = ui->tableWidget->model();
    model->setData(model->index(ui->tableWidget->rowCount()-1,NAME),ui->lineEdit_Name->text());
    model->setData(model->index(ui->tableWidget->rowCount()-1,SSN_Index),ui->lineEdit_SSN->text());
    model->setData(model->index(ui->tableWidget->rowCount()-1,DEPARTMENT),ui->comboBox_Dep->currentText());
    model->setData(model->index(ui->tableWidget->rowCount()-1,SALARY),ui->lineEdit_Salary->text());
     ui->tableWidget->sortItems(sortBy);

}


void HR::on_Delete_clicked()
{
     ui->tableWidget->removeRow(rowNum);
     ui->tableWidget->sortItems(sortBy);
}


void HR::on_Sort_clicked()
{

    if(ui->comboBox_SortBy->currentText() == "Department")
    {
        sortBy = DEPARTMENT;
    }

    else
    {
        sortBy = NAME;
    }

    ui->tableWidget->sortItems(sortBy);
}


void HR::on_LogOut_clicked()
{
    close();
    LoginScreen *l_ptr = new LoginScreen();
    l_ptr->show();

}


void HR::on_Clear_clicked()
{
    rowNum = -1;
    colNum = -1;
    ui->lineEdit_Name->setText(nullptr);
    ui->lineEdit_Salary->setText(nullptr);
    ui->lineEdit_SSN->setText(nullptr);
}


void HR::on_Save_clicked()
{
    vector<EmployeeInfo>NewSavedData;
    auto model = ui->tableWidget->model();
    for (int i = 0 ; i < ui->tableWidget->rowCount(); i++)
    {
        QString data = model->data(model->index(i,NAME)).toString();
        string name = data.toStdString();

        data = model->data(model->index(i,SALARY)).toString();
        double salary = data.toDouble();

        data = model->data(model->index(i,SSN_Index)).toString();
        string ssn = data.toStdString();


         data = model->data(model->index(i,DEPARTMENT)).toString();
         string department = data.toStdString();

         NewSavedData.push_back(EmployeeInfo(name,ssn,department,salary));

    }
    HR_Member newHrMeb;
    newHrMeb.saveEmployeeData(NewSavedData);
}

