#ifndef ICONSTSENSORVISITOR_H
#define ICONSTSENSORVISITOR_H

class AirQualitySensor;
class ExplosiveGasSensor;
class InOutSensor;
class LightSensor;
class PresenceSensor;
class TempHumSensor;

class IConstSensorVisitor{
public:
    virtual void handle(const AirQualitySensor*) =0;
    virtual void handle(const ExplosiveGasSensor*) =0;
    virtual void handle(const InOutSensor*) =0;
    virtual void handle(const LightSensor*) =0;
    virtual void handle(const PresenceSensor*) =0;
    virtual void handle(const TempHumSensor*) =0;
};

#endif // ICONSTSENSORVISITOR_H
