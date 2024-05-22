#include "welcomepage.h"
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "sensoreditor.h"

WelcomePage::WelcomePage(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *welcomeLabel = new QLabel("Welcome to Parking Manager", this);
    welcomeLabel->setAlignment(Qt::AlignCenter);

    QFrame *buttonFrame = new QFrame();
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonFrame);

    QPushButton *open = new QPushButton(QIcon(":/assets/icons/folder.svg"), "Open");
    connect(open, &QPushButton::clicked, this, &WelcomePage::openFile);

    QPushButton *newFile = new QPushButton(QIcon(":/assets/icons/add.svg"), "New");
    buttonLayout->addWidget(open);
    buttonLayout->addWidget(newFile);
    connect(newFile, &QPushButton::clicked, this, &WelcomePage::newParking);

    layout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    layout->addWidget(welcomeLabel);
    layout->addWidget(buttonFrame);
}

void WelcomePage::openFile()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    QString filePath = fileDialog->getOpenFileName(this,
                                                   "Open a JSON file",
                                                   "../../",
                                                   "JSON files (*.json)");
    qDebug() << filePath;
    if (!filePath.isEmpty()) {
        //emit fileOpened(filePath);
    }
}

void WelcomePage::newParking()
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
