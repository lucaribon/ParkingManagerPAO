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
    virtual ~AirSensor() =0;
    float getAirflow() const;

    void setAirflow(float);
};

#endif // AIRSENSOR_H
