#include "sensoreditordialog.h"
#include <QVBoxLayout>
#include "sensoreditor.h"

SensorEditorDialog::SensorEditorDialog(QWidget *parent)
    : QWidget(parent)
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Sensor Editor");
    dialog->setMinimumWidth(600);
    dialog->setMinimumHeight(400);

    SensorEditor *editor = new SensorEditor(dialog);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(editor);
    dialog->exec();
}
