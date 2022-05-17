#ifndef UPDATEDELETERES_H
#define UPDATEDELETERES_H

#include <QMainWindow>

namespace Ui {
class updateDeleteRes;
}

class updateDeleteRes : public QMainWindow
{
    Q_OBJECT

public:
    explicit updateDeleteRes(QWidget *parent = nullptr);
    ~updateDeleteRes();

private slots:
    void on_GetReservationList_clicked();

    void on_Delete_clicked();

    void on_tableWidget_res_cellClicked(int row, int column);

private:
    Ui::updateDeleteRes *ui;
};

#endif // UPDATEDELETERES_H
