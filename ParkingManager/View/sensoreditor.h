#ifndef SENSOREDITOR_H
#define SENSOREDITOR_H

#include <QListWidget>
#include <QWidget>
#include "../Controller/controller.h"

class SensorEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SensorEditor(Controller *con, QWidget *parent = nullptr);

    void refreshAreas(QListWidget *listAreas);
    void createPark();
    void removeArea(const QString &area);
    void pushAreaName(const QString &name);
    void addAreaDialog();

private:
    Controller *controller;
    QListWidget *listAreas;

signals:
    void parkingCreated();
};

#endif // SENSOREDITOR_H
