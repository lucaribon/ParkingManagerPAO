#include "graphpage.h"
#include "../Model/airQualitySensor.h"
#include "../Model/explosiveGasSensor.h"
#include "../Model/inOutSensor.h"
#include "../Model/lightSensor.h"
#include "../Model/presenceSensor.h"
#include "../Model/sensor.h"
#include "../Model/tempHumSensor.h"

#include <QChart>
#include <QChartView>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QLineSeries>
#include <QVBoxLayout>
#include <QValueAxis>

GraphPage::GraphPage(Sensor* sen, QWidget* parent)
    : QWidget{parent}
    , IConstSensorVisitor()
{
    //find sensor type

    sen->accept(this);
}

void GraphPage::handle(const TempHumSensor* sensor)
{
    qDebug() << "GraphPage::handle TempHumSensor";
    QVBoxLayout* lay = new QVBoxLayout;
    setLayout(lay);
    //Grafico Temperatura
    QChart* tempChart = new QChart();
    charts.push_back(tempChart);
    tempChart->setTitle("Temperature");
    std::map<time_t, std::vector<float>> tempHumVal = sensor->getTempHum();
    //get only temperature values, first of vector
    std::vector<float> temp;
    std::vector<time_t> timeTH;
    std::vector<float> hum;
    for (auto i : tempHumVal) {
        temp.push_back(i.second[0]);
        hum.push_back(i.second[1]);
        timeTH.push_back(i.first);
    }
    QLineSeries* tempSeries = new QLineSeries();
    for (int i = 0; i < temp.size(); i++) {
        //qDebug() << timeTH[i] << " : " << temp[i] << Qt::endl;
        tempSeries->append(timeTH[i], temp[i]);
    }
    tempChart->addSeries(tempSeries);

    QDateTimeAxis* xAxis1 = new QDateTimeAxis;
    xAxis1->setGridLineVisible(false);
    xAxis1->setTickCount(10);
    xAxis1->setFormat("hh.mm");
    xAxis1->setTitleText("Ora");
    tempChart->addAxis(xAxis1, Qt::AlignBottom);
    tempSeries->attachAxis(xAxis1);

    QValueAxis* yAxis1 = new QValueAxis;
    yAxis1->setGridLineVisible(false);
    yAxis1->setTickCount(10);
    yAxis1->setRange(-30, 50);
    yAxis1->setTitleText("Gradi Celsius");
    tempChart->addAxis(yAxis1, Qt::AlignLeft);
    tempSeries->attachAxis(yAxis1);

    QChartView* tempView = new QChartView();
    tempView->setChart(tempChart);
    lay->addWidget(tempView);

    //Grafico umidità
    QChart* humidityChart = new QChart();
    charts.push_back(humidityChart);
    humidityChart->setTitle("Umidità");

    QLineSeries* humSeries = new QLineSeries();
    for (int i = 0; i < hum.size(); i++) {
        //qDebug() << timeTH[i] << " : " << hum[i] << Qt::endl;
        humSeries->append(timeTH[i], hum[i]);
    }
    humidityChart->addSeries(humSeries);

    QDateTimeAxis* xAxis2 = new QDateTimeAxis;
    xAxis2->setGridLineVisible(false);
    xAxis2->setFormat("hh.mm");
    xAxis2->setTitleText("Ora");
    humidityChart->addAxis(xAxis2, Qt::AlignBottom);
    humSeries->attachAxis(xAxis2);

    QValueAxis* yAxis2 = new QValueAxis;
    yAxis2->setGridLineVisible(false);
    yAxis2->setTickCount(10);
    yAxis2->setRange(0, 100);
    yAxis2->setTitleText("Percentuale");
    humidityChart->addAxis(yAxis2, Qt::AlignLeft);
    humSeries->attachAxis(yAxis2);

    QChartView* humidityView = new QChartView();
    humidityView->setChart(humidityChart);
    lay->addWidget(humidityView);
}

