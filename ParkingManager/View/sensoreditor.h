#ifndef SENSOREDITOR_H
#define SENSOREDITOR_H

#include <QListWidget>
#include <QWidget>
#include "../Controller/controller.h"

class SensorEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SensorEditor(Controller *con, QWidget *parent = nullptr);

    void createPark();
    void refreshAreas(QListWidget *listAreas);
    void refreshSensors(QListWidget *listSensors, const std::vector<Sensor *> &sensors);
    void removeArea(const QString &area);
    void removeSensor(const int pos);
    void pushAreaName(const QString &name);
    void pushSensor(const QString name, const QString sensorType, const QString area);
    void addAreaDialog();
    void addSensorDialog();
    void editSensorDialog(Sensor *sensor);
    void editSensor(Sensor *sensor,
                    const QString &name,
                    const QString &area,
                    const QString &sensorType);

private:
    Controller *controller;
    QListWidget *listAreas;
    QListWidget *listSensors;

signals:
    void parkingCreated();
};

#endif // SENSOREDITOR_H
