#include <QHBoxLayout>
#include <QPixmap>
#include <QWidget>

#include "sensorinfo.h"

SensorInfo::SensorInfo(QLabel *name, QLabel *value, QWidget *parent)
    : QWidget(parent)
    , name(name)
    , value(value)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->addWidget(name);
    layout->addWidget(value);
}
