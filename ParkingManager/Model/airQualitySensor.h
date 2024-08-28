#ifndef AIRQUALITYSENSOR_H
#define AIRQUALITYSENSOR_H

#include "airSensor.h"

class AirQualitySensor : public AirSensor{
private:
    // inquinanti che servono per calcolare il CAQI europeo,
    // tutti misurati in μg/m3
    float no2;
    float o3;
    float pm10;
    float pm25;
protected:
    AirQualitySensor(std::string, std::string);
public:
    virtual ~AirQualitySensor() =default;
    float getNo2() const;
    float getO3() const;
    float getPm10() const;
    float getPm25() const;

    void setNo2(float);
    void setO3(float);
    void setPm10(float);
    void setPm25(float);

    /* Il valore dell'indice generico è dato dal valore peggiore
    misurato per un singolo inquinante; se, per esempio, il pm10=25=VeryLow
    pm2.5=50=Medium no2=500=VeryHigh, allora il valore dell'indice sarà VeryHigh
    Fonti:
    https://en.wikipedia.org/wiki/Air_quality_index#CAQI
    https://en.wikipedia.org/wiki/Air_quality_index#Computing_the_AQI
    https://www.pranaair.com/blog/what-is-air-quality-index-aqi-and-its-calculation/?srsltid=AfmBOorCFpO9mlQiufmMVOsH1ceK9zuq7FAna3rnzmfjY5zJzAFS0Rfx */
    virtual int getAirStatus();
};

#endif // AIRQUALITYSENSOR_H
