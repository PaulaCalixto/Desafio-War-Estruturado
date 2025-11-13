#ifndef GUERRA_H
#define GUERRA_H

void exibirMapa(int territorios[], int exercitos[]);
void atacar(int territorios[], int exercitos[], int origem, int destino, int jogador);
int verificarVencedor(int territorios[]);

#endif
