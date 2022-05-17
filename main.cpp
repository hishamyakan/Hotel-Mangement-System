#include "View/loginscreen.h"
#include "Control/hotelSystem.h"
#include <iostream>
#include <string>
#include <QMessageBox>

using namespace std;

#include <QApplication>

int main(int argc, char *argv[])
{


    Reservable_Init();
    QApplication a(argc, argv);
    LoginScreen w;
    w.setWindowTitle("Hotel Mangement System");
    w.show();
    cout<<"First time"<<endl;
    return a.exec();
}
