#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "dinasor.h"


class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static int score;
    Dinasor* D;

public slots:
    void creatGround();
    void Scorehandle();
    void creatCactus();
    void checkCollision();
    void resetGame();

private:
    QGraphicsScene *view;
    QTimer* checkGround;
    QTimer* addScore;
    QTimer* cactusTimer;
    QTimer* collisionTimer;
    void keyPressEvent(QKeyEvent* K);
    void clearScene();
    bool gameOver;
};
#endif // MAINWINDOW_H
