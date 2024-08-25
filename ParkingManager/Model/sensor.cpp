#include "sensor.h"

Sensor::Sensor(std::string n, std::string a){
        name = n;
        area = a;
        id = QUuid::createUuid().toString();
}

std::string Sensor::getName() const{return name;}
std::string Sensor::getArea() const{return area;}
QUuid Sensor::getId() const{return id;}

void Sensor::setName(std::string n){name = n;}
void Sensor::setArea(std::string a){area = a;}
