#ifndef ASTRO_H
#define ASTRO_H

#include <QLabel>
#include <QtGui>

class Astro : public QObject
{
    Q_OBJECT
    QLabel label;
    QPixmap chart;
    QTimer *timer;

public:
    Astro();
    void Load();

public slots:
    void TimerSlot();
};

#endif // ASTRO_H

