#include "graphwindow.h"
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>
#include "graphpage.h"

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

    sensorList = new QListWidget();
    sensorList->setMaximumWidth(200);
    for (Sensor* sensor : controller->getSensors()) {
        sensorList->addItem(QString::fromStdString(sensor->getName()));
    }

    QFrame* graphPageFrame = new QFrame();
    graphPageFrame->setStyleSheet("background-color: #f0f0f0; border: none; border-radius: 5px;");
    QVBoxLayout* vLayout = new QVBoxLayout(graphPageFrame);
    connect(sensorList, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
        qDebug() << "Item clicked: " << item;
        //get sensor obj
        for (Sensor* sensor : controller->getSensors()) {
            if (sensor->getName() == item->text().toStdString()) {
                vLayout->addWidget(new GraphPage(sensor));
            }
        }
    });

    hLayout->addWidget(sensorList);
    hLayout->addWidget(graphPageFrame);
    layout->addWidget(graphFrame);
}

void GraphWindow::refreshSensorList(QListWidget* sensorList)
{
    //show the new areas
    if (sensorList->count() > 0)
        sensorList->clear();

    for (Sensor* sensor : controller->getSensors()) {
        sensorList->addItem(QString::fromStdString(sensor->getName()));
    }

    sensorList->update();
    sensorList->repaint();
    sensorList->show();
}

QListWidget* GraphWindow::getSensorList()
{
    return sensorList;
}

void GraphWindow::setSensorList(QListWidget* list)
{
    sensorList = list;
}
