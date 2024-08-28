#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../Model/sensor.h"
#include <set>
#include <vector>

class Controller : public QObject
{
    Q_OBJECT
private:
    std::vector<Sensor *> sensors;
    std::set<std::string> areas;

public:
    explicit Controller(QObject *parent = nullptr);

    void addSensor(Sensor *);
    void removeSensor(Sensor *);
    void addArea();
    void pushAreaName(const QString &area);
    void removeArea(const QString &area);
signals:
};

#endif // CONTROLLER_H
