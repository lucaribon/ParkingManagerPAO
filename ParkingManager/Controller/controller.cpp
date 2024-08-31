#include "controller.h"

Controller::Controller(QObject *parent) : QObject{parent} {
    sensors = std::vector<Sensor *>();
}

void Controller::addSensor(Sensor *sensor)
{
    sensors.push_back(sensor);
}

void Controller::removeSensor(Sensor *sensor) {
    sensors.erase(std::remove(sensors.begin(), sensors.end(), sensor), sensors.end());
}

void Controller::addArea(std::string area) {
    areas.insert(area);
}

void Controller::removeArea(std::string area) {
    areas.erase(area);
}

void Controller::setSensors(std::vector<Sensor *> sensors) {
    this->sensors = sensors;
}

void Controller::setAreas(std::set<std::string> areas) {
    this->areas = areas;
}

std::set<std::string> Controller::getAreas() {
    return areas;
}

std::vector<Sensor *> Controller::getSensors() {
    return sensors;
}
