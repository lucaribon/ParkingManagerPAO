#ifndef SENSORBAR_H
#define SENSORBAR_H

#include <QWidget>
#include "sensorinfo.h"

class SensorBar : public QWidget
{
    Q_OBJECT
private:
    SensorInfo* temp;
    SensorInfo* pres;
public:
    SensorBar(QWidget* parent = 0);
    void refresh();
};

#endif // SENSORBAR_H
