#ifndef PARKINGPAGE_H
#define PARKINGPAGE_H

#include <QWidget>
#include "sensoreditordialog.h"

class ParkingPage : public QWidget
{
    Q_OBJECT
private:
    //SensorEditorDialog *editor;

public:
    explicit ParkingPage(QWidget *parent = nullptr);
    void editMode();

signals:
};

#endif // PARKINGPAGE_H
