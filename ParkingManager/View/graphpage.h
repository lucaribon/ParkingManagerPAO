#ifndef GRAPHPAGE_H
#define GRAPHPAGE_H

#include <QChart>
#include <QWidget>
#include "../Model/IConstSensorVisitor.h"
#include "../Model/airQualitySensor.h"
#include "../Model/explosiveGasSensor.h"
#include "../Model/inOutSensor.h"
#include "../Model/lightSensor.h"
#include "../Model/sensor.h"
#include <list>

class GraphPage : public QWidget, public IConstSensorVisitor
{
    Q_OBJECT
private:
    std::list<QChart *> charts;

public:
    explicit GraphPage(Sensor *sen, QWidget *parent = nullptr);
    virtual ~GraphPage() = default;

    /*
    virtual void handle(const TempHumSensor *) override;
    virtual void handle(const AirQualitySensor *) override;
    virtual void handle(const ExplosiveGasSensor *) override;
    virtual void handle(const InOutSensor *) override;
    virtual void handle(const LightSensor *) override;
    virtual void handle(const PresenceSensor *) override;
    */
signals:
};

#endif // GRAPHPAGE_H
