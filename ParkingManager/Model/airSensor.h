#ifndef AIRSENSOR_H
#define AIRSENSOR_H

#include "sensor.h"
#include <string>
#include <QUuid>

class AirSensor : public Sensor{
private:
    float airflow;
public:
    AirSensor(std::string n, std::string a);
    virtual ~AirSensor() =default;
    float getAirflow() const;

    void setAirflow(float);

    virtual int getAirStatus() =0;
};

#endif // AIRSENSOR_H
