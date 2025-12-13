## Diagrama de Classes

<img width="581" height="385" alt="Classe" src="https://github.com/user-attachments/assets/b4f17e03-adea-4b66-bbd3-fe7041c57256" />

Classes Identificadas:
**JogoTRex (Classe Principal)**

Atributos: velocidade, pontuação, gameover

Métodos: iniciar(), atualizar(), agachar(), pular(), colisao(), dificuldade()

**Dinossauro**

Atributos: posiçãoX, posiçãoY, velocidadeX, velocidadeY

Métodos: pular(), agachar(), resetar()

**Obstáculos**

Atributos: posiçãoX, posiçãoY, velocidadeX, velocidadeY, altura, largura

Métodos: mover()

**Chão**

Atributos: posição, velocidade

Métodos: animar()

**Pontuação**

Atributos: pontuação, highScore

Métodos: incrementar(), resetar(), salvar()


<div align="center">

[Retroceder](analise.md) | [Avançar](implementacao.md)

</div>
