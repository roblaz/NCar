#ifndef NCAR_H
#define NCAR_H
//#pragma once

#include <QDebug>
#include <QString>

class NCar
{
    //class varaibles
    double engineVolume; // liters
    double gasVolume = 0.0;  // rest of gas in tank (liters)
    double odometer = 0.0;   // km
    double gasConsumption; // liters per 100km
protected:
    double tankMax = 50; // liters
    int   doorsCount  = 4;    // units
public:
    QString qsRegNumber;

    //class fuctions
public:
    NCar(double engVol=1.3, QString regNum="------", double gasConsupt = 14.6);
    double fill(double liters);
    double drive(double kmToRide);
    QString toPrint();
};

#endif // NCAR_H
