#ifndef AIRQUALITYSENSOR_H
#define AIRQUALITYSENSOR_H

#include "airSensor.h"

class AirQualitySensor : public AirSensor{
public:
    AirQualitySensor(std::string, std::string);
    virtual ~AirQualitySensor();

    /* Ritorna un int che rappresenta la qualità dell'aria su 5 livelli (lower is better) in
     * un determinato istante time_t.
     * Il valore dell'indice generico è dato dal valore peggiore
     * misurato per un singolo inquinante; se, per esempio, il pm10=25=VeryLow
     * pm2.5=50=Medium no2=500=VeryHigh, allora il valore dell'indice sarà VeryHigh
     * Fonti:
     * https://en.wikipedia.org/wiki/Air_quality_index#CAQI
     * https://en.wikipedia.org/wiki/Air_quality_index#Computing_the_AQI
     * https://www.pranaair.com/blog/what-is-air-quality-index-aqi-and-its-calculation/?srsltid=AfmBOorCFpO9mlQiufmMVOsH1ceK9zuq7FAna3rnzmfjY5zJzAFS0Rfx */
    virtual int getAirStatus(time_t) override;
    virtual void generateSimulationData() override;
};

#endif // AIRQUALITYSENSOR_H
