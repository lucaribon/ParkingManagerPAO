#include "tempHumSensor.h"

TempHumSensor::TempHumSensor(std::string n, std::string a) : Sensor(n,a) {}
TempHumSensor::~TempHumSensor() =default;

std::map<time_t,std::vector<float>> TempHumSensor::getTempHum() const {return tempHum;}

void TempHumSensor::setTempHum(std::map<time_t,std::vector<float>> th) {
    for(auto &i : th) {
        std::vector<float> tempHumToInsert;

        for(auto &s : i.second){
            tempHumToInsert.push_back(s);
        }

        tempHum[i.first] = tempHumToInsert;
    }
}

void TempHumSensor::generateSimulationData(){
    time_t init = time(0);
    tm* date = localtime(&init); // now
    date->tm_mday -= 7; // a week ago

    for(int i=0; i<7; i++) {
        for(int j=0; j<24; j++){
            time_t tempT = mktime(date);

            std::vector<float> tempVal;
            tempVal[0] = 18 + (float)((std::rand()) / (40 - 18 + 1));
            tempVal[1] = 40 + (float)((std::rand()) / (70 - 40 + 1));
            tempHum[tempT] = tempVal;

            date->tm_hour += 1;
        }
        date->tm_mday += 1;
    }
}
