#ifndef SENSORINFO_H
#define SENSORINFO_H

#include <QWidget>
#include <QLabel>

class SensorInfo : public QWidget
{
    Q_OBJECT
private:
    QLabel* icon;
    QLabel* name;
    QLabel* status;
public:
    SensorInfo(QWidget* parent = 0);
    void show();
};

#endif // SENSORINFO_H
