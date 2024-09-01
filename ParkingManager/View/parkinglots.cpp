#include "parkinglots.h"
#include <QGridLayout>

ParkingLots::ParkingLots(QWidget *parent, std::string area, int numSlot)
    : QFrame{parent}
{
    //TEMP PARAMETERS
    int numSlotForColumn;
    if (numSlot % 2 == 0) {
        numSlotForColumn = numSlot / 2;
    } else {
        numSlotForColumn = (numSlot / 2) + 1;
    }

    QFrame *framePark = new QFrame();
    framePark->setObjectName("framePark");

    QVBoxLayout *vertLayout = new QVBoxLayout(this);

    QGridLayout *gridLayout = new QGridLayout(framePark);
    gridLayout->setSpacing(4);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    for (int i = 0; i < numSlot; i++) {
        parkingSlots.push_back(new ParkingSlot(this, i + 1, area));
        gridLayout->addWidget(parkingSlots[i], i % numSlotForColumn, i / numSlotForColumn);
    }
    areaId = new QLabel(QString::fromStdString("Area " + area));
    areaId->setAlignment(Qt::AlignCenter);

    vertLayout->setAlignment(Qt::AlignBottom);
    vertLayout->addWidget(framePark);
    vertLayout->addWidget(areaId);

    setLayout(vertLayout);
}
