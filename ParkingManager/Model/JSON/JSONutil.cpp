#include "JSONutil.h"
#include "../airQualitySensor.h"
#include "../explosiveGasSensor.h"
#include "../inOutSensor.h"
#include "../lightSensor.h"
#include "../presenceSensor.h"
#include "../tempHumSensor.h"
#include "../../Controller/controller.h"

#include <QFile>
#include <QString>
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

    if(!jContent.isEmpty()){
        *document = QJsonDocument::fromJson(jContent.toUtf8());
    }else{
        QJsonArray jArray;
        QJsonObject jObj;
        jObj["sensors"] = jArray;
        document = new QJsonDocument(jObj);
        jFile.write(document->toJson());
    }

    jFile.close();
}

void JSONutil::handle(const AirQualitySensor* sens) {
    QJsonObject jSens;

    jSens["id"]=QString::fromStdString(sens->getId());
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

    jSens["id"]=QString::fromStdString(sens->getId());
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

    jSens["id"]=QString::fromStdString(sens->getId());
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

    jSens["id"]=QString::fromStdString(sens->getId());
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

    jSens["id"]=QString::fromStdString(sens->getId());
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

    jSens["id"]=QString::fromStdString(sens->getId());
    jSens["name"]=QString::fromStdString(sens->getName());
    jSens["area"]=QString::fromStdString(sens->getArea());
    jSens["sensType"]=sensType::TempHum;

    QJsonObject jDocObj(document->object());
    QJsonArray jArr = (jDocObj["sensors"].toArray());
    jArr.append(jSens);
    jDocObj["sensors"]= jArr;
    document->setObject(jDocObj);
}

std::vector<Sensor*> JSONutil::getSensorsFromJSON() const {
    QFile jFile(path);

    if(!jFile.open(QIODevice::ReadOnly)){
        qTerminate();
    }

    std::vector<Sensor*> sensors;

    QJsonObject jDocObj = document->object();
    QJsonValue jContent = jDocObj["sensors"];

    if(!jContent.isNull()){
        QJsonArray jDocArr(jContent.toArray());
        for(auto it = jDocArr.begin(); it != jDocArr.end(); ++it){
            if((*it).isObject()){
                QJsonObject jSensor((*it).toObject());
                int type = jSensor["sensType"].toInt();
                switch (type) {
                case sensType::AirQuality: sensors.push_back(new AirQualitySensor((jSensor["name"].toString()).toStdString(), (jSensor["area"].toString()).toStdString(), (jSensor["id"].toString()).toStdString()));
                    break;
                    case sensType::ExplosiveGas: sensors.push_back(new ExplosiveGasSensor((jSensor["name"].toString()).toStdString(), (jSensor["area"].toString()).toStdString(), (jSensor["id"].toString()).toStdString()));
                        break;
                    case sensType::InOut: sensors.push_back(new InOutSensor((jSensor["name"].toString()).toStdString(), (jSensor["area"].toString()).toStdString(), (jSensor["id"].toString()).toStdString()));
                        break;
                    case sensType::Light: sensors.push_back(new LightSensor((jSensor["name"].toString()).toStdString(), (jSensor["area"].toString()).toStdString(), (jSensor["id"].toString()).toStdString()));
                        break;
                    case sensType::Presence: sensors.push_back(new PresenceSensor((jSensor["name"].toString()).toStdString(), (jSensor["area"].toString()).toStdString(), (jSensor["id"].toString()).toStdString()));
                        break;
                    case sensType::TempHum: sensors.push_back(new TempHumSensor((jSensor["name"].toString()).toStdString(), (jSensor["area"].toString()).toStdString(), (jSensor["id"].toString()).toStdString()));
                        break;
                }
            }
        }
    }

    return sensors;
}

void JSONutil::updateSensorsIntoJSON(std::vector<Sensor*> sens){
    QJsonObject jObj;
    QJsonArray jArr;
    jObj["sensors"]=jArr;
    document->setObject(jObj);

    for(auto s : sens){
        s->accept(this);
    }

    QFile jFile(path);
    if(!jFile.open(QIODevice::WriteOnly)){
        qTerminate();
    }
    jFile.write(document->toJson());
}
