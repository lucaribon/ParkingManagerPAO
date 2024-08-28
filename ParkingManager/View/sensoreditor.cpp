#include "sensoreditor.h"
#include <QDialog>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include "dashboardwindow.h"

SensorEditor::SensorEditor(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << parentWidget()
                    ->parentWidget()
                    ->parentWidget()
                    ->parentWidget()
                    ->parentWidget(); //dashboardwindow
    connect(this,
            &SensorEditor::parkingCreated,
            qobject_cast<DashboardWindow *>(
                parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget()),
            &DashboardWindow::setParkingPage);

    //SEARCH BAR - non so come metterla piccola in mezzo :(
    QLineEdit *search = new QLineEdit();
    //search->setFixedWidth(250);
    search->setPlaceholderText("Search...");
    search->setStyleSheet("background:white; border: none; border-radius: 8px; padding: 4px;");

    //LIST OF AREAS, ADD/REMOVE BUTTONS
    QFrame *sideFrameAreas = new QFrame();
    sideFrameAreas->setStyleSheet("background:yellow; border: none; border-radius: 8px;");
    sideFrameAreas->setMinimumWidth(150);
    sideFrameAreas->setMaximumWidth(230);

    QLabel *labelAreas = new QLabel("Areas");
    labelAreas->setStyleSheet("margin-top: 10px; margin-left: 18px;");

    listAreas = new QListWidget();
    listAreas->setContentsMargins(0, 0, 0, 0);
    listAreas->setSpacing(4);
    listAreas->addItem("General");

    for (const std::string &area : areas) {
        listAreas->addItem("Area " + QString::fromStdString(area));
    }

    //BUTTON BAR
    QWidget *buttonBar = new QWidget();
    QPushButton *addArea = new QPushButton(QIcon(":/assets/icons/add.svg"), "");
    addArea->setToolTip("Add Area");
    addArea->setStyleSheet("background: white;border: none;border-radius: 8px;");
    connect(addArea, &QPushButton::clicked, this, &SensorEditor::addArea);

    QPushButton *remArea = new QPushButton(QIcon(":/assets/icons/minus.svg"), "");
    remArea->setStyleSheet("background: white;border: none;border-radius: 8px;");
    remArea->setToolTip("Remove Area");

    connect(remArea, &QPushButton::clicked, [this] {
        if (listAreas->selectedItems().isEmpty()) {
            QMessageBox::critical(this, "Error", "Select an area to remove", QMessageBox::Ok);
            return;
        } else {
            removeArea(listAreas->selectedItems().first()->text());
        }
    });

    QHBoxLayout *layoutButtons = new QHBoxLayout(buttonBar);
    layoutButtons->addWidget(addArea);
    layoutButtons->addWidget(remArea);

    QVBoxLayout *layoutSideFrame = new QVBoxLayout(sideFrameAreas);
    layoutSideFrame->setContentsMargins(0, 0, 0, 0);

    layoutSideFrame->addWidget(labelAreas);
    layoutSideFrame->addWidget(listAreas);
    layoutSideFrame->addWidget(buttonBar);

    //LIST OF SENSORS + SETTINGS
    QFrame *sensorFrame = new QFrame();
    sensorFrame->setMinimumWidth(200);
    sensorFrame->setMaximumWidth(350);

    QListWidget *listSensors = new QListWidget();
    listSensors->setContentsMargins(0, 0, 0, 0);
    listSensors->setSpacing(4);
    listSensors->setStyleSheet("background-color: lightblue;");
    listSensors->addItem("Sensor 1");
    listSensors->addItem("Sensor 2");
    listSensors->addItem("Sensor 3");

    QFrame *sensorSettings = new QFrame();
    sensorSettings->setMinimumWidth(300);
    sensorSettings->setStyleSheet("background-color: lightgreen;border:none;border-radius:8px;");

    QHBoxLayout *layoutSensors = new QHBoxLayout(sensorFrame);
    layoutSensors->setContentsMargins(0, 0, 0, 0);
    layoutSensors->addWidget(listSensors);

    QWidget *main = new QWidget();
    QHBoxLayout *layoutH = new QHBoxLayout(main);
    layoutH->setContentsMargins(0, 0, 0, 0);
    layoutH->addWidget(sideFrameAreas);
    layoutH->addWidget(sensorFrame);
    layoutH->addWidget(sensorSettings);

    //BUTTON BAR 2
    QWidget *buttonBar2 = new QWidget();
    QHBoxLayout *layoutButtons2 = new QHBoxLayout(buttonBar2);

    QPushButton *cancel = new QPushButton("Cancel");
    cancel->setStyleSheet("background: white;border: none;border-radius: 8px;");
    QPushButton *confirm = new QPushButton("Confirm");
    confirm->setStyleSheet("background: white;border: none;border-radius: 8px;");

    layoutButtons2->addWidget(cancel);
    layoutButtons2->addWidget(confirm);

    //cancell button quit the dialog
    connect(cancel, &QPushButton::clicked, [this] { this->parentWidget()->close(); });
    connect(confirm, &QPushButton::clicked, this, &SensorEditor::createPark);

    //SEARCH + MAIN WINDOW
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(search);
    layout->addWidget(main);
    layout->addWidget(buttonBar2);
}

