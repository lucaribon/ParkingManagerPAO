#ifndef SENSORINFO_H
#define SENSORINFO_H

#include <QWidget>
#include <QLabel>
#include <QSvgWidget>

class SensorInfo : public QWidget
{
    Q_OBJECT
private:
    QSvgWidget* icon;
    QLabel* name;
    QLabel* value;
public:
    SensorInfo(QWidget* parent = 0);
    void show();
};

#endif // SENSORINFO_H
