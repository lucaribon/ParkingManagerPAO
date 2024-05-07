#include "dashboardwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    tempTxt = new QLabel();
    tempTxt->setText("Dashboard");
    sensorBar = new SensorBar();
    layout->addWidget(tempTxt);
    layout->addWidget(sensorBar);

    QFrame* temp = new QFrame();
    temp->setFixedWidth(100);
    temp->setStyleSheet("background: blue;");
    layout->addWidget(temp);
}

void DashboardWindow::show(){

}
