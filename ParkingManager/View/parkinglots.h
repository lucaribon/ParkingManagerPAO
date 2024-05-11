#ifndef PARKINGLOTS_H
#define PARKINGLOTS_H

#include <QLabel>
#include <QWidget>
#include "parkingslot.h"
#include <string>
#include <vector>

class ParkingLots : public QFrame
{
    Q_OBJECT
private:
    std::vector<ParkingSlot *> parkingSlots;
    QLabel *areaId;

public:
    explicit ParkingLots(QWidget *parent = nullptr, std::string area = " ", int numSlot = 10);

signals:
};

#endif // PARKINGLOTS_H
