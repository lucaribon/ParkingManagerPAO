#ifndef PARKINGPAGE_H
#define PARKINGPAGE_H

#include <QWidget>
#include "../Controller/controller.h"
#include "parkinglots.h"
#include <vector>

class ParkingPage : public QWidget
{
    Q_OBJECT
private:
    //SensorEditorDialog *editor;
    Controller *controller;
    std::vector<ParkingLots *> parkingAreas;

public:
    explicit ParkingPage(Controller *con, QWidget *parent = nullptr);
    void editMode();

signals:
};

#endif // PARKINGPAGE_H
