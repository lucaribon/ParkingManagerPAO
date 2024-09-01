#include "sensor.h"

Sensor::Sensor(std::string n, std::string a, std::string i) : name(n), area(a), id( i!="" ? i : (QUuid::createUuid().toString()).toStdString()) {}

std::string Sensor::getName() const{return name;}
std::string Sensor::getArea() const{return area;}
std::string Sensor::getId() const{return id;}

void Sensor::setName(std::string n){name = n;}
void Sensor::setArea(std::string a){area = a;}
