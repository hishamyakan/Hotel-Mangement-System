#ifndef ADDROOMRESERVATION_H
#define ADDROOMRESERVATION_H

#include <QDialog>

namespace Ui {
class AddRoomReservation;
}

class AddRoomReservation : public QDialog
{
    Q_OBJECT

public:
    explicit AddRoomReservation(QWidget *parent = nullptr);
    ~AddRoomReservation();

private:
    Ui::AddRoomReservation *ui;
};

#endif // ADDROOMRESERVATION_H
