#ifndef JSONUTIL_H
#define JSONUTIL_H

#include <QJsonDocument>

#include "../IConstSensorVisitor.h"
#include "../ISensorVisitor.h"

class JSONutil : IConstSensorVisitor, ISensorVisitor {
private:
    QJsonDocument* document;
    std::string path;
public:
    JSONutil(std::string);
    virtual ~JSONutil() =default;

    QJsonDocument getDocument() const;
    std::string getPath() const;

    void setDocument(QJsonDocument);
    void setPath(std::string);

    virtual void handle(AirQualitySensor*) override;
    virtual void handle(EsplosiveGasSensor*) override;
    virtual void handle(InOutSensor*) override;
    virtual void handle(LightSensor*) override;
    virtual void handle(PresenceSensor*) override;
    virtual void handle(TempHumSensor*) override;
    std::vector<Sensor*> getSensorsFromJSON() const;
};

#endif // JSONUTIL_H
