#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon appIcon(":/assets/icons/parking-app-icon.svg");
    a.setWindowIcon(appIcon);
    MainWindow w;
    w.resize(900,600);
    w.show();
    return a.exec();
}
