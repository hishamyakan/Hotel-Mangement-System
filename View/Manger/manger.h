#ifndef MANGER_H
#define MANGER_H

#include <QMainWindow>

#include "View/HR/hr.h"
#include "View/Receptionist/checkavailableroom.h"

namespace Ui {
class Manger;
}

class Manger : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manger(QWidget *parent = nullptr);
    ~Manger();

private slots:
    void on_EditEmpolyeeData_clicked();

    void on_ViewResStatus_clicked();

    void on_LogOut_clicked();

private:
    Ui::Manger *ui;
    HR * hr;
    CheckAvailableRoom *ch;

};

#endif // MANGER_H
