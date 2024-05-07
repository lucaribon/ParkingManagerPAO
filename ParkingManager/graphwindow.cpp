#include "graphwindow.h"
#include <QLabel>
#include <QVBoxLayout>

GraphWindow::GraphWindow(QWidget* parent) : QWidget(parent){
    //QLabel tempTxt =  new QLabel(QString &text="graph",QWidget *parent=this);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    QLabel* tempTxt = new QLabel();
    tempTxt->setText("Graph");
    layout->addWidget(tempTxt);

    setLayout(layout);
}
