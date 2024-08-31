#include "parkingpage.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "parkinglots.h"
#include "sensorbar.h"
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
    SensorBar* sensorBar = new SensorBar();
    sensorBar->setObjectName("sensorBar");
    QPushButton* editButton = new QPushButton(QIcon(":/assets/icons/edit.svg"), "");
    editButton->setFixedSize(35, 35);

    connect(editButton, &QPushButton::clicked, this, &ParkingPage::editMode);

    layoutTopBar->addWidget(sensorBar);
    layoutTopBar->addWidget(editButton);

    // PARCHEGGIO
    QWidget* parkSpace = new QWidget();
    QHBoxLayout* parkLayout = new QHBoxLayout(parkSpace);

    //get areas from controller
    for (const std::string& area : controller->getAreas()) {
        qDebug() << " MISERIA: " << QString::fromStdString(area);
        parkingAreas.push_back(new ParkingLots(this, area, 10));
        parkLayout->addWidget(parkingAreas.back());
    }

    for (ParkingLots* park : parkingAreas) {
        qDebug() << "PARKING LOTS: " << park;
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
