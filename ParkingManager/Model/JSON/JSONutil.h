#ifndef JSONUTIL_H
#define JSONUTIL_H

#include <QJsonDocument>

#include "../IConstSensorVisitor.h"
#include "../ISensorVisitor.h"
#include "../sensor.h"

class JSONutil : IConstSensorVisitor, ISensorVisitor {
private:
    QJsonDocument* document;
    QString path;
public:
    JSONutil(QString);
    virtual ~JSONutil() =default;

    QJsonDocument getDocument() const;
    QString getPath() const;

    void setDocument(QJsonDocument);
    void setPath(QString);

    virtual void handle(const AirQualitySensor*) override;
    virtual void handle(const ExplosiveGasSensor*) override;
    virtual void handle(const InOutSensor*) override;
    virtual void handle(const LightSensor*) override;
    virtual void handle(const PresenceSensor*) override;
    virtual void handle(const TempHumSensor*) override;
    std::vector<Sensor*> getSensorsFromJSON() const;
    void updateSensorsIntoJSON(std::vector<Sensor*>);
};

#endif // JSONUTIL_H
