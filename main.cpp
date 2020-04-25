#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "rise.h"
#include "astro.h"

int main(int argc, char **argv) {

 QApplication app(argc, argv);

 qDebug() << "Main...";

 Rise rise(-33.818538, 150.995233, 87);

 double srise = rise.getriseJ();

 QDate date = QDate::fromJulianDay(srise);
 qDebug() << "Main date..." << date.toString() << date.toJulianDay();

 QTime time = QTime::fromMSecsSinceStartOfDay(43200 * 1000);
 qDebug() << "Main time..." << time.toString() << srise << (srise - trunc(srise));

 QDateTime dt = rise.getriseQ();
 qDebug() << "Main Sunrise..." << dt << dt.toString() << dt.toUTC().toString();

 //Astro astro;

 return 0;
 //return app.exec();

}
