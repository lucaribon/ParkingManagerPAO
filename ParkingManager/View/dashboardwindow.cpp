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

DashboardWindow::DashboardWindow(Controller* con, QWidget* parent)
    : QWidget(parent)
    , controller(con)
{
    QVBoxLayout* mainLayout = new QVBoxLayout();

    contentWindow = new QStackedWidget(this);

    WelcomePage* welcomePage = new WelcomePage(controller, this);
    welcomePage->setFixedHeight(200);
    contentWindow->addWidget(welcomePage);
    contentWindow->setCurrentWidget(welcomePage);

    mainLayout->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
    mainLayout->addWidget(contentWindow);
    setLayout(mainLayout);
}

void DashboardWindow::setParkingPage()
{
    qDebug() << "Setting parking page!";
    ParkingPage* parkingPage = new ParkingPage(controller, this);
    contentWindow->addWidget(parkingPage);
    contentWindow->setCurrentWidget(parkingPage);
}
