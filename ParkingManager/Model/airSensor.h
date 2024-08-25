#ifndef AIRSENSOR_H
#define AIRSENSOR_H

#include "sensor.h"
#include <string>
#include <QUuid>

class AirSensor : public Sensor{
private:
    float airflow;
    int measurementValue;
protected:
    AirSensor(std::string n, std::string a);
public:
    ~AirSensor()=0;

    float getAirflow() const;
    int getMesurement() const;

    void setAirflow(float);
    void setMesurement(int);
};

AirSensor::~AirSensor(){}


#endif // AIRSENSOR_H
