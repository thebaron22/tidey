#include "astro.h"

Astro::Astro()
{
  label.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  label.setStyleSheet("background-color: dimgray");

  qDebug() << "Load...";
  Load();

  timer = new QTimer(this);

  connect(timer, &QTimer::timeout, this, &Astro::TimerSlot);

  qDebug() << "Starting Timer...";
  timer->start(10000);

};

void Astro::Load() {
  QString program = "astrolog";
  QStringList arguments;
  QProcess *myProcess = new QProcess();
  myProcess->start(program, arguments);
  
  chart.load("/tmp/astro.log");

  label.setPixmap(chart);
  label.showMaximized();
};

void Astro::TimerSlot()
{
  qDebug() << "Astro Timer...";
  Load();
}
