#ifndef EXPLOSIVEGASSENSOR_H
#define EXPLOSIVEGASSENSOR_H

#include "airSensor.h"

class ExplosiveGasSensor : public AirSensor{
public:
    ExplosiveGasSensor(std::string, std::string);
    virtual ~ExplosiveGasSensor();

    /* ritorna il livello di pericolosità dato
     * dalla presenza di gas potenzialmente
     * esplosivi man mano che ci si avvicina o
     * supera la soglia minima di pericolosità;
     * la soglia viene calcolata basandosi
     * sull'aria totale analizzata dal sensore
     * (sensor::airflow) e solle quantità dei
     * vari gas misurati da questo sensore
     * (lowerIsBetter) */
    virtual int getAirStatus(time_t) override;
    virtual void generateSimulationData() override;
};

#endif // EXPLOSIVEGASSENSOR_H
