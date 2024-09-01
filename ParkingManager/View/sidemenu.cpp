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

    this->setContentsMargins(16, 16, 16, 16);
    setSpacing(4);
    setCurrentItem(dashboard);
    //layout->addWidget(icon);
    //layout->addWidget(menuName);
}
