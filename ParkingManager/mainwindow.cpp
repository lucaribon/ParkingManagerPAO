#include "mainwindow.h"
#include "sensorbar.h"
#include "sidemenu.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(central);
    SideMenu* sidemenu = new SideMenu();
    SensorBar* sensorbar = new SensorBar();
    layout->addWidget(sidemenu);
    layout->addWidget(sensorbar);
    //sensorbar->setStyleSheet("background-color: red;");
    setCentralWidget(central);
    setWindowTitle("Parking Manager");
}

MainWindow::~MainWindow() {}
