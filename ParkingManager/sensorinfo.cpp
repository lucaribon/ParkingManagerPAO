#include "sensorinfo.h"

#include <QHBoxLayout>
#include <QPixmap>
#include <QFile>
#include <QDir>

SensorInfo::SensorInfo(QWidget* parent) : QWidget(parent){
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    icon = new QLabel();
    name = new QLabel();
    status = new QLabel();

    layout->addWidget(icon);
    layout->addWidget(name);
    layout->addWidget(status);
}

void SensorInfo::show(){
    QPixmap pixIcon(":/assets/icons/temperature.png");
    icon->setPixmap(pixIcon);

    name->setText("Temperature");

    status->setText("50 °C");
}
