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
{}

/*
void GraphPage::handle(const TempHumSensor* sensor)
{
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
        humSeries->append(timeTH[i], temp[i]);
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
*/
