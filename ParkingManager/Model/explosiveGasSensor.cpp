#include "explosiveGasSensor.h"

ExplosiveGasSensor::ExplosiveGasSensor(std::string n, std::string a, std::string i) : AirSensor(n,a, i!="" ? i : (QUuid::createUuid().toString()).toStdString()) {}
ExplosiveGasSensor::~ExplosiveGasSensor() =default;

int ExplosiveGasSensor::getAirStatus(time_t t){
    float airInMilGrams = 1000 * airFlowToAirMass((this->getAirflow())[t]);

    std::vector<float> valueI = values[t];
    // percentuali di presenza dei gas nell'aria analizzata
    float methanePerc = (valueI[0]*100) / airInMilGrams,
        propanePerc = (valueI[1]*100) / airInMilGrams,
        benzenePerc = (valueI[2]*100) / airInMilGrams,
        hydrogenPerc = (valueI[3]*100) /airInMilGrams;

    if(methanePerc>=5 || propanePerc>=2 || benzenePerc>=1.2 || hydrogenPerc>=4){
        return 5; // very high danger
    }else if((methanePerc>=3.75&&methanePerc<5) || (propanePerc>=1.5&&propanePerc<2) ||
               (benzenePerc>=0.9&&benzenePerc<1.2) || (hydrogenPerc>=3&&hydrogenPerc<4)){
        return 4; // high danger
    }else if((methanePerc>=2.5&&methanePerc<3.75) || (propanePerc>=1&&propanePerc<1.5) ||
               (benzenePerc>=0.6&&benzenePerc<0.9) || (hydrogenPerc>=2&&hydrogenPerc<3)){
        return 3; // medium danger
    }else if((methanePerc>=1.25&&methanePerc<2.5) || (propanePerc>=0.5&&propanePerc<1) ||
               (benzenePerc>=0.3&&benzenePerc<0.6) || (hydrogenPerc>=1&&hydrogenPerc<2)){
        return 2; // low danger
    }else if((methanePerc>=0&&methanePerc<1.25) || (propanePerc>=0&&propanePerc<0.5) ||
               (benzenePerc>=0&&benzenePerc<0.3) || (hydrogenPerc>=0&&hydrogenPerc<1)){
        return 1; // very low danger
    }
    return 0;
}

void ExplosiveGasSensor::generateSimulationData() {
    time_t init = time(0);
    tm* date = localtime(&init); // now
    date->tm_mday -= 7; // a week ago

    for(int i=0; i<7; i++) {
        for(int j=0; j<24; j++){
            time_t tempT = mktime(date);

            airflow[tempT] = 0.9 + (float)((std::rand()) / (1.1 - 0.9 + 1));

            std::vector<float> tempVal = std::vector<float>(4);
            tempVal[0] = (float)(std::rand()) / (7);
            tempVal[1] = (float)(std::rand()) / (4);
            tempVal[2] = (float)(std::rand()) / (3.2);
            tempVal[3] = (float)(std::rand()) / (6);
            values[tempT] = tempVal;

            date->tm_hour += 1;
        }
        date->tm_mday += 1;
    }
}

void ExplosiveGasSensor::accept(ISensorVisitor* handler){
    handler->handle(this);
}

void ExplosiveGasSensor::accept(IConstSensorVisitor* handler) const {
    handler->handle(this);
}
