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

private:
    std::set<std::string> areas;
    std::list<std::string> sensors; //DA CAMBIARE CON SENSOR
    QListWidget *listAreas;
signals:
};

#endif // SENSOREDITOR_H
