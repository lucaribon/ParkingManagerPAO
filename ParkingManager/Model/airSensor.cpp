#include "airSensor.h"

// densità dell'aria in cm^3
#define AIR_DENSITY_CM3  0.0012;

AirSensor::AirSensor(std::string n, std::string a, std::string i) : Sensor(n,a,  i!="" ? i :(QUuid::createUuid().toString()).toStdString()) {}
AirSensor::~AirSensor(){}

std::map<time_t, float> AirSensor::getAirflow() const {return airflow;}
std::map<time_t, std::vector<float>> AirSensor::getValues() const {return values;}

void AirSensor::setAirflow(std::map<time_t, float> af) {
    for(auto &i : af) {
        airflow[i.first] = i.second;
    }
}
void AirSensor::setValues(std::map<time_t, std::vector<float>> v) {
    for(auto &i : v) {
        std::vector<float> valuesToInsert;

        for(auto &s : i.second){
            valuesToInsert.push_back(s);
        }

        values[i.first] = valuesToInsert;
    }
}

float AirSensor::airFlowToAirMass(float af){
    float afInC = af * 1000; // airflow in centimetri cubi
    return afInC * AIR_DENSITY_CM3;
}
