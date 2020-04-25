#include "astro.h"

Astro::Astro()
{
  loadChart();
  label.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  label.setStyleSheet("background-color: dimgray");
  updateLabel();

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &Astro::timerSlot);
  qDebug() << "Starting Timer...";
  timer->start(10000);

};

void Astro::loadChart() {
  QString program = "astrolog";
  QStringList arguments;
  QProcess *myProcess = new QProcess();
  myProcess->start(program, arguments);
  
  chart.load("/tmp/astro.log");
}
void Astro::updateLabel() {
  label.setPixmap(chart);
  label.showMaximized();
};

void Astro::timerSlot()
{
  qDebug() << "Astro Timer...";
  loadChart();
  updateLabel();
}
