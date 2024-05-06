#include "sidemenu.h"
#include <QVBoxLayout>


SideMenu::SideMenu(QWidget* parent): QListWidget(parent) {

    //QPixmap dashP();
    QIcon dashIcon(":/assets/icons/dashboard.svg");
    dashboard = new QListWidgetItem(dashIcon, "Dashboard");
    addItem(dashboard);

    graphs = new QListWidgetItem(dashIcon, "Graphs");
    addItem(dashboard);

    //layout->addWidget(icon);
    //layout->addWidget(menuName);
}
