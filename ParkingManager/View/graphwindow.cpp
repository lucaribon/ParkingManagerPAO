#include "graphwindow.h"
#include <QLabel>
#include <QVBoxLayout>

GraphWindow::GraphWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    QLabel* tempTxt = new QLabel();
    tempTxt->setText("Graph");
    layout->addWidget(tempTxt);

    setLayout(layout);
}
