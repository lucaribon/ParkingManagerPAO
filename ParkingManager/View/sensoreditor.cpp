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
    search->setPlaceholderText("Search...");
    search->setStyleSheet("background:white; border: none; border-radius: 8px; padding: 4px;");

    //LIST OF AREAS, ADD/REMOVE BUTTONS
    QFrame *sideFrameAreas = new QFrame();
    sideFrameAreas->setStyleSheet("background:#fbf8cc; border: none; border-radius: 8px;");
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
    sensorFrame->setStyleSheet("background-color: #fde4cf;border: none; border-radius: 8px;");
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
    remSensor->setToolTip("Remove Sensor");

    QPushButton *editButton = new QPushButton(QIcon(":/assets/icons/edit.svg"), "");
    editButton->setStyleSheet("background: white;border: none;border-radius: 8px;");
    editButton->setToolTip("Edit Sensor");

    connect(editButton, &QPushButton::clicked, [this] {
        if (listSensors->selectedItems().isEmpty()) {
            QMessageBox::critical(this, "Error", "Select a sensor to edit", QMessageBox::Ok);
            return;
        }
        Sensor *sensor = controller->getSensors().at(listSensors->currentRow());
        editSensorDialog(sensor);
    });

    connect(addSensor, &QPushButton::clicked, this, &SensorEditor::addSensorDialog);
    connect(remSensor, &QPushButton::clicked, [this] {
        if (listSensors->selectedItems().isEmpty()) {
            QMessageBox::critical(this, "Error", "Select a sensor to remove", QMessageBox::Ok);
            return;
        } else {
            removeSensor(listSensors->currentRow());
        }
    });

    QHBoxLayout *layoutButtonsSensor = new QHBoxLayout(buttonBarSensor);
    layoutButtonsSensor->addWidget(addSensor);
    layoutButtonsSensor->addWidget(remSensor);
    layoutButtonsSensor->addWidget(editButton);

    QVBoxLayout *layoutSensors = new QVBoxLayout(sensorFrame);
    layoutSensors->setContentsMargins(0, 0, 0, 0);
    layoutSensors->addWidget(listSensors);
    layoutSensors->addWidget(buttonBarSensor);

    QWidget *main = new QWidget();
    QHBoxLayout *layoutH = new QHBoxLayout(main);
    layoutH->setContentsMargins(0, 0, 0, 0);
    layoutH->addWidget(sideFrameAreas);
    layoutH->addWidget(sensorFrame);
    //layoutH->addWidget(sensorSettings);

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

    connect(listAreas, &QListWidget::itemClicked, [this](QListWidgetItem *item) {
        std::vector<Sensor *> filter;
        if (item->text() == "General") {
            refreshSensors(listSensors, controller->getSensors());
        } else {
            for (Sensor *sensor : controller->getSensors()) {
                if (sensor->getArea() == item->text().remove("Area ").toStdString()) {
                    filter.push_back(const_cast<Sensor *>(sensor));
                }
            }
            refreshSensors(listSensors, filter);
        }
    });
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
    if (controller->getAreas().empty()) {
        QMessageBox::critical(this, "Error", "Add an area before adding a sensor", QMessageBox::Ok);
        return;
    }

    QDialog *dialogSensor = new QDialog(this);

    //Form
    QWidget *form = new QWidget();
    QFormLayout *formLayout = new QFormLayout(form);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setFormAlignment(Qt::AlignLeft);

    //Name Edit
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setMaxLength(15); //MAX LENGTH NAME AREA
    lineEdit->setStyleSheet("background:white; border: none; border-radius: 8px; padding: 4px;");
    formLayout->addRow("Name", lineEdit);

    // type select
    QComboBox *sensorType = new QComboBox();
    sensorType->setInsertPolicy(QComboBox::InsertAlphabetically);
    sensorType->setFrame(true);
    sensorType->addItem("Light");
    sensorType->addItem("Presence");
    sensorType->addItem("Temperature and Humidity");
    sensorType->addItem("Air Quality");
    sensorType->addItem("Explosive Gas");
    sensorType->addItem("In Out");
    sensorType->setFixedWidth(220);
    formLayout->addRow("Sensor Type", sensorType);

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
        qDebug() << lineEdit->text().trimmed();
        qDebug() << sensorType->currentText();
        qDebug() << areaSelect->currentText();

        ////////////////////////////////////////////////

        int numberParkingSlots = 0;
        if (lineEdit->text().trimmed().isEmpty() || sensorType->currentText().isEmpty()
            || areaSelect->currentText().isEmpty()) {
            QMessageBox::critical(dialogSensor,
                                  "Error",
                                  "Sensor fields cannot be empty",
                                  QMessageBox::Ok);
        } else if (sensorType->currentText() == "Presence") {
            QDialog *dialogNumber = new QDialog(this);
            dialogNumber->setWindowTitle("Parking slots");

            //Form
            QWidget *num = new QWidget();
            QFormLayout *numLayout = new QFormLayout(num);
            numLayout->setLabelAlignment(Qt::AlignLeft);
            numLayout->setFormAlignment(Qt::AlignLeft);

            //Name Edit
            QLineEdit *lineEditNum = new QLineEdit();
            lineEditNum->setMaxLength(2);
            lineEditNum->setStyleSheet(
                "background:white; border: none; border-radius: 8px; padding: 4px;");
            numLayout->addRow("Number of parking slots", lineEditNum);

            QWidget *buttonBarNum = new QWidget();
            QPushButton *okNum = new QPushButton("Confirm");
            QHBoxLayout *layoutButtonsDialogNum = new QHBoxLayout(buttonBarNum);
            layoutButtonsDialogNum->addWidget(okNum);

            connect(okNum, &QPushButton::clicked, [lineEditNum, &numberParkingSlots, dialogNumber] {
                numberParkingSlots = lineEditNum->text().toInt();
                dialogNumber->accept();
            });

            QVBoxLayout *layoutNum = new QVBoxLayout(dialogNumber);
            layoutNum->addWidget(num);
            layoutNum->addWidget(buttonBarNum);

            dialogNumber->exec();

            for (int i = 0; i < numberParkingSlots; i++) {
                pushSensor(lineEdit->text().trimmed() + QString::number(i + 1),
                           sensorType->currentText(),
                           areaSelect->currentText());
            }
            dialogSensor->accept();
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

void SensorEditor::editSensorDialog(Sensor *sensor)
{
    QDialog *dialogSensor = new QDialog(this);
    dialogSensor->setWindowTitle("Edit Sensor");

    //Form
    QWidget *form = new QWidget();
    QFormLayout *formLayout = new QFormLayout(form);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setFormAlignment(Qt::AlignLeft);

    //Name Edit
    QLineEdit *lineEdit = new QLineEdit();
    QString name = QString::fromStdString(sensor->getName()).split(" - ").at(1);
    lineEdit->setText(name);
    lineEdit->setMaxLength(15);
    lineEdit->setStyleSheet("background:white; border: none; border-radius: 8px; padding: 4px;");
    formLayout->addRow("Name", lineEdit);

    // type select
    QComboBox *sensorType = new QComboBox();
    sensorType->setInsertPolicy(QComboBox::InsertAlphabetically);
    sensorType->setFrame(true);
    sensorType->addItem("Light");
    sensorType->addItem("Presence");
    sensorType->addItem("Temperature and Humidity");
    sensorType->addItem("Air Quality");
    sensorType->addItem("Explosive Gas");
    sensorType->addItem("In Out");
    QString type = QString::fromStdString(sensor->getName()).split(" - ").at(0);
    sensorType->setCurrentText(type);

    sensorType->setFixedWidth(220);
    formLayout->addRow("Sensor Type", sensorType);

    // area select
    QComboBox *areaSelect = new QComboBox();
    areaSelect->setInsertPolicy(QComboBox::InsertAlphabetically);
    areaSelect->setFrame(true);
    for (const std::string &area : controller->getAreas()) {
        areaSelect->addItem(QString::fromStdString(area));
    }
    areaSelect->setCurrentText(QString::fromStdString(sensor->getArea()));
    areaSelect->setFixedWidth(220);
    formLayout->addRow("Area", areaSelect);

    setFixedSize(sizeHint());

    QWidget *buttonBar = new QWidget();
    QPushButton *ok = new QPushButton("Ok");

    connect(ok,
            &QPushButton::clicked,
            [this, lineEdit, sensorType, areaSelect, dialogSensor, &sensor] {
                if (lineEdit->text().trimmed().isEmpty() || sensorType->currentText().isEmpty()
                    || areaSelect->currentText().isEmpty()) {
                    QMessageBox::critical(dialogSensor,
                                          "Error",
                                          "Sensor fields cannot be empty",
                                          QMessageBox::Ok);
                } else {
                    editSensor(sensor,
                               lineEdit->text().trimmed(),
                               areaSelect->currentText(),
                               sensorType->currentText());
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
        qDebug() << "Adding presence sensor";
        controller->addSensor(
            new PresenceSensor(sensorType.toStdString() + " - " + name.toStdString(),
                               area.toStdString()));
    } else if (sensorType == "Light") {
        qDebug() << "Adding light sensor";
        controller->addSensor(new LightSensor(sensorType.toStdString() + " - " + name.toStdString(),
                                              area.toStdString()));
    } else if (sensorType == "Temperature and Humidity") {
        qDebug() << "Adding tempHum sensor";
        controller->addSensor(
            new TempHumSensor(sensorType.toStdString() + " - " + name.toStdString(),
                              area.toStdString()));
    } else if (sensorType == "Air Quality") {
        qDebug() << "Adding airQuality sensor";
        controller->addSensor(
            new AirQualitySensor(sensorType.toStdString() + " - " + name.toStdString(),
                                 area.toStdString()));
    } else if (sensorType == "Explosive Gas") {
        qDebug() << "Adding explosiveGas sensor";
        controller->addSensor(
            new ExplosiveGasSensor(sensorType.toStdString() + " - " + name.toStdString(),
                                   area.toStdString()));
    } else {
        qDebug() << "Adding InOut sensor";
        controller->addSensor(new InOutSensor(sensorType.toStdString() + " - " + name.toStdString(),
                                              area.toStdString()));
    }
    refreshSensors(listSensors, controller->getSensors());
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

void SensorEditor::refreshSensors(QListWidget *listSensor, const std::vector<Sensor *> &sensors)
{
    //show the new areas
    listSensor->clear();

    for (const Sensor *sensor : sensors) {
        listSensor->addItem(QString::fromStdString(sensor->getArea()) + " - "
                            + QString::fromStdString(sensor->getName()));
    }

    listSensor->update();
    listSensor->repaint();
    listSensor->show();
}

void SensorEditor::removeArea(const QString &area)
{
    QString areaTrim = area;
    areaTrim.replace("Area ", "");
    qDebug() << "Removing area: " << areaTrim;
    controller->removeArea(areaTrim.toStdString());
    refreshAreas(listAreas);
}

void SensorEditor::removeSensor(const int pos)
{
    qDebug() << "Removing sensor at position: " << pos;
    controller->removeSensor(controller->getSensors().at(pos));
    refreshSensors(listSensors, controller->getSensors());
}

void SensorEditor::createPark()
{
    //close dialog
    parentWidget()->close();
    emit parkingCreated();
}

void SensorEditor::editSensor(Sensor *sensor,
                              const QString &name,
                              const QString &area,
                              const QString &sensorType)
{
    if (name.isEmpty() || sensorType.isEmpty() || area.isEmpty()) {
        QMessageBox::critical(this, "Error", "All fields are required", QMessageBox::Ok);
        return;
    }
    QString newName = "";
    newName = sensorType + " - " + name;
    refreshSensors(listSensors, controller->getSensors());
    sensor->setName(newName.toStdString());
    sensor->setArea(area.toStdString());
    refreshSensors(listSensors, controller->getSensors());
}
