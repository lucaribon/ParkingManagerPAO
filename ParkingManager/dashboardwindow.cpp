#include "dashboardwindow.h"
#include <QLabel>
#include <QVBoxLayout>

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    tempTxt = new QLabel();
    sensorBar = new SensorBar();
    layout->addWidget(tempTxt);
    layout->addWidget(sensorBar);
}

void DashboardWindow::show(){
    tempTxt->setText("dashboard");
}
