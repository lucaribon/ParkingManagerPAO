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

void InOutSensor::generateSimulationData() {
    time_t init = time(0);
    tm* date = localtime(&init); // now
    date->tm_mday -= 7; // a week ago

    for(int i=0; i<7; i++) {
        for(int j=0; j<24; j++){
            time_t tempT = mktime(date);

            std::vector<int> tempInOut;
            tempInOut[0] = (std::rand() % (500 + 1));
            tempInOut[1] = (std::rand() % (500 + 1));
            inOut[tempT] = tempInOut;

            date->tm_hour += 1;
        }
        date->tm_mday += 1;
    }
}


