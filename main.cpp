#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "rise.h"
#include "astro.h"

int main(int argc, char **argv) {

 QApplication app(argc, argv);

 qDebug() << "Main...";

 Rise rise(-33.818538, 150.995233, 59);
 QDate date;
 date.fromJulianDay(rise.getrise());
 QString mystr = QString::number(rise.getrise(), 'f');
 qDebug() << "Main..." << date.toString() << mystr;

 Astro astro;

 return app.exec();

}
