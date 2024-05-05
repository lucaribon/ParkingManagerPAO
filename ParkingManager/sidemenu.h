#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class SideMenu : public QWidget
{
    Q_OBJECT
private:
    QLabel* icon;
    QLabel* menuName;
public:
    SideMenu(QWidget* parent = 0);
    void show();
};

#endif // SIDEMENU_H
