#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <set>
#include <vector>

#include "../Model/sensor.h"
#include "../Model/JSON/JSONutil.h"


enum sensType {AirQuality, ExplosiveGas, InOut, Light, Presence, TempHum};

class Controller : public QObject
{
private:
    std::vector<Sensor *> sensors;
    std::set<std::string> areas;
    QObject* parent;
    std::string path;
    JSONutil* jUtil;
public:
    explicit Controller(QObject* =nullptr);

    std::set<std::string> getAreas();
    std::vector<Sensor *> getSensors();
    std::string getPath();

    void setSensors(std::vector<Sensor *>);
    void setAreas(std::set<std::string>);
    void setPath(std::string);

    void addSensor(Sensor *);
    void addArea(std::string);

    void removeSensor(Sensor *);
    void removeArea(std::string);

    std::vector<Sensor*> searchSensor(const std::string);
    void generateSimulation();
signals:
};

#endif // CONTROLLER_H
