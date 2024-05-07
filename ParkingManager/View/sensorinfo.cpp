#include <QHBoxLayout>
#include <QPixmap>
#include <QWidget>

#include "sensorinfo.h"

SensorInfo::SensorInfo(QWidget* parent) : QWidget(parent){
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    icon = new QSvgWidget(":/assets/icons/temperature-mini.svg");
    name = new QLabel();
    value = new QLabel();

    layout->addWidget(icon);
    layout->addWidget(name);
    layout->addWidget(value);
}

void SensorInfo::show(){
    // QPixmap pixIcon(":/assets/icons/temperature-mini.svg");
    //icon->setAttribute(Qt.AA_UseHighDpiPixmaps, true);
    icon->setFixedSize(18,18);

    name->setText("Temperature");

    value->setText("50 °C");
}
