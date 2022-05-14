#ifndef RESERVEHALL_H
#define RESERVEHALL_H

#include <QMainWindow>

namespace Ui {
class ReserveHall;
}

class ReserveHall : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReserveHall(QWidget *parent = nullptr);
    ~ReserveHall();

private slots:
    void on_Reserve_clicked();

    void on_CreditCard_clicked();

    void on_Cash_clicked();

private:
    Ui::ReserveHall *ui;
};

#endif // RESERVEHALL_H
