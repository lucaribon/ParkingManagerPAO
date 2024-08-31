#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../Model/sensor.h"
#include <set>
#include <vector>

class Controller : public QObject
{
    Q_OBJECT
private:
    std::vector<Sensor *> sensors;
    std::set<std::string> areas;
public:
    explicit Controller(QObject *parent = nullptr);

    void addSensor(std::string name, std::string area, std::string sensorType);
    void removeSensor(Sensor *);
    void addArea(std::string area);
    void removeArea(std::string area);
    void setSensors(std::vector<Sensor *>);
    void setAreas(std::set<std::string>);
    std::set<std::string> getAreas();
    std::vector<Sensor *> getSensors();
signals:
};

#endif // CONTROLLER_H
