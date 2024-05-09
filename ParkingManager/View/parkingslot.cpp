#include "parkingslot.h"
#include <QPixmap>
#include <QStackedWidget>
#include <QSvgWidget>
#include <QVBoxLayout>

ParkingSlot::ParkingSlot(QWidget *parent, int id, std::string area, bool isBusy)
    : QFrame{parent}
{
    this->setObjectName("lotFrame");
    this->setFixedSize(50, 35);
    //#e01b24->rosso   #2ec27e->verde #e5a50a->giallo
    if (isBusy)
        this->setStyleSheet("background: #e01b24; color: white; border: none; border-radius: 8px;");
    else
        this->setStyleSheet("background: #2ec27e; color: white; border: none; border-radius: 8px;");

    lotId = new QLabel(QString::fromStdString(area) + QString::number(id));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    layout->addWidget(lotId);

    setLayout(layout);
}
