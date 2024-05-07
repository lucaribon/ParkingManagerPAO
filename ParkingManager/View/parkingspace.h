#ifndef PARKINGSPACE_H
#define PARKINGSPACE_H

#include <QObject>
#include <QWidget>
#include <QAbstractButton>

class ParkingSpace : public QWidget
{
    Q_OBJECT
private:
    std::list<QAbstractButton*> parkSpaces;
public:
    ParkingSpace(QWidget *parent = nullptr);
};

#endif // PARKINGSPACE_H