void GraphPage::handle(const AirQualitySensor* sensor) {
    qDebug() << "GraphPage::handle AirQualitySensor";
    QVBoxLayout* lay = new QVBoxLayout;
    setLayout(lay);
    //Grafico QualitàAria
    QChart* qualChart = new QChart();
    charts.push_back(qualChart);
    qualChart->setTitle("AirQuality");
    std::map<time_t, std::vector<float>> qualVal = sensor->getValues();
    std::vector<int> airStatus;
    std::vector<time_t> timeA;
    for (auto i : qualVal) {
        timeA.push_back(i.first);
        airStatus.push_back(const_cast<AirQualitySensor*>(sensor)->getAirStatus(i.first));
    }
    QLineSeries* airSeries = new QLineSeries();
    for (int i = 0; i < airStatus.size(); i++) {
        // qDebug() << timeA[i] << " : " << airStatus[i] << Qt::endl;
        airSeries->append(timeA[i], airStatus[i]);
    }
    qualChart->addSeries(airSeries);

    QDateTimeAxis* xAxis1 = new QDateTimeAxis;
    xAxis1->setGridLineVisible(false);
    xAxis1->setTickCount(10);
    xAxis1->setFormat("hh.mm");
    xAxis1->setTitleText("Ora");
    qualChart->addAxis(xAxis1, Qt::AlignBottom);
    airSeries->attachAxis(xAxis1);

    QValueAxis* yAxis1 = new QValueAxis;
    yAxis1->setGridLineVisible(false);
    yAxis1->setTickCount(1);
    yAxis1->setRange(1,5);
    yAxis1->setTitleText("AQI");
    qualChart->addAxis(yAxis1, Qt::AlignLeft);
    airSeries->attachAxis(yAxis1);

    QChartView* qualView = new QChartView();
    qualView->setChart(qualChart);
    lay->addWidget(qualView);
}

void GraphPage::handle(const ExplosiveGasSensor* sensor) {
    qDebug() << "GraphPage::handle ExplosiveGasSensor";
    QVBoxLayout* lay = new QVBoxLayout;
    setLayout(lay);
    //Grafico Gas Esplosivi
    QChart* expChart = new QChart();
    charts.push_back(expChart);
    expChart->setTitle("Explosive Gas");
    std::map<time_t, std::vector<float>> expVal = sensor->getValues();
    std::vector<int> airStatus;
    std::vector<time_t> timeE;
    for (auto i : expVal) {
        timeE.push_back(i.first);
        airStatus.push_back(const_cast<ExplosiveGasSensor*>(sensor)->getAirStatus(i.first));
    }
    QLineSeries* expSeries = new QLineSeries();
    for (int i = 0; i < airStatus.size(); i++) {
        qDebug() << timeE[i] << " : " << airStatus[i] << Qt::endl;
        expSeries->append(timeE[i], airStatus[i]);
    }
    expChart->addSeries(expSeries);

    QDateTimeAxis* xAxis1 = new QDateTimeAxis;
    xAxis1->setGridLineVisible(false);
    xAxis1->setTickCount(10);
    xAxis1->setFormat("hh.mm");
    xAxis1->setTitleText("Ora");
    expChart->addAxis(xAxis1, Qt::AlignBottom);
    expSeries->attachAxis(xAxis1);

    QValueAxis* yAxis1 = new QValueAxis;
    yAxis1->setGridLineVisible(false);
    yAxis1->setTickCount(1);
    yAxis1->setRange(1,5);
    yAxis1->setTitleText("Explosive Gas Danger (lower is better)");
    expChart->addAxis(yAxis1, Qt::AlignLeft);
    expSeries->attachAxis(yAxis1);

    QChartView* expView = new QChartView();
    expView->setChart(expChart);
    lay->addWidget(expView);
}

