#include "lightSensor.h"

LightSensor::LightSensor(std::string n, std::string a) : Sensor(n,a) {}
LightSensor::~LightSensor() =default;

std::map<time_t,int> LightSensor::getBrightness() const {return brightness;}

void LightSensor::setBrightness(std::map<time_t, int> b) {
    for(auto &i : b) {
        brightness[i.first] = i.second;
    }
}

bool LightSensor::lightsNeeded(time_t t){
    if(brightness[t] < 8000){
        return true;
    }
    return false;
}

void LightSensor::generateSimulationData(){}

