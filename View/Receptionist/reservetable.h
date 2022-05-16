#ifndef RESERVETABLE_H
#define RESERVETABLE_H

#include <QMainWindow>

namespace Ui {
class ReserveTable;
}

class ReserveTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReserveTable(QWidget *parent = nullptr);
    ~ReserveTable();

private slots:
    void on_Reserve_clicked();

private:
    Ui::ReserveTable *ui;
};

#endif // RESERVETABLE_H
