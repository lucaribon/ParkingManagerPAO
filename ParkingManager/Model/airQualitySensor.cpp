#include "airQualitySensor.h"

AirQualitySensor::AirQualitySensor(std::string n, std::string a) : AirSensor(n,a) {}
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
    //TODO
}
