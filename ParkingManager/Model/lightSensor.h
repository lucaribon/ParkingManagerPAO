#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "sensor.h"
#include <map>

class LightSensor : public Sensor{
private:
    /* int = lux una buona illuminazione per un parcheggio, sopratutto se chiuso, è di 150 lux
     * quindi quando si arriva sotto a questo livello è preferito attivare l'impianto di
     * illuminazione; durante il giorno però, se il parcheggio è raggiunto dalla luce naturale
     * può arrivare 1000lux */
    std::map<time_t,int> brightness;
public:
    LightSensor(std::string, std::string, std::string="");
    virtual ~LightSensor();

    std::map<time_t,int> getBrightness() const;

    void setBrightness(std::map<time_t,int>);

    bool lightsNeeded(time_t);
    virtual void generateSimulationData() override;

    virtual void accept(ISensorVisitor*) override;
    virtual void accept(IConstSensorVisitor*) const override;
};

#endif // LIGHTSENSOR_H
