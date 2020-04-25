#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "rise.h"
#include "astro.h"

int main(int argc, char **argv) {

 QApplication app(argc, argv);

 qDebug() << "Main...Start";

 Rise rise(150.995233, -33.818538, 87);

 double srise = rise.getriseJ();

 QDate date = QDate::fromJulianDay(srise);
 qDebug() << "Main date..." << date.toString() << date.toJulianDay();

 QTime time = QTime::fromMSecsSinceStartOfDay(43200 * 1000);
 qDebug() << "Main time..." << time.toString() << srise << (srise - trunc(srise));

 QDateTime qdt = rise.getriseQ();
 qDebug() << "Main Sunrise..." << qdt << qdt.toString() << qdt.toUTC().toString();

 //Astro astro;

 return 0;
 //return app.exec();

}
