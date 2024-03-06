#ifndef PARKINGMANAGER_H
#define PARKINGMANAGER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ParkingManager;
}
QT_END_NAMESPACE

class ParkingManager : public QMainWindow {
  Q_OBJECT

public:
  ParkingManager(QWidget *parent = nullptr);
  ~ParkingManager();

private:
  Ui::ParkingManager *ui;
};
#endif // PARKINGMANAGER_H
