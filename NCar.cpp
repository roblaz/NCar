#include "ncar.h"

NCar::NCar(double engVol, QString regNum, double gasConsupt)
{
    qDebug() << "NCar double engVol: " << engVol << "QString regNum: " << regNum << "double gasConsupt" << gasConsupt ;
    engineVolume = engVol;
    qsRegNumber = regNum;
    gasConsumption = gasConsupt;
}

double NCar::fill(double wantToFill)
{
    if (gasVolume + wantToFill <= tankMax) {
        gasVolume += wantToFill;
    } else
        gasVolume = tankMax;
    return gasVolume;
}

double NCar::drive(double kmToRide)
{
    double litersSpend = gasConsumption*kmToRide/100.0;

    if (gasVolume < litersSpend){
        kmToRide = gasVolume*100.0/gasConsumption;
        litersSpend = gasVolume;
    }

    gasVolume -= litersSpend;
    odometer += kmToRide;
    return kmToRide;
}

QString NCar::toPrint()
{
    QString qsTemp = "{%1}: engine: %2 l; consumption:%3 liters per 100 km; max vol: %4\n"
                     "Gas current vol: %5 l; odometr: %6 km; Can drive: %7 km";
     qsTemp = qsTemp.arg(qsRegNumber).arg(engineVolume).arg(gasConsumption).arg(tankMax)
             .arg(gasVolume).arg(odometer).arg((gasVolume/gasConsumption)*100.0);
    return qsTemp;

}
