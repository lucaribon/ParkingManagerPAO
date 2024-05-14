#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>

class WelcomePage : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomePage(QWidget *parent = nullptr);
    void openFile();
signals:
};

#endif // WELCOMEPAGE_H
