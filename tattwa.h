#ifndef TATWA_H
#define TATWA_H

#include <QLabel>
#include <QtGui>

#include "rise.h"

class Tattwa : public QObject
{
    Q_OBJECT
    QLabel label;
    QTimer *timer;
    Rise *prise;
    char elem[5][8] = {
      "Spirit",
      "Air",
      "Fire",
      "Water",
      "Earth"
    };

public:
    Tattwa(Rise *rise);
    void calc();

public slots:
    void timerSlot();
};

#endif // TATWA_H

