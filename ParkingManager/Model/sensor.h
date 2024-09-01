#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <QUuid>
#include <QString>

#include "ISensorVisitor.h"
#include "IConstSensorVisitor.h"

class Sensor {
private:
    std::string name;
    std::string area;
    std::string id;
protected:
    Sensor(std::string, std::string, std::string="");
    virtual void generateSimulationData()=0;
public:
    virtual ~Sensor() =default;
    std::string getName() const;
    std::string getArea() const;
    std::string getId() const;

    void setName(std::string);
    void setArea(std::string);
    void setId(std::string );

    virtual void accept(ISensorVisitor*) =0;
    virtual void accept(IConstSensorVisitor*) const =0;
};
#endif // SENSOR_H
