#include "sensoreditor.h"
#include <QComboBox>
#include <QDialog>
#include <QFormLayout>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include "../Model/airQualitySensor.h"
#include "../Model/explosiveGasSensor.h"
#include "../Model/inOutSensor.h"
#include "../Model/lightSensor.h"
#include "../Model/presenceSensor.h"
#include "../Model/tempHumSensor.h"
#include "dashboardwindow.h"

SensorEditor::SensorEditor(Controller *con, QWidget *parent)
    : QWidget(parent)
    , controller(con)
    , listAreas(new QListWidget(this))
    , listSensors(new QListWidget(this))
{
    qDebug() << "--- " << parent->parentWidget()->parentWidget()->parentWidget();
    //get dashboard window
    DashboardWindow *dashboard = dynamic_cast<DashboardWindow *>(
        parent->parentWidget()->parentWidget()->parentWidget());

    connect(this, &SensorEditor::parkingCreated, dashboard, &DashboardWindow::setParkingPage);
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
    labelAreas->setStyleSheet("margin-top: 10px; margin-left: 18px; text-align: center; font-size: "
                              "16px; font-weight: bold;");

    listAreas->setContentsMargins(0, 0, 0, 0);
    listAreas->setSpacing(4);
    listAreas->addItem("General");

    for (const std::string &area : controller->getAreas()) {
        listAreas->addItem("Area " + QString::fromStdString(area));
    }

    //BUTTON BAR
    QWidget *buttonBar = new QWidget();
    QPushButton *addArea = new QPushButton(QIcon(":/assets/icons/add.svg"), "");
    addArea->setToolTip("Add Area");
    addArea->setStyleSheet("background: white;border: none;border-radius: 8px;");

    QPushButton *remArea = new QPushButton(QIcon(":/assets/icons/minus.svg"), "");
    remArea->setStyleSheet("background: white;border: none;border-radius: 8px;");
    remArea->setToolTip("Remove Area");

    connect(addArea, &QPushButton::clicked, this, &SensorEditor::addAreaDialog);
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
    sensorFrame->setStyleSheet("background-color: lightblue;border: none; border-radius: 8px;");
    listSensors->setContentsMargins(0, 0, 0, 0);
    listSensors->setSpacing(4);

    //get sensors from controller
    if (controller->getSensors().empty()) {
        listSensors->addItem("No sensors added");
    } else {
        for (const Sensor *sensor : controller->getSensors()) {
            listSensors->addItem(QString::fromStdString(sensor->getName()));
        }
    }

    QWidget *buttonBarSensor = new QWidget();
    QPushButton *addSensor = new QPushButton(QIcon(":/assets/icons/add.svg"), "");
    addSensor->setToolTip("Add Sensor");
    addSensor->setStyleSheet("background: white;border: none;border-radius: 8px;");

    QPushButton *remSensor = new QPushButton(QIcon(":/assets/icons/minus.svg"), "");
    remSensor->setStyleSheet("background: white;border: none;border-radius: 8px;");
    remSensor->setToolTip("Remove Area");

    connect(addSensor, &QPushButton::clicked, this, &SensorEditor::addSensorDialog);
    connect(remSensor, &QPushButton::clicked, [this] {
        if (listSensors->selectedItems().isEmpty()) {
            QMessageBox::critical(this, "Error", "Select a sensor to remove", QMessageBox::Ok);
            return;
        } else {
            removeArea(listSensors->selectedItems().first()->text());
        }
    });

    QHBoxLayout *layoutButtonsSensor = new QHBoxLayout(buttonBarSensor);
    layoutButtonsSensor->addWidget(addSensor);
    layoutButtonsSensor->addWidget(remSensor);

    QVBoxLayout *layoutSensors = new QVBoxLayout(sensorFrame);
    layoutSensors->setContentsMargins(0, 0, 0, 0);
    layoutSensors->addWidget(listSensors);
    layoutSensors->addWidget(buttonBarSensor);

    QFrame *sensorSettings = new QFrame();
    sensorSettings->setMinimumWidth(300);
    sensorSettings->setStyleSheet("background-color: lightgreen;border:none;border-radius:8px;");

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

void SensorEditor::addAreaDialog()
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
        ////DEBUGG
        qDebug() << "Ok clicked";
        qDebug() << lineEdit->text().trimmed();
        for (const auto &area : controller->getAreas()) {
            qDebug() << "getAreas ";
            qDebug() << QString::fromStdString(area);
        }
        ////////////////////////////////////////////////

        if (lineEdit->text().trimmed().isEmpty()) {
            QMessageBox::critical(dialog, "Error", "Area name cannot be empty", QMessageBox::Ok);

            //check if area already exists???
        } else {
            pushAreaName(lineEdit->text().trimmed());
            dialog->accept();
        }
    });
    QPushButton *cancel = new QPushButton("Cancel");
    connect(cancel, &QPushButton::clicked, [dialog] { dialog->close(); });
    QHBoxLayout *layoutButtonsDialog = new QHBoxLayout(buttonBar);
    layoutButtonsDialog->addWidget(ok);
    layoutButtonsDialog->addWidget(cancel);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(content);
    layout->addWidget(buttonBar);

    dialog->exec();
}

