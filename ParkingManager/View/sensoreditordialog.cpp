#include "sensoreditordialog.h"
#include <QVBoxLayout>
#include "sensoreditor.h"

SensorEditorDialog::SensorEditorDialog(Controller *con, QWidget *parent)
    : QDialog(parent)
    , controller(con)
{
    this->setWindowTitle("Sensor Editor");
    this->setMinimumWidth(600);
    this->setMinimumHeight(400);

    SensorEditor *editor = new SensorEditor(controller, this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(editor);
}