void GraphPage::handle(const InOutSensor* sensor) {
    qDebug() << "GraphPage::handle Entrate";
    QVBoxLayout* lay = new QVBoxLayout;
    setLayout(lay);
    //Grafico Entrate
    QChart* inChart = new QChart();
    charts.push_back(inChart);
    inChart->setTitle("Entrate");
    std::map<time_t, std::vector<int>> inOutVal = sensor->getInOut();
    std::vector<int> in;
    std::vector<int> out;
    std::vector<time_t> timeIO;
    for (auto i : inOutVal) {
        timeIO.push_back(i.first);
        in.push_back(i.second[0]);
        out.push_back(i.second[1]);
    }
    QLineSeries* inSeries = new QLineSeries();
    QLineSeries* outSeries = new QLineSeries();
    for (int i = 0; i < in.size(); i++) {
        //qDebug() << timeIO[i] << " : " << in[i] << Qt::endl;
        inSeries->append(timeIO[i], in[i]);
        outSeries->append(timeIO[i], out[i]);
    }
    inChart->addSeries(inSeries);

    QDateTimeAxis* xAxis1 = new QDateTimeAxis;
    xAxis1->setGridLineVisible(false);
    xAxis1->setTickCount(10);
    xAxis1->setFormat("hh.mm");
    xAxis1->setTitleText("Ora");
    inChart->addAxis(xAxis1, Qt::AlignBottom);
    inSeries->attachAxis(xAxis1);

    QValueAxis* yAxis1 = new QValueAxis;
    yAxis1->setGridLineVisible(false);
    yAxis1->setTickCount(100);
    yAxis1->setRange(0,500);
    yAxis1->setTitleText("Entrate");
    inChart->addAxis(yAxis1, Qt::AlignLeft);
    inSeries->attachAxis(yAxis1);

    QChartView* inView = new QChartView();
    inView->setChart(inChart);
    lay->addWidget(inView);

    //Grafico Uscite
    QChart* outChart = new QChart();
    charts.push_back(outChart);
    inChart->setTitle("Uscite");

    outChart->addSeries(outSeries);

    QDateTimeAxis* xAxis2 = new QDateTimeAxis;
    xAxis2->setGridLineVisible(false);
    xAxis2->setTickCount(10);
    xAxis2->setFormat("hh.mm");
    xAxis2->setTitleText("Ora");
    outChart->addAxis(xAxis2, Qt::AlignBottom);
    outSeries->attachAxis(xAxis2);

    QValueAxis* yAxis2 = new QValueAxis;
    yAxis2->setGridLineVisible(false);
    yAxis2->setTickCount(100);
    yAxis2->setRange(0,500);
    yAxis2->setTitleText("Uscite");
    outChart->addAxis(yAxis2, Qt::AlignLeft);
    outSeries->attachAxis(yAxis2);

    QChartView* outView = new QChartView();
    outView->setChart(outChart);
    lay->addWidget(outView);
}

void GraphPage::handle(const LightSensor* sensor) {
    qDebug() << "GraphPage::handle Light";
    QVBoxLayout* lay = new QVBoxLayout;
    setLayout(lay);
    //Grafico Luce
    QChart* lightChart = new QChart();
    charts.push_back(lightChart);
    lightChart->setTitle("Luce");
    std::map<time_t, int> lightVal = sensor->getBrightness();
    std::vector<int> light;
    std::vector<time_t> timeL;
    for (auto i : lightVal) {
        timeL.push_back(i.first);
        light.push_back(i.second);
    }
    QLineSeries* lightSeries = new QLineSeries();
    for (int i = 0; i < light.size(); i++) {
        // qDebug() << timeL[i] << " : " << light[i] << Qt::endl;
        lightSeries->append(timeL[i], light[i]);
    }
    lightChart->addSeries(lightSeries);

    QDateTimeAxis* xAxis1 = new QDateTimeAxis;
    xAxis1->setGridLineVisible(false);
    xAxis1->setTickCount(10);
    xAxis1->setFormat("hh.mm");
    xAxis1->setTitleText("Ora");
    lightChart->addAxis(xAxis1, Qt::AlignBottom);
    lightSeries->attachAxis(xAxis1);

    QValueAxis* yAxis1 = new QValueAxis;
    yAxis1->setGridLineVisible(false);
    yAxis1->setTickCount(100);
    yAxis1->setRange(0,500);
    yAxis1->setTitleText("Luce");
    lightChart->addAxis(yAxis1, Qt::AlignLeft);
    lightSeries->attachAxis(yAxis1);

    QChartView* lightView = new QChartView();
    lightView->setChart(lightChart);
    lay->addWidget(lightView);

}

void GraphPage::handle(const PresenceSensor* sensor) {}
