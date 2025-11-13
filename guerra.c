#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "guerra.h"

void exibirMapa(int territorios[], int exercitos[]) {
    printf("\n--- Mapa Atual ---\n");
    for (int i = 0; i < 6; i++) {
        printf("Território %d - Dono: %s - Exércitos: %d\n",
               i,
               territorios[i] == 0 ? "Neutro" :
               territorios[i] == 1 ? "Jogador 1" : "Jogador 2",
               exercitos[i]);
    }
}

void atacar(int territorios[], int exercitos[], int origem, int destino, int jogador) {
    if (exercitos[origem] < 2) {
        printf("Não há exércitos suficientes para atacar (mínimo 2).\n");
        return;
    }

    int ataque = rand() % 6 + 1;
    int defesa = rand() % 6 + 1;

    printf("Dado do atacante: %d\n", ataque);
    printf("Dado do defensor: %d\n", defesa);

    if (ataque > defesa) {
        printf("Ataque bem-sucedido!\n");
        territorios[destino] = jogador;
        exercitos[origem] -= 1;
        exercitos[destino] = 1;
    } else {
        printf("Defesa bem-sucedida!\n");
        exercitos[origem] -= 1;
    }
}

int verificarVencedor(int territorios[]) {
    int count1 = 0, count2 = 0;
    for (int i = 0; i < 6; i++) {
        if (territorios[i] == 1) count1++;
        else if (territorios[i] == 2) count2++;
    }

    if (count1 == 6) return 1;
    if (count2 == 6) return 2;
    return 0;
}
