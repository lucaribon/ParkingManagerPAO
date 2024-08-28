#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include "sensoreditordialog.h"

class WelcomePage : public QWidget
{
    Q_OBJECT
private:
    SensorEditorDialog *editor;

public:
    explicit WelcomePage(SensorEditorDialog *editor, QWidget *parent = nullptr);
    void openFile();
    void newParking();
signals:
};

#endif // WELCOMEPAGE_H
