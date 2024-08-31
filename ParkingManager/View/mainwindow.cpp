#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , appLogo(new AppLogo())
    , sideMenu(new SideMenu())
    , controller(new Controller(this))
{    
    // WIDGET CENTRALE
    QWidget* central = new QWidget();

    // PANNELLO LATERALE
    QWidget* sidePanel = new QWidget();
    sidePanel->setObjectName("sidePanel");
    QVBoxLayout* layoutSidePanel = new QVBoxLayout(sidePanel);
    layoutSidePanel->setContentsMargins(0, 0, 0, 0);

    //sideMenu->setFixedWidth(200);

    layoutSidePanel->addWidget(appLogo);
    layoutSidePanel->addWidget(sideMenu);
    layoutSidePanel->setAlignment(Qt::AlignTop);
    sidePanel->setFixedWidth(200);

    // STACKED WIDGET
    contentWindow = new QStackedWidget(central);

    dashWindow = new DashboardWindow(controller);
    graphWindow = new GraphWindow();
    reportWindow = new ReportWindow();

    contentWindow->insertWidget(0, dashWindow);
    contentWindow->insertWidget(1, graphWindow);
    contentWindow->insertWidget(2, reportWindow);

    contentWindow->setCurrentIndex(0); // finestra di default

    //qDebug() << contentWindow->currentWidget();

    // LAYOUT WIDGET GENERALE CENTRALE
    QHBoxLayout* layoutCentral = new QHBoxLayout(central);
    layoutCentral->addWidget(sidePanel);
    layoutCentral->addWidget(contentWindow);

    // CONNESSIONE SIDEMENU -> STACKED WIDGET
    sideMenu->connect(sideMenu, &SideMenu::currentRowChanged, contentWindow, &QStackedWidget::setCurrentIndex);

    this->setCentralWidget(central);
    setWindowTitle("Parking Manager");
}

MainWindow::~MainWindow() {}
