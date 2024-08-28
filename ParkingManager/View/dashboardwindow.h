#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QLabel>
#include <QStackedWidget>
#include <QWidget>

#include "../Controller/controller.h"
#include "sensorbar.h"
#include "sensoreditordialog.h"

class DashboardWindow : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    SensorBar* sensorBar;
    QStackedWidget* contentWindow;
    SensorEditorDialog* editorDialog;

public:
    DashboardWindow(Controller* con, QWidget* parent = 0);

public slots:
    void setParkingPage();
};

#endif // DASHBOARDWINDOW_H
