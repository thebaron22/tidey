#ifndef RISE_H
#define RISE_H

#include <sweodef.h>
#include <swephexp.h>

class Rise {

    char serr[AS_MAXCH]; // for library error messages

    // array for atmospheric conditions
    double datm[2];

    // Location Lat, Long, height above sea level
    double geopos[3];

    double trise; // for rising time
    double tset;  // for setting time

    double tjd; // for Julian date

    // Sunrise UTC results
    int rise_year;
    int rise_month;
    int rise_day;
    int rise_hour;
    int rise_min;
    double rise_sec;

    // Sunset UTC results
    int set_year;
    int set_month;
    int set_day;
    int set_hour;
    int set_min;
    double set_sec;

  public:
    Rise(double x, double y, double z);
    void setdate();
    void setdate(QDateTime);
    int calc();
    double getriseJ();
    double getsetJ();
    QDateTime getriseQ();
    QDateTime getsetQ();

};

#endif // RISE_H

