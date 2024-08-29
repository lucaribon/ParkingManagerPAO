#include "welcomepage.h"
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "sensoreditordialog.h"

WelcomePage::WelcomePage(Controller *con, QWidget *parent)
    : QWidget{parent}
    , controller(con)
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
    SensorEditorDialog *sensorEditor = new SensorEditorDialog(controller, this);
    sensorEditor->exec();
}
