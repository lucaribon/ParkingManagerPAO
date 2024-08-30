#ifndef EXPLOSIVEGASSENSOR_H
#define EXPLOSIVEGASSENSOR_H

#include "airSensor.h"

class GasSensor : public AirSensor{
private:
    float methane; // pericolo esplosione > 5%
    float propane; // pericolo esplosione > 2%
    float benzene; // pericolo esplosione > 1.2%
    float hydrogen; // pericolo esplosione > 4%
protected:
    GasSensor(std::string, std::string);
public:
    virtual ~GasSensor() =default;
    float getNo2() const;

    void setNo2(float);
}

#endif // EXPLOSIVEGASSENSOR_H
