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

private:
    Ui::updateDeleteRes *ui;
};

#endif // UPDATEDELETERES_H