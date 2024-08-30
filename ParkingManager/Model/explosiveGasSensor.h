#ifndef EXPLOSIVEGASSENSOR_H
#define EXPLOSIVEGASSENSOR_H

#include "airSensor.h"

class ExplosiveGasSensor : public AirSensor{
private:
    float methane; // pericolo esplosione > 5%
    float propane; // pericolo esplosione > 2%
    float benzene; // pericolo esplosione > 1.2%
    float hydrogen; // pericolo esplosione > 4%
protected:
    ExplosiveGasSensor(std::string, std::string);
public:
    virtual ~ExplosiveGasSensor() =default;

    float getMethane() const;
    float getPropane() const;
    float getBenzene() const;
    float getHydrogen() const;

    void setMethane(float);
    void setPropane(float);
    void setBenzene(float);
    void setHydrogen(float);

    /* ritorna il livello di pericolosità dato
     * dalla presenza di gas potenzialmente
     * esplosivi man mano che ci si avvicina o
     * supera la soglia minima di pericolosità;
     * la soglia viene calcolata basandosi
     * sull'aria totale analizzata dal sensore
     * (sensor::airflow) e solle quantità dei
     * vari gas misurati da questo sensore
     * (lowerIsBetter) */
    int getAirStatus();
};

#endif // EXPLOSIVEGASSENSOR_H
