#include "ground.h"
#include <QGraphicsScene>
#include <QDebug>

double Ground::speed = 3;
bool Ground::empty = false;

Ground::Ground() : cloneCreated(false)
{
    static QPixmap* cachedPixmap = nullptr;

    if (cachedPixmap == nullptr) {
        QPixmap originalImg(":/imagens/Ground.png");
        if (originalImg.isNull()) {
            qDebug() << "Imagem não encontrada!";
        } else {
            // Cria a imagem na heap e armazena no ponteiro estático
            //setScale(1000,100);
            cachedPixmap = new QPixmap(originalImg.scaled(900,480, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

    if (cachedPixmap) {
        setPixmap(*cachedPixmap);
    }

    this->setPos(-100, 480);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ground::move);
    timer->start(10);
}

Ground::~Ground()
{
    // O timer é deletado automaticamente
    qDebug() << "Ground deletado";
}

void Ground::move()
{
    // Move o objeto para a esquerda
    setPos(x() - speed, y());

    // Cria o próximo pedaço de chão
    // Se passou de -80 e ainda não criou um clone
    if (x() <= -80 && !cloneCreated) {
        empty = true; // Sinaliza para o gerenciador criar outro chão
        cloneCreated = true;
    }

    // Se saiu totalmente da tela
    if (x() < -1100) {
        // Remove da cena visualmente
        if (scene()) {
            scene()->removeItem(this);
        }
        // Agenda a deleção segura do objeto para o próximo ciclo de loop
        this->deleteLater();
    }
}
