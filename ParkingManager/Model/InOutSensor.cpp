#include "inOutSensor.h"

InOutSensor::InOutSensor(std::string n, std::string a) : Sensor(n,a) {}
InOutSensor::~InOutSensor() =default;

std::map<time_t,std::vector<int>> InOutSensor::getInOut() const {return inOut;}

void InOutSensor::setInOut(std::map<time_t,std::vector<int>> io) {
    for(auto &i : io) {
        std::vector<int> inOutToInsert;

        for(auto &s : i.second){
            inOutToInsert.push_back(s);
        }

        inOut[i.first] = inOutToInsert;
    }
}

void InOutSensor::generateSimulationData() {}


