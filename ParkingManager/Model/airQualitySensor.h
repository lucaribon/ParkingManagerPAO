#ifndef AIRQUALITYSENSOR_H
#define AIRQUALITYSENSOR_H

#include "airSensor.h"

class AirQualitySensor : public AirSensor{
private:
    // inquinanti che servono per calcolare il CAQI europeo
    float no2;
    float o3;
    float pm10;
    float pm25;
protected:
    AirQualitySensor(float, int);
public:
    float getNo2() const;
    float getO3() const;
    float getPm10() const;
    float getPm25() const;

    void setNo2(float);
    void setO3(float);
    void setPm10(float);
    void setPm25(float);

    // TODO: funzione calculateCommonAirQualityIndex() con equazione
    // https://en.wikipedia.org/wiki/Air_quality_index#CAQI
    // https://en.wikipedia.org/wiki/Air_quality_index#Computing_the_AQI
    // https://www.pranaair.com/blog/what-is-air-quality-index-aqi-and-its-calculation/?srsltid=AfmBOorCFpO9mlQiufmMVOsH1ceK9zuq7FAna3rnzmfjY5zJzAFS0Rfx
    // Il valore dell'indice generico è dato dal valore peggiore
    // misurato per un singolo inquinante; quindi se tipo il pm10=25
    // pm2.5=50 no2=100, allora il valore dell'indice sarà 100=VeryHigh
};

#endif // AIRQUALITYSENSOR_H
