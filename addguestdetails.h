#ifndef ADDGUESTDETAILS_H
#define ADDGUESTDETAILS_H

#include <QDialog>

namespace Ui {
class AddGuestDetails;
}

class AddGuestDetails : public QDialog
{
    Q_OBJECT

public:
    explicit AddGuestDetails(QWidget *parent = nullptr);
    ~AddGuestDetails();

private slots:
    void on_AddData_clicked();

private:
    Ui::AddGuestDetails *ui;
};

#endif // ADDGUESTDETAILS_H
