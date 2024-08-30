#ifndef AIRSENSOR_H
#define AIRSENSOR_H

#include "sensor.h"
#include <string>
#include <QUuid>

class AirSensor : public Sensor{
private:
    /* registra i metri cubi di aria al minuto,
     * nel nostro caso l'idea è che ci sia un
     * flusso d'aria di +-1(m^3)/h (0.9-1.1)
     * costante che viene usato dai sensori per
     * compierele misurazioni */
    float airflow;
protected:
    /* converte m^3 di aria in grammi */
    float airFlowToAirMass(float);
public:
    AirSensor(std::string n, std::string a);
    virtual ~AirSensor() =0;
    float getAirflow() const;

    void setAirflow(float);
};

#endif // AIRSENSOR_H
