#ifndef SENSOREDITOR_H
#define SENSOREDITOR_H

#include <QListWidget>
#include <QWidget>
#include "../Controller/controller.h"
#include "../Model/sensor.h"

class SensorEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SensorEditor(Controller *con, QWidget *parent = nullptr);

    void createPark();
    void refreshAreas(QListWidget *listAreas);
    void removeArea(const QString &area);
    void pushAreaName(const QString &name);
    void addAreaDialog();
    void addSensorDialog();
    void pushSensor(const QString &area, const Sensor &sensor);

private:
    Controller *controller;
    QListWidget *listAreas;
    QListWidget *listSensors;

signals:
    void parkingCreated();
};

#endif // SENSOREDITOR_H
