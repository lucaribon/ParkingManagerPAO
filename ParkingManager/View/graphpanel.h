#ifndef GRAPHPANEL_H
#define GRAPHPANEL_H

#include "../Model/IConstSensorVisitor.h"

#include <QChart>
#include <QWidget>
#include "../Model/sensor.h"

class GraphPanel : public QWidget, public IConstSensorVisitor {
private:
    QChart* charts;

public:
    GraphPanel(Sensor*);
    ~GraphPanel();
};

#endif // GRAPHPANEL_H
