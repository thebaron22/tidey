#ifndef RISE_H
#define RISE_H

#include <sweodef.h>
#include <swephexp.h>

class Rise {

    char serr[AS_MAXCH];
    double epheflag = SEFLG_SWIEPH;
    int gregflag = SE_GREG_CAL;

    double rhour;
    double shour;

    // array for atmospheric conditions
    double datm[2];

    // Location Lat, Long, height above sea level
    double geopos[3];

    int ipl = SE_SUN; // object whose rising is wanted
    char starname[255] = ""; // name of star, if a star's rising is wanted
                      // is "" or NULL, if Sun, Moon, or planet is calculated

    double trise; // for rising time
    double tset;  // for setting time

    int year;
    int month;
    int day;

    double tjd;
    double dt;

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
    void setdate(int x, int y, int z);
    int calc();
    double getrise();
    double getset();

};

#endif // RISE_H

