#include "loginscreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginScreen w;
    w.setWindowTitle("Hotel Mangement System");
    w.show();
    return a.exec();
}
