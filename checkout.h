#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QMainWindow>

namespace Ui {
class CheckOut;
}

class CheckOut : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckOut(QWidget *parent = nullptr);
    ~CheckOut();

private slots:
    void on_f_yes_clicked();

    void on_radioButton_2_clicked();

    void on_CreditCard_clicked();

    void on_Cash_clicked();

    void on_addFeedBack_clicked();

private:
    Ui::CheckOut *ui;
};

#endif // CHECKOUT_H
