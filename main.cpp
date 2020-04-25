#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "rise.h"
#include "astro.h"

int main(int argc, char **argv) {

 QApplication app(argc, argv);

 Rise rise(150.995233, -33.818538, 87);

 QDateTime qdt = rise.getRiseQ();
 qDebug() << "Main Sunrise..." << qdt << qdt.toString() << qdt.toUTC().toString();

 //Astro astro;

 return app.exec();

}
