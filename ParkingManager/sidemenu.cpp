#include "sidemenu.h"
#include <QVBoxLayout>


SideMenu::SideMenu(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    icon = new QLabel();
    menuName = new QLabel();

    layout->addWidget(icon);
    layout->addWidget(menuName);
}
