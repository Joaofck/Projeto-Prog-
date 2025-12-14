#ifndef DINASOR_H
#define DINASOR_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
class Dinasor : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Dinasor();
    QList<QPixmap> Frame;
    QString situation; // Estado atual "Stable" (parado) "Up" (subindo) "Down" (descendo)
    void reset();
    void set_walking(bool TF){
        is_walking = TF;
        return;
    }

public slots:
    void SCheck();

private:
    QTimer* SHandle;
    int shetab=15;
    bool is_walking;
};

#endif // DINASOR_H