void SensorEditor::addSensorDialog()
{
    /* chiedere
     * - tipo di sensore
     * - nome del sensore
     * - area in cui si trova
     */

    QDialog *dialogSensor = new QDialog(this);
    dialogSensor->setWindowTitle("New Sensor");

    //Form
    QWidget *form = new QWidget();
    QFormLayout *formLayout = new QFormLayout(form);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setFormAlignment(Qt::AlignLeft);

    //Name Edit
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setMaxLength(15); //MAX LENGTH NAME AREA
    lineEdit->setStyleSheet("background:white; border: none; border-radius: 8px; padding: 4px;");
    formLayout->addRow("Nome", lineEdit);

    // type select
    QComboBox *sensorType = new QComboBox();
    sensorType->setInsertPolicy(QComboBox::InsertAlphabetically);
    sensorType->setFrame(true);
    sensorType->addItem("Presence");
    sensorType->addItem("Light");
    sensorType->addItem("Temperature and Humidity");
    sensorType->addItem("Air Quality");
    sensorType->addItem("Explosive Gas");
    sensorType->setFixedWidth(220);
    formLayout->addRow("Sensor Type", sensorType);

    //if presence sensor, show a text box to insert number
    QLineEdit *presenceNumber = new QLineEdit();
    if (sensorType->currentText() == "Presence") {
        formLayout->addRow("Presence Number", presenceNumber);
    } else {
        formLayout->removeRow(presenceNumber);
    }

    // area select
    QComboBox *areaSelect = new QComboBox();
    areaSelect->setInsertPolicy(QComboBox::InsertAlphabetically);
    areaSelect->setFrame(true);
    for (const std::string &area : controller->getAreas()) {
        areaSelect->addItem(QString::fromStdString(area));
    }
    areaSelect->setFixedWidth(220);
    formLayout->addRow("Area", areaSelect);

    setFixedSize(sizeHint());

    QWidget *buttonBar = new QWidget();
    QPushButton *ok = new QPushButton("Ok");

    connect(ok, &QPushButton::clicked, [this, lineEdit, sensorType, areaSelect, dialogSensor] {
        ////DEBUGG
        qDebug() << "Ok clicked";
        qDebug() << lineEdit->text().trimmed();
        qDebug() << sensorType->currentText();
        qDebug() << areaSelect->currentText();
        for (const auto &area : controller->getAreas()) {
            qDebug() << "getAreas ";
            qDebug() << QString::fromStdString(area);
        }
        ////////////////////////////////////////////////

        if (lineEdit->text().trimmed().isEmpty()) {
            QMessageBox::critical(dialogSensor,
                                  "Error",
                                  "Sensor name cannot be empty",
                                  QMessageBox::Ok);
        } else {
            pushSensor(lineEdit->text().trimmed(),
                       sensorType->currentText(),
                       areaSelect->currentText());
            dialogSensor->accept();
        }
    });
    QPushButton *cancel = new QPushButton("Cancel");
    connect(cancel, &QPushButton::clicked, [dialogSensor] { dialogSensor->close(); });
    QHBoxLayout *layoutButtonsDialogS = new QHBoxLayout(buttonBar);
    layoutButtonsDialogS->addWidget(ok);
    layoutButtonsDialogS->addWidget(cancel);

    QVBoxLayout *layout = new QVBoxLayout(dialogSensor);
    layout->addWidget(form);
    layout->addWidget(buttonBar);
    //Composizione form

    dialogSensor->exec();
}

void SensorEditor::pushAreaName(const QString &name)
{
    controller->addArea(name.toStdString());
    refreshAreas(listAreas);
}

void SensorEditor::pushSensor(const QString name, const QString sensorType, const QString area)
{
    if (name.isEmpty() || sensorType.isEmpty() || area.isEmpty()) {
        QMessageBox::critical(this, "Error", "All fields are required", QMessageBox::Ok);
        return;
    }
    if (sensorType == "Presence") {
        controller->addSensor(new PresenceSensor(name.toStdString(), area.toStdString()));
    }
    refreshAreas(listSensors);
}

void SensorEditor::refreshAreas(QListWidget *listAreas)
{
    //show the new areas
    listAreas->clear();
    listAreas->addItem("General");

    const std::set<std::string> areas = controller->getAreas();
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
    controller->removeArea(areaTrim.toStdString());
    refreshAreas(listAreas);
}

void SensorEditor::createPark()
{
    //close dialog
    parentWidget()->close();
    qDebug() << "createPark()";
    emit parkingCreated();
}
