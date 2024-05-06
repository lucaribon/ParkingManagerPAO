#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QWidget>
#include <QLabel>

class dashboardWindow : public QWidget
{
    Q_OBJECT
private:
    QLabel* tempTxt;
public:
    dashboardWindow(QWidget* parent = 0);
    void show();
};

#endif // DASHBOARDWINDOW_H
