#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include "../Controller/controller.h"

class WelcomePage : public QWidget
{
    Q_OBJECT
private:
    Controller *controller;

public:
    explicit WelcomePage(Controller *con, QWidget *parent = nullptr);
    void openFile();
    void newParking();
signals:
};

#endif // WELCOMEPAGE_H
