#include "parkingmanager.h"
#include "ui_parkingmanager.h"

ParkingManager::ParkingManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ParkingManager)
{
    ui->setupUi(this);
}

ParkingManager::~ParkingManager()
{
    delete ui;
}
