#ifndef RESERVEROOM_H
#define RESERVEROOM_H

#include <QMainWindow>


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

private:
    Ui::ReserveRoom *ui;
};

#endif // RESERVEROOM_H
