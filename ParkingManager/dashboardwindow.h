#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QWidget>
#include <QLabel>

#include "sensorbar.h"

class DashboardWindow : public QWidget
{
    Q_OBJECT
private:
    QLabel* tempTxt;
    SensorBar* sensorBar;
public:
    DashboardWindow(QWidget* parent = 0);
    void show();
};

#endif // DASHBOARDWINDOW_H
