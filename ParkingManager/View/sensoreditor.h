#ifndef SENSOREDITOR_H
#define SENSOREDITOR_H

#include <QListWidget>
#include <QWidget>
#include <set>

class SensorEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SensorEditor(QWidget *parent = nullptr);
    void addArea();
    void pushAreaName(const QString &area);
    void removeArea(const QString &area);
    void refreshAreas(QListWidget *listAreas);
    void createPark();

private:
    std::set<std::string> areas;
    std::list<std::string> sensors; //DA CAMBIARE CON SENSOR
    QListWidget *listAreas;

signals:
    void parkingCreated();
};

#endif // SENSOREDITOR_H
