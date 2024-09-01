#ifndef SENSORINFO_H
#define SENSORINFO_H

#include <QWidget>
#include <QLabel>
#include <QSvgWidget>

class SensorInfo : public QWidget
{
    Q_OBJECT
private:
    QLabel* name;
    QLabel* value;
public:
    SensorInfo(QLabel* name, QLabel* value, QWidget* parent = nullptr);
};

#endif // SENSORINFO_H
