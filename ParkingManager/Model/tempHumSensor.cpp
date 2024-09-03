#include "tempHumSensor.h"
#include <QtDebug>

TempHumSensor::TempHumSensor(std::string n, std::string a, std::string i) : Sensor(n,a, i!="" ? i : (QUuid::createUuid().toString()).toStdString()) {}
TempHumSensor::~TempHumSensor() =default;

std::map<time_t, std::vector<float>> TempHumSensor::getTempHum() const
{
    return tempHum;
}

void TempHumSensor::setTempHum(std::map<time_t, std::vector<float>> th)
{
    for (auto &i : th) {
        std::vector<float> tempHumToInsert;

        for (auto &s : i.second) {
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

            std::vector<float> tempVal = std::vector<float>(2);
            tempVal[0] = 18 + ((std::rand()) % (40 - 18 + 1));
            tempVal[1] = 40 + ((std::rand()) % (70 - 40 + 1));
            tempHum[tempT] = tempVal;

            date->tm_hour += 1;
        }
        date->tm_mday += 1;
    }
}

void TempHumSensor::accept(ISensorVisitor* handler){
    handler->handle(this);
}

void TempHumSensor::accept(IConstSensorVisitor* handler) const {
    handler->handle(this);
}
