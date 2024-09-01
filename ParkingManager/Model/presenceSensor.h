#ifndef PRESENCESENSOR_H
#define PRESENCESENSOR_H

#include "sensor.h"
#include <map>

class PresenceSensor : public Sensor{
private:
    std::map<time_t,bool> parkingLotsPresence;
public:
    PresenceSensor(std::string, std::string, std::string="");
    virtual ~PresenceSensor();

    std::map<time_t,bool> getParkingLotsPresence() const;

    void setParkingLotsPresence(std::map<time_t,bool>);

    virtual void generateSimulationData() override;

    virtual void accept(ISensorVisitor*) override;
    virtual void accept(IConstSensorVisitor*) const override;
};


#endif // PRESENCESENSOR_H
