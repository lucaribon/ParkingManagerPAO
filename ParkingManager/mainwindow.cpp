#include "mainwindow.h"
#include "sensorbar.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SensorBar* sensorbar = new SensorBar();
    //sensorbar->setStyleSheet("background-color: red;");
    setCentralWidget(sensorbar);
}

MainWindow::~MainWindow() {}
