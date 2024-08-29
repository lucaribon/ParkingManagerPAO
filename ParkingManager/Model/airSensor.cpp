#include "airSensor.h"

AirSensor::AirSensor(std::string n, std::string a) : Sensor(n,a), airflow(0) {}

float AirSensor::getAirflow() const{return airflow;}

void AirSensor::setAirflow(float af){airflow = af;}
