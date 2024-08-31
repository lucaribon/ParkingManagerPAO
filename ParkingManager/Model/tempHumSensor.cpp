#include "tempHumSensor.h"

TempHumSensor::TempHumSensor(std::string n, std::string a) : Sensor(n,a) {}
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

void TempHumSensor::generateSimulationData() {}
