#include "tattwa.h"

Tattwa::Tattwa(Rise *rise)
{
  prise = rise;
  calc();
  label.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  label.setStyleSheet("background-color: dimgray");

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &Tattwa::timerSlot);
  qDebug() << "Tattwa Starting Timer...";
  timer->start(10000);

};

void Tattwa::calc()
{
  QDateTime srise = prise->getRiseQ();
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 5; j++){
      qDebug() << elem[j] << srise.toString();
      srise = srise.addSecs(24 * 60);
    }
  }
};

void Tattwa::timerSlot()
{
  qDebug() << "Tattwa Timer...";
  calc();
};

