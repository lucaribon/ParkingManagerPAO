#include "parkingslot.h"
#include <QPixmap>
#include <QStackedWidget>
#include <QVBoxLayout>

ParkingSlot::ParkingSlot(QWidget *parent)
    : QWidget{parent}
{
    lotFrame = new QFrame();
    lotFrame->setObjectName("lotFrame");
    lotFrame->setFixedSize(35, 50);
    lotFrame->setStyleSheet("background: green; border: 1px solid black; border-radius: 8px;");

    lotId = new QLabel("A1");

    QPixmap carPixmap(":/assets/images/car.png");
    carIcon = new QLabel();
    carIcon->setPixmap(carPixmap.scaledToHeight(20));

    QStackedWidget *stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(lotFrame);
    stackedWidget->addWidget(carIcon);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(stackedWidget);
    layout->addWidget(lotId);
}
