#ifndef GRAPHPANEL_H
#define GRAPHPANEL_H

#include "../Model/IConstSensorVisitor.h"

#include <QChart>

class GraphPanel : public QWidget, public IConstSensorVisitor {
private:
    std::vector<QChart*> charts;
public:
    GraphPanel(Sensor*);
    ~GraphPanel();
};

#endif // GRAPHPANEL_H
