#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(central);
    sensorBar = new SensorBar();
    sideMenu = new SideMenu();
    contentWindow = new QStackedWidget();

    dashWindow = new DashboardWindow();
    contentWindow->addWidget(dashWindow);
    dashWindow->show();
    dashWindow->setStyleSheet("background:orange;");

    graphWindow = new GraphWindow();
    contentWindow->addWidget(graphWindow);

    reportWindow = new ReportWindow();
    contentWindow->addWidget(reportWindow);

    contentWindow->setCurrentIndex(0);

    layout->addWidget(sideMenu);
    layout->addWidget(contentWindow);

    setCentralWidget(central);
    setWindowTitle("Parking Manager");
}

MainWindow::~MainWindow() {}
