// gamescene.h
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>

class Dinasor;
class Ground;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);

private slots:
    void spawnGround();
    void updateGame();

private:
    Dinasor *dinasor;
    QTimer *spawnTimer;
    QTimer *gameTimer;
    double gameSpeed = 3.0;
};

#endif // GAMESCENE_H
