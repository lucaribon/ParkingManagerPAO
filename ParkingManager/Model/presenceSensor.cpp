#include "presenceSensor.h"
#include <random>
#include <functional>

PresenceSensor::PresenceSensor(std::string n, std::string a) : Sensor(n,a) {}
PresenceSensor::~PresenceSensor() =default;

std::map<time_t,bool> PresenceSensor::getParkingLotsPresence() const {return parkingLotsPresence;}

void PresenceSensor::setParkingLotsPresence(std::map<time_t,bool> p) {
    for(auto &i : p) {
        parkingLotsPresence[i.first] = i.second;
    }
}

void PresenceSensor::generateSimulationData(){
    time_t init = time(0);
    tm* date = localtime(&init); // now
    date->tm_mday -= 7; // a week ago

    // random booleans generator
    auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());

    for(int i=0; i<7; i++) {
        for(int j=0; j<24; j++){
            time_t tempT = mktime(date);

            bool tempVal = gen();
            parkingLotsPresence[tempT] = tempVal;

            date->tm_hour += 1;
        }
        date->tm_mday += 1;
    }
}
