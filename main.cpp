#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "astro.h"

int main(int argc, char **argv) {

 QApplication app(argc, argv);

 qDebug() << "Main...";

 Astro astro;

 return app.exec();

}
