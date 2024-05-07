#include "sidemenu.h"
#include <QVBoxLayout>


SideMenu::SideMenu(QWidget* parent): QListWidget(parent) {
    //QPixmap dashP();
    QIcon dashIcon(":/assets/icons/dashboard.svg");
    dashboard = new QListWidgetItem(dashIcon, "Dashboard");
    addItem(dashboard);

    QIcon graphIcon(":/assets/icons/chart.svg");
    graphs = new QListWidgetItem(graphIcon, "Graphs");
    addItem(graphs);

    QIcon reportIcon(":/assets/icons/report.svg");
    reports = new QListWidgetItem(reportIcon, "Reports");
    addItem(reports);

    setSpacing(11);
    //layout->addWidget(icon);
    //layout->addWidget(menuName);
}
