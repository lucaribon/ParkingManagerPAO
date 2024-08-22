#include "sensorAir.h"

SensorAir::SensorAir(float af, int m){
    airflow = af;
    measurementValue = m;
}

float SensorAir::getAirflow(){
    return airflow;
}

int SensorAir::getMesurement(){
    return measurementValue;
}

void SensorAir::setAirflow(float af){
    airflow = af;
}

void SensorAir::setMesurement(int m){
    measurementValue = m;
}
