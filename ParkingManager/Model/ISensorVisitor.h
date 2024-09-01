#ifndef ISENSORVISITOR_H
#define ISENSORVISITOR_H

class AirQualitySensor;
class EsplosiveGasSensor;
class InOutSensor;
class LightSensor;
class PresenceSensor;
class TempHumSensor;

class ISensorVisitor{
public:
    virtual void handle(AirQualitySensor*) =0;
    virtual void handle(EsplosiveGasSensor*) =0;
    virtual void handle(InOutSensor*) =0;
    virtual void handle(LightSensor*) =0;
    virtual void handle(PresenceSensor*) =0;
    virtual void handle(TempHumSensor*) =0;
};


#endif // ISENSORVISITOR_H
