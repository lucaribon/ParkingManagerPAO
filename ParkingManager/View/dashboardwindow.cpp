#include "dashboardwindow.h"
#include <QDialog>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QList>
#include <QPushButton>
#include <QVBoxLayout>
#include "parkinglots.h"

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // TOP BAR
    QFrame* topBar = new QFrame();
    QHBoxLayout* layoutTopBar = new QHBoxLayout(topBar);
    // BARRA SENSORI
    sensorBar = new SensorBar();
    sensorBar->setObjectName("sensorBar");
    QPushButton* editButton = new QPushButton(QIcon(":/assets/icons/edit.svg"), "");
    editButton->setFixedSize(35, 35);
    //editButton->setStyleSheet("background: #f0f0f0; border:none; border-radius:8px; padding: 10px;");
    connect(editButton, &QPushButton::clicked, this, &DashboardWindow::editMode);

    layoutTopBar->addWidget(sensorBar);
    layoutTopBar->addWidget(editButton);

    // PARCHEGGIO
    QWidget* parkSpace = new QWidget();
    QHBoxLayout* parkLayout = new QHBoxLayout(parkSpace);

    ParkingLots* park = new ParkingLots(this, "A", 20);
    ParkingLots* park1 = new ParkingLots(this, "B", 10);
    ParkingLots* park2 = new ParkingLots(this, "C", 12);

    parkLayout->addWidget(park);
    parkLayout->addWidget(park1);
    parkLayout->addWidget(park2);

    parkLayout->setAlignment(Qt::AlignBottom);

    // LAYOUT GENERALE
    layout->addWidget(topBar);
    layout->addWidget(parkSpace);

    setLayout(layout);
}

void DashboardWindow::show(){
    
}

void DashboardWindow::editMode()
{
    qDebug() << "Edit mode activated!";
    //finestra a comparsa per la modifica
    //modifica sensori
    //modifica parcheggio
    QPushButton* saveButton = new QPushButton("Save");
    QPushButton* cancelButton = new QPushButton("Cancel");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(saveButton);
    layout->addWidget(cancelButton);
    QDialog* editWindow = new QDialog();
    editWindow->setLayout(layout);
    editWindow->show();
}
