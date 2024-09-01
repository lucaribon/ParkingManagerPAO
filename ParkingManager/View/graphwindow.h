#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include "../Controller/controller.h"

class GraphWindow : public QWidget
{
    Q_OBJECT
private:
    Controller *controller;

public:
    GraphWindow(Controller *con, QWidget *parent = 0);
};

#endif // GRAPHWINDOW_H
