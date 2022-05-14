#ifndef CHECKAVAILABLEROOM_H
#define CHECKAVAILABLEROOM_H

#include <QMainWindow>

namespace Ui {
class CheckAvailableRoom;
}

class CheckAvailableRoom : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckAvailableRoom(QWidget *parent = nullptr);
    ~CheckAvailableRoom();

private slots:
    void on_RoomStatus_clicked();

    void on_VehicleStatus_clicked();

private:
    Ui::CheckAvailableRoom *ui;
};

#endif // CHECKAVAILABLEROOM_H
