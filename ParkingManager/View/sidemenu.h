#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QObject>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>

class SideMenu : public QListWidget
{
    Q_OBJECT
private:
    QListWidgetItem* parkingApp;
    QListWidgetItem* dashboard;
    QListWidgetItem* graphs;
public:
    SideMenu(QWidget* parent = 0);
    void show();
};

#endif // SIDEMENU_H
