#include "cactus.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QRandomGenerator>

Cactus::Cactus(double speed) : speed(speed)
{
    QPixmap originalImg(":/imagens/Cactus.png");
    if (originalImg.isNull()) {
        qDebug() << "Imagem do cactus não encontrada!";
    } else {
        QPixmap scaledImg = originalImg.scaled(40, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        setPixmap(scaledImg);
    }

    this->setPos(800, 450);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cactus::move);
    timer->start(10);
}

Cactus::~Cactus()
{
    if (timer) {
        timer->stop();
        delete timer;
    }
}

void Cactus::move()
{
    // Move para a esquerda na mesma velocidade do chão
    setPos(x() - speed, y());

    // Remove quando sai da tela
    if (x() < -100) {
        if (scene()) {
            scene()->removeItem(this);
        }
        deleteLater();
    }
}

void Cactus::stop()
{
    if (timer) {
        timer->stop();

    }
}
