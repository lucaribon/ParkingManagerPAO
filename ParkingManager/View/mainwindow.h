#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "sensorbar.h"
#include "sidemenu.h"
#include "dashboardwindow.h"
#include "graphwindow.h"
#include "reportwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    SensorBar* sensorBar;
    SideMenu* sideMenu;
    QStackedWidget* contentWindow;
    DashboardWindow* dashWindow;
    ReportWindow* reportWindow;
    GraphWindow* graphWindow;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

