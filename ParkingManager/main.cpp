#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon appIcon(":/assets/icons/parking-app-icon.svg");
    a.setWindowIcon(appIcon);

    QFile styleFile( ":/style/style.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    a.setStyleSheet( style );

    MainWindow w;
    w.resize(900,600);
    w.show();
    return a.exec();
}
