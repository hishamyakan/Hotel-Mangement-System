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

private:
    Ui::ReserveRoom *ui;
};

#endif // RESERVEROOM_H
