#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "../Controller/controller.h"
#include "applogo.h"
#include "dashboardwindow.h"
#include "graphwindow.h"
#include "reportwindow.h"
#include "sidemenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    AppLogo* appLogo;
    SideMenu* sideMenu;
    QStackedWidget* contentWindow;
    DashboardWindow* dashWindow;
    GraphWindow* graphWindow;
    ReportWindow* reportWindow;

    Controller* controller;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
