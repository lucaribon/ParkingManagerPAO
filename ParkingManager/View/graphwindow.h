#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QListWidget>
#include "../Controller/controller.h"

class GraphWindow : public QWidget
{
    Q_OBJECT
private:
    Controller *controller;
    QListWidget* sensorList;

public:
    GraphWindow(Controller *con, QWidget *parent = 0);

    QListWidget* getSensorList();
    void setSensorList(QListWidget*);

    void refreshSensorList(QListWidget* sensorList);
};

#endif // GRAPHWINDOW_H
