#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "rise.h"
#include "astro.h"

int main(int argc, char **argv) {

 QApplication app(argc, argv);

 qDebug() << "Main...";

 Rise rise(-33.818538, 150.995233, 59);

 double srise = rise.getrise();

 QDate date = QDate::fromJulianDay(srise);
 qDebug() << "Main date..." << date.toString() << date.toJulianDay();

 //QTime time = QTime::fromMSecsSinceStartOfDay((srise - trunc(srise)) * 86400 * 1000);
 QTime time = QTime::fromMSecsSinceStartOfDay(43200 * 1000);
 qDebug() << "Main time..." << time.toString() << srise << (srise - trunc(srise));


 Astro astro;

 return app.exec();

}
