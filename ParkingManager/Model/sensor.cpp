#include "sensor.h"

std::string Sensor::getName(){
    return name;
}

std::string Sensor::getArea(){
    return area;
}

QUuid Sensor::getId(){
    return id;
}

void Sensor::setName(std::string n){
    name = n;
}

void Sensor::setArea(std::string a){
    area = a;
}
