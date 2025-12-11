#include "dinasor.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

Dinasor::Dinasor()
{
    QPixmap imagDI1(":/imagens/Dinasor1.png");
    QPixmap scaled_imagDI1=imagDI1.scaled(60,110,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    Frame << scaled_imagDI1;
    setPixmap(scaled_imagDI1);
    this->setPos(55,443);
    setZValue(10);

    situation = "Stable";

    SHandle =  new QTimer();
    connect(SHandle,&QTimer::timeout,this,&Dinasor::SCheck); // Conecta o sinal timeou do timer ao slot SCheck
    SHandle->start(15);
    is_walking=true;

}

void Dinasor::SCheck(){
    if(is_walking==false){
        SHandle->stop();
        return;
    }
    if(situation=="Up"){
        // Quando shetab chega a 0, atingiu altura máxima
        if(shetab==0){
            situation = "Down";
        }
        setPos(x(),y()-shetab); // Subtrai shetab da posição Y
        shetab--; // Diminui shetab próximo pulo será menor
    }
    else if(situation=="Down"){
        if(shetab==15){  // Quando shetab volta a 15 chegou no chão
            this->setPos(55,443);
            situation = "Stable";
        }
        setPos(x(),y()+shetab);
        shetab++;
    }
}
