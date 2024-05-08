#include "dashboardwindow.h"
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include "parkingslot.h"

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    sensorBar = new SensorBar();
    sensorBar->setObjectName("sensorBar");
    //sensorBar->setStyleSheet("background: pink;");
    //this->setObjectName("sensorBar");

    //TEST
    QWidget* park = new QWidget();
    QHBoxLayout* parkLayout = new QHBoxLayout(park);
    parkLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    parkLayout->setSpacing(0);
    parkLayout->setContentsMargins(0, 0, 0, 0);
    ParkingSlot* parkingSlot = new ParkingSlot();
    parkingSlot->setFixedSize(60, 100);
    ParkingSlot* parkingSlot1 = new ParkingSlot();
    parkingSlot1->setFixedSize(60, 100);
    parkLayout->addWidget(parkingSlot);
    parkLayout->addWidget(parkingSlot1);

    layout->addWidget(sensorBar);
    layout->addWidget(park);

    setLayout(layout);

    //QFrame* temp = new QFrame();
    //temp->setFixedWidth(1000);
    //temp->setStyleSheet("background: blue;");
    //layout->addWidget(temp);
}

void DashboardWindow::show(){

}
