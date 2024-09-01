#include "lightSensor.h"

LightSensor::LightSensor(std::string n, std::string a, std::string i) : Sensor(n,a, i!="" ? i : (QUuid::createUuid().toString()).toStdString()) {}
LightSensor::~LightSensor() =default;

std::map<time_t,int> LightSensor::getBrightness() const {return brightness;}

void LightSensor::setBrightness(std::map<time_t, int> b) {
    for(auto &i : b) {
        brightness[i.first] = i.second;
    }
}

bool LightSensor::lightsNeeded(time_t t){
    if(brightness[t] < 150){
        return true;
    }
    return false;
}

void LightSensor::generateSimulationData(){
    time_t init = time(0);
    tm* date = localtime(&init); // now
    date->tm_mday -= 7; // a week ago

    for(int i=0; i<7; i++) {
        for(int j=0; j<24; j++){
            time_t tempT = mktime(date);

            // nighttime birghtness
            if(date->tm_hour>=20 && date->tm_hour<=7){
                brightness[tempT] = 10 + (std::rand() % (250 - 10 + 1));
            }
            // daytime birghtness
            else if(date->tm_hour>7 && date->tm_hour<20){
                brightness[tempT] = 148 + (std::rand() % (100 - 148 + 1));
            }

            date->tm_hour += 1;
        }
        date->tm_mday += 1;
    }
}

void LightSensor::accept(ISensorVisitor* handler){
    handler->handle(this);
}

void LightSensor::accept(IConstSensorVisitor* handler) const {
    handler->handle(this);
}
