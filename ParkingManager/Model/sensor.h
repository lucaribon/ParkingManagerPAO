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
    // per il momento per rendere la classe virtuale usiamo il costruttore
    // come metodo puro e lo ridefiniamo fuori
    virtual ~Sensor()=0;

    std::string getName() const;
    std::string getArea() const;
    QUuid getId() const;

    void setName(std::string);
    void setArea(std::string);
    // probabilmente ha più senso definire l'id in costruzione e non poterlo più modificare
    // void setId();
};

Sensor::~Sensor(){}

#endif // SENSOR_H
