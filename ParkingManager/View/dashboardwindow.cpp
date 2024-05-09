#include "dashboardwindow.h"
#include <QFrame>
#include <QLabel>
#include <QList>
#include <QVBoxLayout>
#include "parkinglots.h"

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    sensorBar = new SensorBar();
    sensorBar->setObjectName("sensorBar");
    //sensorBar->setStyleSheet("background: pink;");
    //this->setObjectName("sensorBar");

    //TEST
    //QWidget* park = new QWidget();
    //QHBoxLayout* parkLayout = new QHBoxLayout(park);
    //parkLayout->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    //parkLayout->setSpacing(0);
    //parkLayout->setContentsMargins(0, 0, 0, 0);

    //ParkingSlot* parkingSlot = new ParkingSlot();
    //ParkingSlot* parkingSlot1 = new ParkingSlot(this, true);
    //ParkingSlot* parkingSlot2 = new ParkingSlot();
    //parkLayout->addWidget(parkingSlot);
    //parkLayout->addWidget(parkingSlot1);
    //parkLayout->addWidget(parkingSlot2);

    QWidget* parkSpace = new QWidget();
    QHBoxLayout* parkLayout = new QHBoxLayout(parkSpace);

    ParkingLots* park = new ParkingLots(this, "A");
    ParkingLots* park1 = new ParkingLots(this, "B");
    ParkingLots* park2 = new ParkingLots(this, "C");

    parkLayout->addWidget(park);
    parkLayout->addWidget(park1);
    parkLayout->addWidget(park2);

    layout->addWidget(sensorBar);
    layout->addWidget(parkSpace);

    setLayout(layout);

    //QFrame* temp = new QFrame();
    //temp->setFixedWidth(1000);
    //temp->setStyleSheet("background: blue;");
    //layout->addWidget(temp);
}

void DashboardWindow::show(){

}
