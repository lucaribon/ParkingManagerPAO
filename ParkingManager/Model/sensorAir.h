#ifndef SENSORAIR_H
#define SENSORAIR_H

#include <string>
#include <QUuid>

class SensorAir {
private:
    float airflow;
    int measurementValue;
protected:
    SensorAir(float, int);
public:
    float getAirflow();
    int getMesurement();

    void setAirflow(float);
    void setMesurement(int);
};

#endif // SENSORAIR_H
