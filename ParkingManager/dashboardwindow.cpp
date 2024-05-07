#include "dashboardwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    tempTxt = new QLabel();
    tempTxt->setText("Dashboard");
    sensorBar = new SensorBar();
    layout->addWidget(tempTxt);
    layout->addWidget(sensorBar);

    setLayout(layout);
    //QFrame* temp = new QFrame();
    //temp->setFixedWidth(1000);
    //temp->setStyleSheet("background: blue;");
    //layout->addWidget(temp);

}

void DashboardWindow::show(){

}
