#include "presenceSensor.h"

PresenceSensor::PresenceSensor(std::string n, std::string a) : Sensor(n,a) {}
PresenceSensor::~PresenceSensor() =default;

std::map<time_t,bool> PresenceSensor::getParkingLotsPresence() const {return parkingLotsPresence;}

void PresenceSensor::setParkingLotsPresence(std::map<time_t,bool> p) {
    for(auto &i : p) {
        parkingLotsPresence[i.first] = i.second;
    }
}

void PresenceSensor::generateSimulationData(){}
