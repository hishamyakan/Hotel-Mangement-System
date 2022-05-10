#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>
#include "reserveroom.h"
#include "receptionist.h"

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
    ReserveRoom *r;
    Receptionist *rec;
};
#endif // LOGINSCREEN_H
