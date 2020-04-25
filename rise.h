#ifndef RISE_H
#define RISE_H

#include <sweodef.h>
#include <swephexp.h>

class Rise {

    char serr[AS_MAXCH]; // for swe library error messages

    // array for atmospheric conditions
    double datm[2];

    // Location Long, Lat, height above sea level
    double geopos[3];

    double trise; // for calculated rising time
    double tset;  // for calculated setting time

    double tjd; // for calculated Julian date

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
    void setDate();
    void setDate(QDateTime);
    int calc();
    double getRiseJ();
    double getSetJ();
    QDateTime getRiseQ();
    QDateTime getSetQ();

};

#endif // RISE_H