void SensorEditor::addArea()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("New Area");

    QWidget *content = new QWidget();
    QHBoxLayout *layoutContent = new QHBoxLayout(content);
    QLabel *label = new QLabel("Area Name:");
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setMaxLength(15); //MAX LENGTH NAME AREA
    lineEdit->setStyleSheet("background:white; border: none; border-radius: 8px; padding: 4px;");
    layoutContent->addWidget(label);
    layoutContent->addWidget(lineEdit);

    QWidget *buttonBar = new QWidget();
    QPushButton *ok = new QPushButton("Ok");
    connect(ok, &QPushButton::clicked, [this, lineEdit, dialog] {
        if (lineEdit->text().trimmed().isEmpty()) {
            QMessageBox::critical(dialog, "Error", "Area name cannot be empty", QMessageBox::Ok);
        } else if (areas.find(lineEdit->text().trimmed().toStdString()) != areas.end()) {
            QMessageBox::critical(dialog, "Error", "Area name already exists", QMessageBox::Ok);
        } else {
            pushAreaName(lineEdit->text().trimmed());
            dialog->accept();
        }
    });
    QPushButton *cancel = new QPushButton("Cancel");
    connect(cancel, &QPushButton::clicked, [dialog] { dialog->close(); });
    QHBoxLayout *layoutButtons = new QHBoxLayout(buttonBar);
    layoutButtons->addWidget(ok);
    layoutButtons->addWidget(cancel);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(content);
    layout->addWidget(buttonBar);

    dialog->exec();
}
void SensorEditor::pushAreaName(const QString &area)
{
    areas.insert(area.toStdString());
    refreshAreas(listAreas);
}

void SensorEditor::refreshAreas(QListWidget *listAreas)
{
    //show the new areas
    listAreas->clear();
    listAreas->addItem("General");
    for (const std::string &area : areas) {
        listAreas->addItem("Area " + QString::fromStdString(area));
    }
    listAreas->update();
    listAreas->repaint();
    listAreas->show();
}

void SensorEditor::removeArea(const QString &area)
{
    QString areaTrim = area;
    areaTrim.replace("Area ", "");
    qDebug() << "Removing area: " << areaTrim;
    areas.erase(areaTrim.toStdString());
    refreshAreas(listAreas);
}

void SensorEditor::createPark()
{
    //close dialog
    parentWidget()->close();
    //read the areas
    for (const std::string &area : areas) {
        qDebug() << "Area: " << area.c_str();
    }

    emit parkingCreated();
}
