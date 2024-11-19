# Snake Game 🐍

## **Descrição**
Este é um jogo simples de "Cobra" desenvolvido em C, utilizando funcionalidades de manipulação de tela, teclado e temporização para criar uma experiência de jogo no terminal. O objetivo é controlar a cobra, coletar a comida representada por um asterisco (`*`) e crescer, evitando colidir com o próprio corpo.

---

## **Como Jogar**
1. **Inicie o jogo:**
   - Ao executar o programa, será solicitado que você insira seu nome. Após isso, o jogo começará.

2. **Controles do Jogo:**
   - Use as teclas `W`, `A`, `S`, `D` para mover a cobra:
     - `W`: Para cima.
     - `A`: Para a esquerda.
     - `S`: Para baixo.
     - `D`: Para a direita.
   - Pressione `Q` ou `Esc` para sair do jogo.

3. **Objetivo:**
   - Colete a comida (`*`) para aumentar a pontuação e o comprimento da cobra.
   - Evite colidir com o próprio corpo. Caso isso aconteça, o jogo terminará.

4. **Ranking:**
   - Após o fim do jogo, o placar é atualizado com as maiores pontuações e exibido na tela.

---

## **Requisitos**
- **Compilador C**: GCC ou equivalente.
- **Sistema Operacional**: Unix/Linux (compatível com o uso de ANSI escape codes para controle de tela e teclado).

---

## **Instruções de Compilação**
Este projeto utiliza um **Makefile** para facilitar a compilação. Para compilar o jogo, siga os passos abaixo:

1. **Abra o terminal** na pasta onde os arquivos do projeto estão localizados.
2. **Compile o projeto** com o comando:
   ```bash
   make
   Isso gerará um executável chamado snake_game
   execute o jogo com: ./snake_game
