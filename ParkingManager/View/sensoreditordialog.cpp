#include "sensoreditordialog.h"
#include <QVBoxLayout>
#include "sensoreditor.h"

SensorEditorDialog::SensorEditorDialog(Controller *con, QWidget *parent)
    : QWidget(parent)
    , controller(con)
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Sensor Editor");
    dialog->setMinimumWidth(600);
    dialog->setMinimumHeight(400);

    SensorEditor *editor = new SensorEditor(controller);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(editor);
    dialog->exec();
}
