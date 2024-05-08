#include "sidemenu.h"
#include <QVBoxLayout>


SideMenu::SideMenu(QWidget* parent): QListWidget(parent) {
    /*
    QIcon parkingLogo(":/assets/icons/parking-app-icon.svg");
    parkingApp = new QListWidgetItem(parkingLogo, "Parking\nManager");
    parkingApp->setFlags(parkingApp->flags() & ~Qt::ItemIsSelectable);
    addItem(parkingApp);
    */

    QIcon dashIcon(":/assets/icons/dashboard.svg");
    dashboard = new QListWidgetItem(dashIcon, "Dashboard");
    addItem(dashboard);

    QIcon graphIcon(":/assets/icons/chart.svg");
    graphs = new QListWidgetItem(graphIcon, "Graphs");
    addItem(graphs);

    QIcon reportIcon(":/assets/icons/report.svg");
    reports = new QListWidgetItem(reportIcon, "Reports");
    addItem(reports);

    setSpacing(12);
    setCurrentItem(dashboard);
    //layout->addWidget(icon);
    //layout->addWidget(menuName);
}
