#ifndef RESERVEROOM_H
#define RESERVEROOM_H

#include <QMainWindow>
#include "Control/guest.h"


namespace Ui {
class ReserveRoom;
}

class ReserveRoom : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReserveRoom(QWidget *parent = nullptr);
    ~ReserveRoom();

private slots:
    void on_addGuestData_clicked();

    void on_AddReservation_clicked();

    void on_Submit_clicked();

    void on_AddNewGuest_clicked();

private:
    Ui::ReserveRoom *ui;
    //Guest newGuest;
};

#endif // RESERVEROOM_H
