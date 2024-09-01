#include "graphwindow.h"
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

GraphWindow::GraphWindow(Controller* con, QWidget* parent)
    : QWidget(parent)
    , controller(con)
{
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    QLabel* tempTxt = new QLabel();
    tempTxt->setText("Graph");
    layout->addWidget(tempTxt);

    setLayout(layout);

    QFrame* graphFrame = new QFrame();
    QHBoxLayout* hLayout = new QHBoxLayout(graphFrame);

    QListWidget* sensorList = new QListWidget();
    for (Sensor* sensor : controller->getSensors()) {
        sensorList->addItem(QString::fromStdString(sensor->getName()));
    }

    hLayout->addWidget(sensorList);
    layout->addWidget(graphFrame);
}
