#include "parkingpage.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "../Model/presenceSensor.h"
#include "parkinglots.h"
#include "sensoreditordialog.h"

ParkingPage::ParkingPage(Controller* con, QWidget* parent)
    : QWidget{parent}
    , controller(con)
{
    //this->editor = editor;
    //MAIN WINDOW *******
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // TOP BAR
    QFrame* topBar = new QFrame();
    QHBoxLayout* layoutTopBar = new QHBoxLayout(topBar);
    // BARRA SENSORI

    QPushButton* editButton = new QPushButton(QIcon(":/assets/icons/edit.svg"), "");
    editButton->setFixedSize(35, 35);

    connect(editButton, &QPushButton::clicked, this, &ParkingPage::editMode);

    layoutTopBar->addWidget(editButton);

    // PARCHEGGIO
    QWidget* parkSpace = new QWidget();
    QHBoxLayout* parkLayout = new QHBoxLayout(parkSpace);

    //get areas from controller
    for (const std::string& area : controller->getAreas()) {
        //count sensor presence
        int parkingCount = 0;
        for (Sensor* sensor : controller->getSensors()) {
            if (sensor->getArea() == area) {
                //add sensor to parking area
                if (dynamic_cast<PresenceSensor*>(sensor))
                    parkingCount++;
            }
        }
        qDebug() << "Area: " << QString::fromStdString(area) << " - Sensors: " << parkingCount;
        parkingAreas.push_back(new ParkingLots(this, area, parkingCount));
        parkLayout->addWidget(parkingAreas.back());
    }

    parkLayout->setAlignment(Qt::AlignBottom);

    // LAYOUT GENERALE
    layout->addWidget(topBar);
    layout->addWidget(parkSpace);

    setLayout(layout);
}

void ParkingPage::editMode()
{
    qDebug() << "Edit mode activated!";
    SensorEditorDialog* sensorEditor = new SensorEditorDialog(controller, this);
    sensorEditor->exec();
}
