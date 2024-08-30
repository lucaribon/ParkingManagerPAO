#include "explosiveGasSensor.h"

ExplosiveGasSensor::ExplosiveGasSensor(std::string n, std::string a) : AirSensor(n,a), methane(0), propane(0), benzene(0), hydrogen(0) {}

float ExplosiveGasSensor::getMethane() const {return methane;}
float ExplosiveGasSensor::getPropane() const {return propane;}
float ExplosiveGasSensor::getBenzene() const {return benzene;}
float ExplosiveGasSensor::getHydrogen() const {return hydrogen;}

void ExplosiveGasSensor::setMethane(float val) {methane = val;}
void ExplosiveGasSensor::setPropane(float val) {propane = val;}
void ExplosiveGasSensor::setBenzene(float val) {benzene = val;}
void ExplosiveGasSensor::setHydrogen(float val) {hydrogen = val;}

int ExplosiveGasSensor::getAirStatus(){
    float airInMilGrams = 1000 * airFlowToAirMass(this->getAirflow());

    float methanePerc = (methane*100) / airInMilGrams;
    float propanePerc = (propane*100) / airInMilGrams;
    float benzenePerc = (benzene*100) / airInMilGrams;
    float hydrogenPerc = (hydrogen*100) / airInMilGrams;

    if(methanePerc>=5 || propanePerc>=2 ||
        benzenePerc>=1.2 || hydrogenPerc>=4){
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
