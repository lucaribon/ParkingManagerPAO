#include "dashboardwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    sensorBar = new SensorBar();
    sensorBar->setObjectName("sensorBar");
    //sensorBar->setStyleSheet("background: pink;");
    //this->setObjectName("sensorBar");

    layout->addWidget(sensorBar);

    setLayout(layout);

    //QFrame* temp = new QFrame();
    //temp->setFixedWidth(1000);
    //temp->setStyleSheet("background: blue;");
    //layout->addWidget(temp);
}

void DashboardWindow::show(){

}
