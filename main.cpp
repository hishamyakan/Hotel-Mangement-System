#include "View/loginscreen.h"
#include "Control/hotelSystem.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QFile>

using namespace std;

#include <QApplication>

int main(int argc, char *argv[])
{


    Reservable_Init();
    QApplication a(argc, argv);

    QFile styleSheetFile("E://GitHub//Hotel-Mangement-System//Irrorater.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString ss = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(ss);

    LoginScreen w;
    w.setWindowTitle("Hotel Mangement System");
    w.show();

    return a.exec();
}
