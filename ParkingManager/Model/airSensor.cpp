#include "airSensor.h"

// densità dell'aria in cm^3
#define AIR_DENSITY_CM3  0.0012;

AirSensor::AirSensor(std::string n, std::string a) : Sensor(n,a), airflow(1.0) {}

AirSensor::~AirSensor(){} // forse meglio =default;

float AirSensor::getAirflow() const {return airflow;}

void AirSensor::setAirflow(float af) {airflow = af;}

float AirSensor::airFlowToAirMass(float af){
    float afInC = af * 1000; // airflow in centimetri cubi
    return afInC * AIR_DENSITY_CM3;
}
