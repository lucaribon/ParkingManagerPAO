#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QLabel>
#include <QStackedWidget>
#include <QWidget>

#include "../Controller/controller.h"

class DashboardWindow : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    QStackedWidget* contentWindow;

public:
    DashboardWindow(Controller* con, QWidget* parent = 0);

public slots:
    void setParkingPage();
};

#endif // DASHBOARDWINDOW_H
