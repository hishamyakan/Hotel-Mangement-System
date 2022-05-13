#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <QMainWindow>
#include "reserveroom.h"
#include "reservevehicle.h"
#include "reservehall.h"
#include "reservetable.h"
#include "checkout.h"
#include "updatedeleteres.h"
#include "checkavailableroom.h"


namespace Ui {
class Receptionist;
}

class Receptionist : public QMainWindow
{
    Q_OBJECT

public:
    explicit Receptionist(QWidget *parent = nullptr);
    ~Receptionist();

private slots:
    void on_LogOut_clicked();

    void on_ReserveRoom_clicked();

    void on_ReserveVehicle_clicked();

    void on_ReserveHall_clicked();

    void on_CheckOut_clicked();

    void on_updateOrDelete_clicked();

    void on_ReserveTable_clicked();

    void on_CheckRes_clicked();

private:
    Ui::Receptionist *ui;
    ReserveRoom *r;
    ReserveVehicle *v;
    ReserveHall *h;
    ReserveTable *t;
    CheckOut *c;
    updateDeleteRes *u;
    CheckAvailableRoom *ch;



};

#endif // RECEPTIONIST_H
