#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sensorbar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    SensorBar* sensorBar;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

