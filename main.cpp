#include "View/loginscreen.h"
#include "Control/hotelSystem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Reservable_Init();
    QApplication a(argc, argv);
    LoginScreen w;
    w.setWindowTitle("Hotel Mangement System");
    w.show();
    return a.exec();
}
