#ifndef HR_H
#define HR_H

#include <QMainWindow>

namespace Ui {
class HR;
}

class HR : public QMainWindow
{
    Q_OBJECT

public:
    explicit HR(QWidget *parent = nullptr, int caller = 0);
    ~HR();

private slots:
    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_cellClicked(int row, int column);

    void on_Update_clicked();

    void on_AddNewEmp_clicked();

    void on_Delete_clicked();

    void on_Sort_clicked();

    void on_LogOut_clicked();

    void on_Clear_clicked();

private:
    Ui::HR *ui;
};

#endif // HR_H
