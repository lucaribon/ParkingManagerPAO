#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget();

    sideMenu = new SideMenu();
    contentWindow = new QStackedWidget(central);

    QHBoxLayout* layoutCentral = new QHBoxLayout(central);
    dashWindow = new DashboardWindow();
    graphWindow = new GraphWindow();
    reportWindow = new ReportWindow();

    //dashWindow->show();
    //dashWindow->setStyleSheet("background:orange;");

    contentWindow->addWidget(dashWindow);
    contentWindow->addWidget(graphWindow);
    contentWindow->addWidget(reportWindow);

    //QFrame* temp2 = new QFrame();
    //temp2->setFixedWidth(100);
    //temp2->setStyleSheet("background: green;");
    //layoutCentral->addWidget(temp2);
    layoutCentral->addWidget(sideMenu);
    layoutCentral->addWidget(contentWindow);
    //QFrame* temp = new QFrame();
    //temp->setFixedWidth(100);
    //temp->setStyleSheet("background: orange;");
    //layoutCentral->addWidget(temp);

    contentWindow->setCurrentIndex(0);

    QObject::connect(sideMenu, &SideMenu::currentRowChanged, contentWindow, &QStackedWidget::setCurrentIndex);

    this->setCentralWidget(central);
    setWindowTitle("Parking Manager");
}

MainWindow::~MainWindow() {}
