#ifndef ADDROOMRESERVATION_H
#define ADDROOMRESERVATION_H

#include <QDialog>
#include "Control/guest.h"

namespace Ui {
class AddRoomReservation;
}

class AddRoomReservation : public QDialog
{
    Q_OBJECT

public:
    explicit AddRoomReservation(QWidget *parent = nullptr , Guest *myGuest = nullptr);
    ~AddRoomReservation();

private slots:
    void on_Reserve_clicked();

private:
    Ui::AddRoomReservation *ui;
    Guest *myGuest;
};

#endif // ADDROOMRESERVATION_H
