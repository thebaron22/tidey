#include <QDateTime>
#include <QDebug>

#include "rise.h"

Rise::Rise(double x, double y, double z) {

  datm[0] = 1013.25; // atmospheric pressure;
  datm[1] = 15;      // atmospheric temperature;

  geopos[0] = x;
  geopos[1] = y;
  geopos[2] = z;
  swe_set_topo(geopos[0], geopos[1], geopos[2]);

  setdate();
  calc();
};

void Rise::setdate() {
  QDateTime qdt = QDateTime::currentDateTime();
  qDebug() << qdt.toString() << qdt.toString("yyyy") << qdt.toString("yyyy").toInt() << qdt.toUTC();
  setdate(qdt.toUTC());
}

void Rise::setdate(QDateTime qdt) {

  double hrs = (qdt.toString("hh").toDouble() + qdt.toString("mm").toDouble()/60 + qdt.toString("ss").toDouble()/3600)/24;
  hrs = 22;

  tjd = swe_julday(qdt.toString("yyyy").toInt(), qdt.toString("MM").toInt(), qdt.toString("dd").toInt(), hrs, SE_GREG_CAL);

  qDebug() << "Set Date: " <<  QString::number(tjd,'f') << hrs;
  double dt =  geopos[0] / 360.0;
  qDebug() << "Set Date: ft" <<  QString::number(dt,'f') << hrs;
    tjd = tjd - dt;
  //tjd = tjd - (geopos[0] / 360.0);
//  tjd = 2458965;
  qDebug() << "Set Date: " <<  QString::number(tjd,'f');
};

int Rise::calc(){

  qDebug() << "Calc..." << QString::number(tjd, 'f');

  int return_code = swe_rise_trans(tjd, SE_SUN, NULL, SEFLG_SWIEPH, SE_CALC_RISE, geopos, datm[0], datm[1], &trise, serr);

  if (return_code == ERR) {
    printf("%s\n", serr);
    return 1;
  }

  qDebug() << "Calc..." << QString::number(trise, 'f');
  //trise = 2458965.352014;

  swe_jdet_to_utc(trise, SE_GREG_CAL, &rise_year, &rise_month, &rise_day, &rise_hour, &rise_min, &rise_sec);

  return_code = swe_rise_trans(tjd, SE_SUN, NULL, SEFLG_SWIEPH, SE_CALC_SET, geopos, datm[0], datm[1], &tset, serr);

  if (return_code == ERR) {
    printf("%s\n", serr);
    return 1;
  }
    
  swe_jdet_to_utc(tset, SE_GREG_CAL, &set_year, &set_month, &set_day, &set_hour, &set_min, &set_sec);

  return 0;
};

double Rise::getriseJ() {
  return trise;
};

double Rise::getsetJ() {
  return tset;
};

QDateTime Rise::getriseQ() {
  QDateTime qdt(QDate(rise_year, rise_month, rise_day), QTime(rise_hour, rise_min, rise_sec), Qt::UTC);
  qDebug() << "Julian rise:" << QString::number(trise, 'f');
  return qdt.toTimeSpec(Qt::LocalTime);
};

QDateTime Rise::getsetQ() {
  QDateTime qdt(QDate(set_year, set_month, set_day), QTime(set_hour, set_min, set_sec), Qt::UTC);
  return qdt.toTimeSpec(Qt::LocalTime);
};
