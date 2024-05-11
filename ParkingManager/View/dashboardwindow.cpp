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

    QWidget* parkSpace = new QWidget();
    QHBoxLayout* parkLayout = new QHBoxLayout(parkSpace);

    ParkingLots* park = new ParkingLots(this, "A", 20);
    ParkingLots* park1 = new ParkingLots(this, "B", 10);
    ParkingLots* park2 = new ParkingLots(this, "C", 12);

    parkLayout->addWidget(park);
    parkLayout->addWidget(park1);
    parkLayout->addWidget(park2);
    parkLayout->setAlignment(Qt::AlignBottom);

    layout->addWidget(sensorBar);
    layout->addWidget(parkSpace);

    setLayout(layout);
}

void DashboardWindow::show(){

}
