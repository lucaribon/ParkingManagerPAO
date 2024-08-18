#include "dashboardwindow.h"
#include <QDialog>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QList>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "parkingpage.h"
#include "welcomepage.h"

DashboardWindow::DashboardWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* mainLayout = new QVBoxLayout();

    QStackedWidget* contentWindow = new QStackedWidget(this);

    WelcomePage* welcomePage = new WelcomePage();
    welcomePage->setFixedHeight(200);
    contentWindow->addWidget(welcomePage);

    ParkingPage* parkingPage = new ParkingPage();
    contentWindow->addWidget(parkingPage);

    //contentWindow->setCurrentWidget(welcomePage);
    contentWindow->setCurrentWidget(parkingPage);

    mainLayout->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
    mainLayout->addWidget(contentWindow);
    setLayout(mainLayout);
}

void DashboardWindow::show(){
    
}

void DashboardWindow::editMode()
{
    qDebug() << "Edit mode activated!";
    //QPushButton* saveButton = new QPushButton("Save");
    //QPushButton* cancelButton = new QPushButton("Cancel");
    //QVBoxLayout* layout = new QVBoxLayout();
    //layout->addWidget(saveButton);
    //layout->addWidget(cancelButton);
    //QDialog* editWindow = new QDialog();
    //editWindow->setLayout(layout);
    //editWindow->show();
}
