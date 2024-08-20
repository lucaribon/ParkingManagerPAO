#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <QUuid>

class Sensor {
private:
    std::string name;
    std::string area;
    QUuid id;
protected:
    Sensor(std::string, std::string);
public:
    std::string getName();
    std::string getArea();
    QUuid getId();

    void setName(std::string);
    void setArea(std::string);
    // probabilmente ha più senso definire l'id in costruzione e non poterlo più modificare
    // void setId();
};

#endif // SENSOR_H
