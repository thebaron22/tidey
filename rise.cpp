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
  qDebug() << qdt.toString() << qdt.toString("yyyy") << qdt.toString("yyyy").toInt();
  setdate(qdt.toString("yyyy").toInt(), qdt.toString("MM").toInt(), qdt.toString("dd").toInt());
}

void Rise::setdate(int x, int y, int z) {
  year = x;
  month = y;
  day = z;
      
  qDebug() << x << y << z;

  // calculate the julian day number of the date at 12:00 localtime
  tjd = swe_julday(year,month,day,0,gregflag);

  // convert geographic longitude to time (day fraction) and subtract it from tjd
  // this method should be good for all geographic latitudes except near in
  // polar regions
  qDebug() << "Set Julian day: " <<  QString::number(tjd,'f');
  dt =  geopos[0] / 360.0;
  tjd = tjd - dt;
  qDebug() << "Set Julian day: " <<  QString::number(tjd,'f');
};

int Rise::calc(){

  int return_code;
  return_code = swe_rise_trans(tjd, ipl, starname, epheflag, SE_CALC_RISE, geopos, datm[0], datm[1], &trise, serr);

  if (return_code == ERR) {
    printf("%s\n", serr);
    return 1;
  }

  swe_jdet_to_utc(trise, gregflag, &rise_year, &rise_month, &rise_day, &rise_hour, &rise_min, &rise_sec);

  return_code = swe_rise_trans(trise, ipl, starname, epheflag, SE_CALC_SET, geopos, datm[0], datm[1], &tset, serr);

  if (return_code == ERR) {
    printf("%s\n", serr);
    return 1;
  }
    
  swe_jdet_to_utc(tset, gregflag, &set_year, &set_month, &set_day, &set_hour, &set_min, &set_sec);

  return 0;
};

double Rise::getrise() {
  return trise;
};

double Rise::getset() {
  return tset;
};
