#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "ncar.h"

class Truck: public NCar{
public:
    Truck(double dVol, QString strNum, double dCons):NCar(dVol, strNum, dCons){
        tankMax = 200;
        doorsCount = 2;
    }
};

class Bus: public NCar{
public:
    Bus(double dVol, QString strNum, double dCons):NCar(dVol, strNum, dCons){
        tankMax = 120;
        doorsCount = 3;

    }
};

QDebug operator<<(QDebug dbg, NCar &c){
    QDebugStateSaver saver(dbg);
    dbg.noquote() << c.toPrint();
    return dbg;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NCar car1(1.2, "564MKJ", 5); //engineVol, regNumber, gasConsumpt
    Bus bus1(4.0, "132BHJ", 20);
    Truck truck1(5.0, "589GTF", 50);

    std::cout << '\n' << "Filling:" << '\n';
    car1.fill(50);
    qDebug() << car1;
    bus1.fill(100);
    qDebug() << bus1;
    truck1.fill(250);
    qDebug() << truck1;

    std::cout << '\n' << "Driving:" <<'\n';
    car1.drive(1000);
    qDebug() << car1;
    bus1.drive(300);
    qDebug() << bus1;
    truck1.drive(500);
    qDebug() << truck1;
    return a.exec();
}
