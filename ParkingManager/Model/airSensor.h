#ifndef AIRSENSOR_H
#define AIRSENSOR_H

#include "sensor.h"
#include <map>

class AirSensor : public Sensor{
private:
protected:
    /* registra i metri cubi di aria all'ora,
     * nel nostro caso l'idea è che ci sia un
     * flusso d'aria di +-1(m^3)/h (0.9-1.1)
     * costante che viene usato dai sensori per
     * compiere le misurazioni */
    std::map<time_t, float> airflow;
    // map<dataora, vector<elemento1,elemento2,elemento3,elemento4>>
    std::map<time_t, std::vector<float>> values;
    /* converte m^3 di aria in grammi */
    float airFlowToAirMass(float);
    AirSensor(std::string n, std::string a);
public:
    virtual ~AirSensor() =0;
    std::map<time_t, float> getAirflow() const;
    std::map<time_t, std::vector<float>> getValues() const;

    void setAirflow(std::map<time_t, float>);
    void setValues(std::map<time_t, std::vector<float>>);

    virtual int getAirStatus(time_t) =0;
};

#endif // AIRSENSOR_H
