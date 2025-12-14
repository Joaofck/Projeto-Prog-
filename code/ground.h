#ifndef GROUND_H
#define GROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Ground : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static double speed;
    static bool empty;

    Ground();
    ~Ground();

public slots:
    void move();

private:
    QTimer* timer;
    bool cloneCreated;
};

#endif // GROUND_H
