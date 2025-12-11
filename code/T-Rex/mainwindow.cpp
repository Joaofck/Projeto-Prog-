#include "mainwindow.h"
#include "ground.h"
#include <QList>
#include <QFont>
#include "cactus.h"
#include <QDebug>
using namespace std;

int MainWindow::score=0;

// Construtor da MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent) // Chama o construtor da classe base QGraphicsView.
{
    //Configuração da Cena
    view = new QGraphicsScene(this);
    setScene(view);
    setFixedSize(800,600);

    //Timer da pontuaçao
    addScore = new QTimer();
    // Conecta o sinal timeout do timer à função Scorehandle
    connect(addScore,&QTimer::timeout,this,&MainWindow::Scorehandle);
    addScore->start(750);

    // Criação do Jogador
    D = new Dinasor();
    view->addItem(D);

    // Criação do Chão Inicial
    Ground* G = new Ground();
    view->addItem(G);


    // Timer do Gerador de Chão
    checkGround = new QTimer();
    connect(checkGround,&QTimer::timeout,this,&MainWindow::creatGround);
    checkGround->start(5);

    // Timer para criar cactus
    cactusTimer = new QTimer();
    connect(cactusTimer, &QTimer::timeout, this, &MainWindow::creatCactus);
    cactusTimer->start(2000);  // Cria cactus a cada 2 segundos

    // Timer para verificar colisões
    collisionTimer = new QTimer();
    connect(collisionTimer, &QTimer::timeout, this, &MainWindow::checkCollision);
    collisionTimer->start(50);  // Verifica colisão a cada 50ms
}

// Cria novos pedaços de chão
void MainWindow::creatGround(){
    // Verifica uma variável estática na classe Ground que sinaliza se há espaço vazio.
    if(Ground::empty==true){
        Ground* newG = new Ground();  //Faz um pedaço novo de chão
        newG->setPos(800,480);
        setSceneRect(0,0,700,700);
        view->addItem(newG);
        Ground::empty=false; // Reseta a flag para indicar que o buraco foi preenchido.
    }
}

// Função para criar cactus
void MainWindow::creatCactus(){
    // Cria um novo cactus com a velocidade atual do chão
    Cactus* cactus = new Cactus(Ground::speed);
    view->addItem(cactus);

    // Intervalo aleatório entre 1 e 3 segundos
    int randomInterval = 1000 + rand() % 1500;
    cactusTimer->start(randomInterval);
}

// Função para verificar colisão
void MainWindow::checkCollision(){
    // Verifica se há colisão entre o dinossauro e qualquer cactus
    QList<QGraphicsItem*> items = view->items();

    for (QGraphicsItem* item : items) {
        Cactus* cactus = dynamic_cast<Cactus*>(item);
        if (cactus) {
            // Verifica colisão usando bounding boxes
            if (D->collidesWithItem(cactus)) {
                qDebug() << "COLISÃO DETECTADA";

                // Para todos os timers
                checkGround->stop();
                addScore->stop();
                cactusTimer->stop();
                collisionTimer->stop();
                Ground::speed = 0;


                // Para o dinossauro
                D->set_walking(false);

                for (QGraphicsItem* cactusItem : view->items()) {
                    Cactus* cactusToStop = dynamic_cast<Cactus*>(cactusItem);
                    if (cactusToStop) {
                        cactusToStop->stop();  // Para o timer individual do cactus
                    }
                }

                // Mostra mensagem de game over
                QGraphicsTextItem *gameOverText = new QGraphicsTextItem();
                gameOverText->setPlainText("GAME OVER!");
                gameOverText->setDefaultTextColor(Qt::black);
                gameOverText->setFont(QFont("Arial", 40, QFont::Bold));
                gameOverText->setPos(100, 300);
                view->addItem(gameOverText);

                return;
            }
        }
    }
}


// Atualiza a pontuação e a dificuldade
void MainWindow::Scorehandle(){
    MainWindow::score++;

    // Loop para remover o texto da pontuação antiga da tela
    foreach(QGraphicsItem *item,scene()->items()){ // Pega todos os itens na cena.
        // Verifica se é texto. Se não for texto, retorna null.
        QGraphicsTextItem* txt =dynamic_cast<QGraphicsTextItem*>(item);
        if(txt){
            view->removeItem(item); // remove ele da cena (para não sobrepor).
        }
    }

    // Cria o novo texto de pontuação
    QGraphicsTextItem *scoreTextItem = new QGraphicsTextItem();
    QString PrintScore= ("Your Score : " + QString::number(score));
    scoreTextItem->setPlainText(PrintScore); // Define o texto do item.
    scoreTextItem->setDefaultTextColor(Qt::black);
    scoreTextItem->setFont(QFont("Arial", 14));
    scoreTextItem->setPos(10, 100); // Posição do placar na tela

    view->addItem(scoreTextItem); // Adiciona o novo placar à cena.

    // Aumenta velocidade do chão progressivamente
    if(Ground::speed<20){ // Se a velocidade ainda não atingiu o máximo 20
        Ground::speed+=0.1; //aumenta a velocidade em 0.1.
        return;
    }
}

// Evento de Teclado
void MainWindow::keyPressEvent(QKeyEvent* K){
    // Verifica se a tecla é ESPAÇO E se o dinossauro está chão.
    if(K->key()==Qt::Key_Space && D->situation=="Stable"){
        D->situation="Up"; // Muda o estado do dinossauro
    }
}

MainWindow::~MainWindow() {}
