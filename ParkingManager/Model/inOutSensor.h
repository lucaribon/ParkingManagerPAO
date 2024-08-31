#ifndef INOUTSENSOR_H
#define INOUTSENSOR_H

#include "sensor.h"
#include <map>

class InOutSensor : public Sensor {
private:
    std::map<time_t,std::vector<int>> inOut;
public:
    InOutSensor(std::string,std::string);
    virtual ~InOutSensor();

    std::map<time_t,std::vector<int>> getInOut() const;

    void setInOut(std::map<time_t,std::vector<int>>);

    virtual void generateSimulationData() override;
};

#endif // INOUTSENSOR_H
