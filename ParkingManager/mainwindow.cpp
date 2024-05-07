#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget();

    sideMenu = new SideMenu();
    sideMenu->setFixedWidth(200);
    contentWindow = new QStackedWidget(central);

    QHBoxLayout* layoutCentral = new QHBoxLayout(central);
    dashWindow = new DashboardWindow();
    graphWindow = new GraphWindow();
    reportWindow = new ReportWindow();

    //dashWindow->show();
    //dashWindow->setStyleSheet("background:orange;");

    contentWindow->setCurrentIndex(0);
    contentWindow->insertWidget(0, dashWindow);
    contentWindow->insertWidget(1, graphWindow);
    contentWindow->insertWidget(2, reportWindow);

    qDebug() << contentWindow->currentWidget();

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

    qDebug() << sideMenu->connect(sideMenu, &SideMenu::currentRowChanged, contentWindow, &QStackedWidget::setCurrentIndex);
    //QObject::connect(sideMenu, &SideMenu::currentRowChanged, contentWindow, &QStackedWidget::setCurrentIndex);

    this->setCentralWidget(central);
    setWindowTitle("Parking Manager");
}

MainWindow::~MainWindow() {}
