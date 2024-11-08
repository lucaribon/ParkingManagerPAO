#include "airQualitySensor.h"
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <ctime>

AirQualitySensor::AirQualitySensor(std::string n, std::string a, std::string i) : AirSensor(n,a, i!="" ? i : (QUuid::createUuid().toString()).toStdString()) {}
AirQualitySensor::~AirQualitySensor() =default;

int AirQualitySensor::getAirStatus(time_t t) {
    std::vector<float> valueI = values[t];
    float no2=valueI[0],
        o3=valueI[1],
        pm10=valueI[2],
        pm25=valueI[3];

    if(no2>400 || o3>240 || pm10>180 || pm25>110) {
        return 5; // very high danger
    }else if((no2>=200&&no2<=400) ||
               (o3>=180&&o3<=240) ||
               (pm10>=90&&pm10<=180) ||
               (pm25>=55&&pm25<=110)) {
        return 4; // high danger
    }else if((no2>=100&&no2<=200) ||
               (o3>=120&&o3<=180) ||
               (pm10>=50&&pm10<=90) ||
               (pm25>=30&&pm25<=55)) {
        return 3; // medium danger
    }else if((no2>=50&&no2<=100) ||
               (o3>=60&&o3<=120) ||
               (pm10>=25&&pm10<=50) ||
               (pm25>=15&&pm25<=30)) {
        return 2; // low danger
    }else if((no2>=0&&no2<=50) ||
               (o3>=0&&o3<=60) ||
               (pm10>=0&&pm10<=25) ||
               (pm25>=0&&pm25<=15)) {
        return 1; // very low danger
    }

    return 0;
}

void AirQualitySensor::generateSimulationData() {
    time_t init = time(0);
    tm* date = localtime(&init); // now
    date->tm_mday -= 7; // a week ago

    for(int i=0; i<7; i++) {
        for(int j=0; j<24; j++){
            time_t tempT = mktime(date);

            airflow[tempT] = (std::rand() / (double)RAND_MAX) * (1.1 - 0.9) + 0.9;

            std::vector<float> tempVal = std::vector<float>(4);
            tempVal[0] = (std::rand()) % (501);
            tempVal[1] = (std::rand()) % (301);
            tempVal[2] = (std::rand()) % (201);
            tempVal[3] = (std::rand()) % (161);
            values[tempT] = tempVal;

            date->tm_hour += 1;
        }
        date->tm_mday += 1;
    }
}

void AirQualitySensor::accept(ISensorVisitor * handler){
    handler->handle(this);
}

void AirQualitySensor::accept(IConstSensorVisitor * handler) const {
    handler->handle(this);
}

