#ifndef SENSOREDITORDIALOG_H
#define SENSOREDITORDIALOG_H

#include <QDialog>
#include <QWidget>
#include "../Controller/controller.h"

class SensorEditorDialog : public QWidget
{
    Q_OBJECT
private:
    Controller *controller;

public:
    explicit SensorEditorDialog(Controller *con, QWidget *parent = nullptr);
};

#endif // SENSOREDITORDIALOG_H
