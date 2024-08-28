#include "airQualitySensor.h"

AirQualitySensor::AirQualitySensor(std::string n, std::string a) : AirSensor(n,a), no2(0), o3(0), pm10(0), pm25(0){}

float AirQualitySensor::getNo2() const{return no2;}
float AirQualitySensor::getO3() const{return o3;}
float AirQualitySensor::getPm10() const{return pm10;}
float AirQualitySensor::getPm25() const{return pm25;}

void AirQualitySensor::setNo2(float val){no2 = val;}
void AirQualitySensor::setO3(float val){o3 = val;}
void AirQualitySensor::setPm10(float val){pm10 = val;}
void AirQualitySensor::setPm25(float val){pm25 = val;}

// ritorna un int che rappresenta la qualità dell'aria su 5 livelli (lower is better)
int AirQualitySensor::getAirStatus() {
    if(no2>400 || o3>240 || pm10>180 || pm25>110){
        return 5; // very high
    }else if((no2>=200&&no2<=400) ||
               (o3>=180&&o3<=240) ||
               (pm10>=90&&pm10<=180) ||
               (pm25>=55&&pm25<=110)){
        return 4; // high
    }else if((no2>=100&&no2<=200) ||
               (o3>=120&&o3<=180) ||
               (pm10>=50&&pm10<=90) ||
               (pm25>=30&&pm25<=55)){
        return 3; // medium
    }else if((no2>=50&&no2<=100) ||
               (o3>=60&&o3<=120) ||
               (pm10>=25&&pm10<=50) ||
               (pm25>=15&&pm25<=30)){
        return 2; // low
    }else if((no2>=0&&no2<=50) ||
               (o3>=0&&o3<=60) ||
               (pm10>=0&&pm10<=25) ||
               (pm25>=0&&pm25<=15)){
        return 1; // very low
    }
    return 0;
}
