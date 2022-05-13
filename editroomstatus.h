#ifndef EDITROOMSTATUS_H
#define EDITROOMSTATUS_H

#include <QMainWindow>

namespace Ui {
class EditRoomStatus;
}

class EditRoomStatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditRoomStatus(QWidget *parent = nullptr, int caller = 0);
    ~EditRoomStatus();

private slots:
    void on_editRoom_clicked();

    void on_editStatus_clicked();

    void on_Reservable_cellClicked(int row, int column);

    void on_editVehicle_clicked();

    void on_LogOut_clicked();

    void on_Update_clicked();

private:
    Ui::EditRoomStatus *ui;
};

#endif // EDITROOMSTATUS_H
