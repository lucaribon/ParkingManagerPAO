#include "parkingpage.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include "../Model/airQualitySensor.h"
#include "../Model/explosiveGasSensor.h"
#include "../Model/inOutSensor.h"
#include "../Model/lightSensor.h"
#include "../Model/presenceSensor.h"
#include "../Model/tempHumSensor.h"
#include "parkinglots.h"
#include "sensoreditordialog.h"
#include "sensorinfo.h"

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
    //save button
    QPushButton* saveButton = new QPushButton(QIcon(":/assets/icons/save-file.svg"), "Save");
    //saveButton->setFixedSize(35, 35);

    QPushButton* editButton = new QPushButton(QIcon(":/assets/icons/edit.svg"), "Edit");
    //editButton->setFixedSize(35, 35);

    QPushButton* generateButton = new QPushButton(QIcon(":/assets/icons/player-play.svg"),
                                                  "Generate");
    //generateButton->setFixedSize(35, 35);

    connect(editButton, &QPushButton::clicked, this, &ParkingPage::editMode);
    connect(saveButton, &QPushButton::clicked, this, &ParkingPage::saveFile);

    layoutTopBar->addWidget(saveButton);
    layoutTopBar->addWidget(editButton);
    layoutTopBar->addWidget(generateButton);

    // PARCHEGGIO
    QFrame* parkSpace = new QFrame();
    QHBoxLayout* parkLayout = new QHBoxLayout(parkSpace);

    //get areas from controller
    for (const std::string& area : controller->getAreas()) {
        QWidget* areaSpace = new QWidget();
        QVBoxLayout* areaLayout = new QVBoxLayout(areaSpace);
        //count sensor presence
        int parkingCount = 0;
        for (Sensor* sensor : controller->getSensors()) {
            if (sensor->getArea() == area) {
                //add sensor to parking area
                if (dynamic_cast<PresenceSensor*>(sensor)) {
                    parkingCount++;
                } else if (dynamic_cast<LightSensor*>(sensor)) {
                    LightSensor* light = dynamic_cast<LightSensor*>(sensor);
                    QString brightness = QString::fromStdString(
                        std::to_string(light->getBrightness().end()->second));
                    SensorInfo* sensorInfo = new SensorInfo(new QLabel(QString::fromStdString(
                                                                sensor->getName())),
                                                            new QLabel(brightness),
                                                            this);
                    areaLayout->addWidget(sensorInfo);
                } else if (dynamic_cast<InOutSensor*>(sensor)) {
                    InOutSensor* inOutSens = dynamic_cast<InOutSensor*>(sensor);
                    QString inOut = QString::fromStdString(
                        "IN: " + std::to_string(inOutSens->getInOut().end()->second.at(0))
                        + " OUT: " + std::to_string(inOutSens->getInOut().end()->second.at(1)));
                    SensorInfo* sensorInfo = new SensorInfo(new QLabel(QString::fromStdString(
                                                                sensor->getName())),
                                                            new QLabel(inOut),
                                                            this);
                    areaLayout->addWidget(sensorInfo);
                } else if (dynamic_cast<AirQualitySensor*>(sensor)) {
                    AirQualitySensor* air = dynamic_cast<AirQualitySensor*>(sensor);
                    QString airQuality = QString::fromStdString(
                        //ctime per to string in caso
                        std::to_string(air->getAirStatus(air->getValues().end()->first)));
                    SensorInfo* sensorInfo = new SensorInfo(new QLabel(QString::fromStdString(
                                                                sensor->getName())),
                                                            new QLabel(airQuality),
                                                            this);
                    areaLayout->addWidget(sensorInfo);
                } else if (dynamic_cast<ExplosiveGasSensor*>(sensor)) {
                    ExplosiveGasSensor* gas = dynamic_cast<ExplosiveGasSensor*>(sensor);
                    QString gasLevel = QString::fromStdString(
                        std::to_string(gas->getAirStatus(gas->getValues().end()->first)));
                    SensorInfo* sensorInfo = new SensorInfo(new QLabel(QString::fromStdString(
                                                                sensor->getName())),
                                                            new QLabel(gasLevel),
                                                            this);
                    areaLayout->addWidget(sensorInfo);
                } else if (dynamic_cast<TempHumSensor*>(sensor)) {
                    TempHumSensor* temp = dynamic_cast<TempHumSensor*>(sensor);
                    QString temperature = QString::fromStdString(
                        std::to_string(temp->getTempHum().end()->second.at(0)) + "°C" + "\n"
                        + std::to_string(temp->getTempHum().end()->second.at(1)) + "%");
                    SensorInfo* sensorInfo = new SensorInfo(new QLabel(QString::fromStdString(
                                                                sensor->getName())),
                                                            new QLabel(temperature),
                                                            this);
                    areaLayout->addWidget(sensorInfo);
                }
            }
        }
        if (parkingCount > 0) {
            qDebug() << "Area: " << QString::fromStdString(area) << " - Sensors: " << parkingCount;
            parkingAreas.push_back(new ParkingLots(this, area, parkingCount));
            areaLayout->addWidget(parkingAreas.back());
        }
        parkLayout->addWidget(areaSpace);
    }

    parkLayout->setAlignment(Qt::AlignBottom | Qt::AlignCenter);

    // LAYOUT GENERALE
    layout->addWidget(topBar);
    layout->addWidget(parkSpace);

    setLayout(layout);
}

void ParkingPage::editMode(){
    qDebug() << "Edit mode activated!";
    SensorEditorDialog* sensorEditor = new SensorEditorDialog(controller, this);
    sensorEditor->exec();
}

void ParkingPage::saveFile(){
    qDebug() << "Saving file!";
    controller->setPath((QFileDialog::getSaveFileName(this, ("Crea nuovo file"), QDir::homePath(), "JSON Files (*.json)")).toStdString());
    controller->saveFile();
}
