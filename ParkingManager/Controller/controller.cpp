#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "controller.h"

Controller::Controller(QObject* p) : parent(p) {
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
    jUtil->updateSensorsIntoJSON(sensors);
}

void Controller::setAreas(std::set<std::string> areas) {
    this->areas = areas;
}

void Controller::setPath(std::string path) {
    this->path = path;
    jUtil = new JSONutil(QString::fromStdString(path));
}

std::set<std::string> Controller::getAreas() {
    return areas;
}

std::vector<Sensor *> Controller::getSensors() {
    return sensors;
}

std::string Controller::getPath(){
    return path;
}

std::vector<Sensor*> Controller::searchSensor(const std::string query){
    std::vector<Sensor*> matchingSensors;
    if(!query.empty()){
        QRegularExpression queryExp("^" + QString::fromStdString(query));
        for(Sensor* sens : sensors){
            QRegularExpressionMatch match = queryExp.match(QString::fromStdString(sens->getName()),
                                                           Qt::CaseInsensitive);
            if(match.hasMatch()){
                matchingSensors.push_back(sens);
            }
        }
    }
    return matchingSensors;
}

void Controller::saveFile(){
    jUtil->updateSensorsIntoJSON(sensors);
}
