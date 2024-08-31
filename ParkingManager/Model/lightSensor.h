#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "sensor.h"
#include <map>

class LightSensor : public Sensor{
private:
    std::map<time_t,int> brightness;
public:
    LightSensor(std::string, std::string);
    virtual ~LightSensor();

    std::map<time_t,int> getBrightness() const;

    void setBrightness(std::map<time_t,int>);

    bool lightsNeeded(time_t);
    virtual void generateSimulationData() override;
};

#endif // LIGHTSENSOR_H
