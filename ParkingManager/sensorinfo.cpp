#include "sensorinfo.h"

#include <QHBoxLayout>
#include <QPixmap>
#include <QWidget>


SensorInfo::SensorInfo(QWidget* parent) : QWidget(parent){
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    icon = new QLabel();
    name = new QLabel();
    value = new QLabel();

    layout->addWidget(icon);
    layout->addWidget(name);
    layout->addWidget(value);
}

void SensorInfo::show(){
    QPixmap pixIcon(":/assets/icons/temperature-mini.svg");
    //icon->setAttribute(Qt.AA_UseHighDpiPixmaps, true);
    icon->setPixmap(pixIcon);

    name->setText("Temperature");

    value->setText("50 °C");
}
