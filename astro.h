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
    void loadChart();
    void updateLabel();

public slots:
    void timerSlot();
};

#endif // ASTRO_H

