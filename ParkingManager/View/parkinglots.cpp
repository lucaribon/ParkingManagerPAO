#include "parkinglots.h"
#include <QGridLayout>

ParkingLots::ParkingLots(QWidget *parent, std::string area)
    : QWidget{parent}
{
    //areaId = new QLabel("Area 1");
    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(4);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    for (int i = 0; i < 20; i++) {
        parkingSlots.push_back(new ParkingSlot(this, i + 1, area));
        layout->addWidget(parkingSlots[i], i % 10, i / 10);
    }
}
