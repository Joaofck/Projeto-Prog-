# Análise orientada a objeto

## Descrição Geral do domínio do problema

 O domínio do problema envolve o controle de um personagem principal, um dinossauro T-Rex, que corre automaticamente em um cenário desértico. O jogador deve evitar obstáculos — realizando saltos no momento certo.

## Diagrama Casos de Uso
<img width="424" height="466" alt="Capturar" src="https://github.com/user-attachments/assets/c45550c7-3a63-465e-b8b3-7ccd23c7d815" />

**Iniciar Jogo**
Descrição: Ação inicial que coloca o sistema em funcionamento
Configura ambiente inicial, pontuação zerada, estado "pronto para jogar"

**Pular**
Descrição: Comando do jogador para fazer o personagem saltar obstáculos

**Agachar**
Descrição: Ação para evitar obstáculos altos (não implementada no código)

**Reiniciar Jogo**
Descrição: Recomeça o jogo após game over
Reseta pontuação, velocidade, remove obstáculos, recria elementos iniciais

## Diagrama de Classes

<img width="581" height="385" alt="Classe" src="https://github.com/user-attachments/assets/b4f17e03-adea-4b66-bbd3-fe7041c57256" />
