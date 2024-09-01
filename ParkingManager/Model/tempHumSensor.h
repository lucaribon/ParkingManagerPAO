#ifndef TEMPHUMSENSOR_H
#define TEMPHUMSENSOR_H

#include "sensor.h"
#include <map>

class TempHumSensor : public Sensor {
private:
    std::map<time_t,std::vector<float>> tempHum;
public:
    TempHumSensor(std::string, std::string, std::string="");
    virtual ~TempHumSensor();

    std::map<time_t,std::vector<float>> getTempHum() const;

    void setTempHum(std::map<time_t,std::vector<float>>);

    virtual void generateSimulationData() override;

    virtual void accept(ISensorVisitor*) override;
    virtual void accept(IConstSensorVisitor*) const override;
};

#endif // TEMPHUMSENSOR_H
