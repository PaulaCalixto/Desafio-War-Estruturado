#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "guerra.h"

int main() {
    int territorios[6] = {1, 1, 2, 2, 0, 0}; // 0 = neutro, 1 = jogador 1, 2 = jogador 2
    int exercitos[6] = {5, 5, 5, 5, 3, 3};

    int jogadorAtual = 1;
    int vencedor = 0;

    srand(time(NULL));

    printf("=== DESAFIO WAR - TEMA 1 ===\n");

    while (!vencedor) {
        exibirMapa(territorios, exercitos);

        printf("\nVez do Jogador %d\n", jogadorAtual);
        int origem, destino;
        printf("Escolha o território de origem (0-5): ");
        scanf("%d", &origem);
        printf("Escolha o território de destino (0-5): ");
        scanf("%d", &destino);

        if (territorios[origem] == jogadorAtual && territorios[destino] != jogadorAtual) {
            atacar(territorios, exercitos, origem, destino, jogadorAtual);
        } else {
            printf("Jogada inválida!\n");
        }

        vencedor = verificarVencedor(territorios);
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
    }

    printf("\nFIM DE JOGO! Jogador %d venceu!\n", vencedor);

    return 0;
}
