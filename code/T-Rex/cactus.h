#ifndef CACTUS_H
#define CACTUS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Cactus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Cactus(double speed = 3);
    ~Cactus();

public slots:
    void move();
    void stop();

private:
    QTimer* timer;
    double speed;
};

#endif // CACTUS_H
