#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    sensors = std::vector<Sensor *>();
}

void Controller::addSensor(Sensor *sensor)
{
    sensors.push_back(sensor);
}

void Controller::removeSensor(Sensor *sensor)
{
    sensors.erase(std::remove(sensors.begin(), sensors.end(), sensor), sensors.end());
}
