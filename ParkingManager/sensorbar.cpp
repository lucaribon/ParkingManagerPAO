#include "sensorbar.h"
#include <QHBoxLayout>

SensorBar::SensorBar(QWidget* parent) : QWidget(parent){
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    temp = new SensorInfo(this);
    pres = new SensorInfo(this);

    temp->show();
    pres->show();
    layout->addWidget(temp);
    layout->addWidget(pres);
}

void SensorBar::refresh(){
    temp->show();
    pres->show();
}

