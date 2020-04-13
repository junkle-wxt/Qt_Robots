#include "mainwindow.h"
#include"mainui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainUI w;
    w.show();
   //woshinidie
    return a.exec();
}
