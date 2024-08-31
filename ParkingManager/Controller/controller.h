#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <set>
#include <vector>

#include "../Model/sensor.h"

class Controller : public QObject
{
private:
    std::vector<Sensor *> sensors;
    std::set<std::string> areas;
    QObject* parent;
    std::string path;
public:
    explicit Controller(QObject* =nullptr);

    std::set<std::string> getAreas();
    std::vector<Sensor *> getSensors();

    void setSensors(std::vector<Sensor *>);
    void setAreas(std::set<std::string>);

    void addSensor(Sensor *);
    void addArea(std::string);

    void removeSensor(Sensor *);
    void removeArea(std::string);

    void searchSensor(const std::string);
signals:
};

#endif // CONTROLLER_H
