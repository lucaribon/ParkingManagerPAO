#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <QUuid>
#include <QString>

class Sensor {
private:
    std::string name;
    std::string area;
    QString id;
protected:
    Sensor(std::string, std::string);
    virtual void generateSimulationData()=0;
public:
    virtual ~Sensor() =default;
    std::string getName() const;
    std::string getArea() const;
    QString getId() const;

    void setName(std::string);
    void setArea(std::string);
    void setId(QString);
};
#endif // SENSOR_H
