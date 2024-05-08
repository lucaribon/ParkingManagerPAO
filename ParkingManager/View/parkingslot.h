#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include <QFrame>
#include <QLabel>
#include <QWidget>

class ParkingSlot : public QWidget
{
    Q_OBJECT
private:
    QFrame *lotFrame;
    QLabel *lotId;
    QLabel *carIcon;

public:
    explicit ParkingSlot(QWidget *parent = nullptr);

signals:
};

#endif // PARKINGSLOT_H
