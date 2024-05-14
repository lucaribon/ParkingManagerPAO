#include "parkingpage.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "parkinglots.h"
#include "sensorbar.h"

ParkingPage::ParkingPage(QWidget *parent)
    : QWidget{parent}
{
    //MAIN WINDOW *******
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // TOP BAR
    QFrame* topBar = new QFrame();
    QHBoxLayout* layoutTopBar = new QHBoxLayout(topBar);
    // BARRA SENSORI
    SensorBar* sensorBar = new SensorBar();
    sensorBar->setObjectName("sensorBar");
    QPushButton* editButton = new QPushButton(QIcon(":/assets/icons/edit.svg"), "");
    editButton->setFixedSize(35, 35);
    //connect(editButton, &QPushButton::clicked, this, &DashboardWindow::editMode);

    layoutTopBar->addWidget(sensorBar);
    layoutTopBar->addWidget(editButton);

    // PARCHEGGIO
    QWidget* parkSpace = new QWidget();
    QHBoxLayout* parkLayout = new QHBoxLayout(parkSpace);

    ParkingLots* park = new ParkingLots(this, "A", 20);
    ParkingLots* park1 = new ParkingLots(this, "B", 10);
    ParkingLots* park2 = new ParkingLots(this, "C", 12);

    parkLayout->addWidget(park);
    parkLayout->addWidget(park1);
    parkLayout->addWidget(park2);

    parkLayout->setAlignment(Qt::AlignBottom);

    // LAYOUT GENERALE
    layout->addWidget(topBar);
    layout->addWidget(parkSpace);

    setLayout(layout);
}
