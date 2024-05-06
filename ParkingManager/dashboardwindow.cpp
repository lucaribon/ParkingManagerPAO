#include "dashboardwindow.h"
#include <QLabel>

dashboardWindow::dashboardWindow(QWidget* parent) : QWidget(parent){
    tempTxt = new QLabel();
}

void dashboardWindow::show(){
    tempTxt->setText("dashboard");
}
