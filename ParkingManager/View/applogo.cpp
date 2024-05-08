#include "applogo.h"
#include <QHBoxLayout>

AppLogo::AppLogo(QFrame *parent)
    : QFrame{parent}
{
    QHBoxLayout* layoutLogo = new QHBoxLayout(this);

    icon = new QSvgWidget(":/assets/icons/parking-app-icon.svg");
    icon->setFixedSize(30, 30);
    logoText = new QLabel("Parking Manager");

    layoutLogo->addWidget(icon);
    layoutLogo->addWidget(logoText);
}
