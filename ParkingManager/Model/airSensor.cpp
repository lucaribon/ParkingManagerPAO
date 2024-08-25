#include "airSensor.h"

AirSensor::AirSensor(std::string n, std::string a){
    name = n;
    area = a;
    id = QUuid::createUuid().toString();
}

float AirSensor::getAirflow() const{return airflow;}
int AirSensor::getMesurement() const{return measurementValue;}

void AirSensor::setAirflow(float af){airflow = af;}
void AirSensor::setMesurement(int m){measurementValue = m;}
