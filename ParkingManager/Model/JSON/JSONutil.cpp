#include "JSONutil.h"
#include "../airQualitySensor.h"
#include "../explosiveGasSensor.h"
#include "../inOutSensor.h"
#include "../lightSensor.h"
#include "../presenceSensor.h"
#include "../tempHumSensor.h"
#include "../../Controller/controller.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JSONutil::JSONutil(QString p) : path(p) {
    QString jContent;
    QFile jFile(p);

    if(!jFile.open(QIODevice::ReadWrite)){
        qTerminate();
    }
    jFile.open(QIODevice::ReadOnly | QIODevice::Text);
    jContent = jFile.readAll();
    jFile.close();

    *document = QJsonDocument::fromJson(jContent.toUtf8());
}

void JSONutil::handle(const AirQualitySensor* sens) {
    QJsonObject jSens;

    jSens["id"]=sens->getId();
    jSens["name"]=QString::fromStdString(sens->getName());
    jSens["area"]=QString::fromStdString(sens->getArea());
    jSens["sensType"]=sensType::AirQuality;

    QJsonObject jDocObj(document->object());
    QJsonArray jArr = (jDocObj["sensors"].toArray());
    jArr.append(jSens);
    jDocObj["sensors"]= jArr;
    document->setObject(jDocObj);
}

void JSONutil::handle(const ExplosiveGasSensor* sens) {
    QJsonObject jSens;

    jSens["id"]=sens->getId();
    jSens["name"]=QString::fromStdString(sens->getName());
    jSens["area"]=QString::fromStdString(sens->getArea());
    jSens["sensType"]=sensType::ExplosiveGas;

    QJsonObject jDocObj(document->object());
    QJsonArray jArr = (jDocObj["sensors"].toArray());
    jArr.append(jSens);
    jDocObj["sensors"]= jArr;
    document->setObject(jDocObj);
}

void JSONutil::handle(const InOutSensor* sens) {
    QJsonObject jSens;

    jSens["id"]=sens->getId();
    jSens["name"]=QString::fromStdString(sens->getName());
    jSens["area"]=QString::fromStdString(sens->getArea());
    jSens["sensType"]=sensType::InOut;

    QJsonObject jDocObj(document->object());
    QJsonArray jArr = (jDocObj["sensors"].toArray());
    jArr.append(jSens);
    jDocObj["sensors"]= jArr;
    document->setObject(jDocObj);
}

void JSONutil::handle(const LightSensor* sens) {
    QJsonObject jSens;

    jSens["id"]=sens->getId();
    jSens["name"]=QString::fromStdString(sens->getName());
    jSens["area"]=QString::fromStdString(sens->getArea());
    jSens["sensType"]=sensType::Light;

    QJsonObject jDocObj(document->object());
    QJsonArray jArr = (jDocObj["sensors"].toArray());
    jArr.append(jSens);
    jDocObj["sensors"]= jArr;
    document->setObject(jDocObj);
}

void JSONutil::handle(const PresenceSensor* sens) {
    QJsonObject jSens;

    jSens["id"]=sens->getId();
    jSens["name"]=QString::fromStdString(sens->getName());
    jSens["area"]=QString::fromStdString(sens->getArea());
    jSens["sensType"]=sensType::Presence;

    QJsonObject jDocObj(document->object());
    QJsonArray jArr = (jDocObj["sensors"].toArray());
    jArr.append(jSens);
    jDocObj["sensors"]= jArr;
    document->setObject(jDocObj);
}

void JSONutil::handle(const TempHumSensor* sens) {
    QJsonObject jSens;

    jSens["id"]=sens->getId();
    jSens["name"]=QString::fromStdString(sens->getName());
    jSens["area"]=QString::fromStdString(sens->getArea());
    jSens["sensType"]=sensType::TempHum;

    QJsonObject jDocObj(document->object());
    QJsonArray jArr = (jDocObj["sensors"].toArray());
    jArr.append(jSens);
    jDocObj["sensors"]= jArr;
    document->setObject(jDocObj);
}
