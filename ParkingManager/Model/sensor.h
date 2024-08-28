#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <list>
#include <QUuid>
#include <QString>

class Sensor {
private:
    std::string name;
    std::string area;
    QString id;
protected:
    Sensor(std::string, std::string);
    // meglio una lista perché alla fine una volta generati di dati saranno inseriti alla fine e basta, e poi per usarli nei grafici l'accesso sarà sequenziale
    virtual std::list<float> generateData()=0;
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
