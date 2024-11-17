#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "keyboard.h"
#include "screen.h"
#include "timer.h"

#define COLUNAS 40
#define LINHAS 19
#define MAX_SCORES 5

typedef struct {
    int x, y;
} Ponto;

typedef struct {
    Ponto *partes;
    int comprimento;
} Cobra;

typedef struct {
    Ponto local;
} Alimento;

typedef struct {
    int score;
    char nome[50];
} Placar;

Cobra cobra;
Alimento comida;
int direcaoX = 1;
int direcaoY = 0;
int jogoAtivo = 1;
char nomeJogador[50];

void iniciarJogo() {
    printf("Digite seu nome: ");
    scanf("%s", nomeJogador);

    screenHideCursor();
    keyboardInit();
    timerInit(55);

    cobra.comprimento = 1;
    cobra.partes = (Ponto *)malloc(cobra.comprimento * sizeof(Ponto));
    if (cobra.partes == NULL) {
        printf("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    cobra.partes[0].x = COLUNAS / 2;
    cobra.partes[0].y = LINHAS / 2;
}

void desenharLimites() {
    screenClear();
    printf("┌");
    for (int i = 0; i < COLUNAS; i++)
        printf("─");
    printf("┐\n");
    for (int j = 0; j < LINHAS; j++) {
        printf("│");
        for (int i = 0; i < COLUNAS; i++)
            printf(" ");
        printf("│\n");
    }
    printf("└");
    for (int i = 0; i < COLUNAS; i++)
        printf("─");
    printf("┘");
}

void desenharJogo() {
    for (int i = 0; i < cobra.comprimento; i++) {
        screenGotoxy(cobra.partes[i].x, cobra.partes[i].y);
        printf("0");
    }
    screenUpdate();
}

void criarComida() {
    int valido;
    do {
        valido = 1;
        comida.local.x = rand() % COLUNAS;
        comida.local.y = rand() % LINHAS;

        for (int i = 0; i < cobra.comprimento; i++) {
            if (cobra.partes[i].x == comida.local.x && cobra.partes[i].y == comida.local.y) {
                valido = 0;
                break;
            }
        }
    } while (!valido);
}



void atualizarJogo() {
    if (!jogoAtivo) return;

    int novaX = (cobra.partes[0].x + direcaoX + COLUNAS) % COLUNAS;
    int novaY = (cobra.partes[0].y + direcaoY + LINHAS) % LINHAS;

    if (novaX == comida.local.x && novaY == comida.local.y) {
        cobra.comprimento++;
        cobra.partes = (Ponto *)realloc(cobra.partes, cobra.comprimento * sizeof(Ponto));
        criarComida();
    } else {
        screenGotoxy(cobra.partes[cobra.comprimento - 1].x, cobra.partes[cobra.comprimento - 1].y);
        printf(" ");
    }

    for (int i = cobra.comprimento - 1; i > 0; i--) {
        cobra.partes[i] = cobra.partes[i - 1];
    }

    cobra.partes[0].x = novaX;
    cobra.partes[0].y = novaY;
}

int main() {
    iniciarJogo();
    criarComida();
    desenharLimites();
    desenharJogo();

    while (jogoAtivo) {
        if (timerTimeOver()) {
            atualizarJogo();
            desenharJogo();
        }
    }
    return 0;
}


