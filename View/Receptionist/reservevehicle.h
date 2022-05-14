#ifndef RESERVEVEHICLE_H
#define RESERVEVEHICLE_H

#include <QMainWindow>

namespace Ui {
class ReserveVehicle;
}

class ReserveVehicle : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReserveVehicle(QWidget *parent = nullptr);
    ~ReserveVehicle();

private slots:
    void on_Reserve_clicked();

private:
    Ui::ReserveVehicle *ui;
};

#endif // RESERVEVEHICLE_H
