#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>

#include "View/Receptionist/receptionist.h"
#include "View/HR/hr.h"
#include "View/Manger/manger.h"
#include "View/MaintenanceOrHouseKeeping/editroomstatus.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void on_Sign_In_clicked();

private:
    Ui::LoginScreen *ui;
    Receptionist *rec;
    HR * hr;
    Manger *manger;
    EditRoomStatus *hk;
    EditRoomStatus *me;
};
#endif // LOGINSCREEN_H
