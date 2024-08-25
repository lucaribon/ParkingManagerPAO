#include "airQualitySensor.h"

AirQualitySensor::AirQualitySensor(std::string n, std::string a){
    name = n;
    area = a;
    id = QUuid::createUuid().toString();
}

float AirQualitySensor::getNo2() const{return no2;}
float AirQualitySensor::getO3() const{return o3;}
float AirQualitySensor::getPm10() const{return pm10;}
float AirQualitySensor::getPm25() const{return pm25;}

void AirQualitySensor::setNo2(float val){no2 = val;}
void AirQualitySensor::setO3(float val){o3 = val;}
void AirQualitySensor::setPm10(float val){pm10 = val;}
void AirQualitySensor::setPm25(float val){pm25 = val;}
