#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include <QFrame>
#include <QLabel>
#include <QWidget>
#include <string>

class ParkingSlot : public QFrame
{
    Q_OBJECT
private:
    QLabel *lotId;

public:
    explicit ParkingSlot(QWidget *parent = nullptr,
                         int id = 0,
                         std::string area = " ",
                         bool isBusy = false);

signals:
};

#endif // PARKINGSLOT_H
