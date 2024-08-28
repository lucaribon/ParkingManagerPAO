#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QLabel>
#include <QStackedWidget>
#include <QWidget>

#include "sensorbar.h"
#include "sensoreditordialog.h"

class DashboardWindow : public QWidget
{
    Q_OBJECT
private:
    SensorBar* sensorBar;
    QStackedWidget* contentWindow;
    SensorEditorDialog* editorDialog;

public:
    DashboardWindow(QWidget* parent = 0);

public slots:
    void setParkingPage();
};

#endif // DASHBOARDWINDOW_H
