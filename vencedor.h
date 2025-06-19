#ifndef VENCEDOR_H
#define VENCEDOR_H

#include <stdio.h>
#include "jogador.h"

void jogo_verificar_vencedor(tp_jogador *jogadores, int quantJogadores) {
    int vencedor = -1;

    for (int i = 0; i < quantJogadores; i++) {
        if (jogadores[i].desistir) continue;

        if (vencedor == -1 || jogadores[i].comparadorValor > jogadores[vencedor].comparadorValor) {
            vencedor = i;
        }
    }

    if (vencedor != -1) {
        printf("\nO vencedor da rodada é o jogador [%d] - %s!\n", vencedor, jogadores[vencedor].nome);
        printf("Comparador de valor da mão: %d\n", jogadores[vencedor].comparadorValor);
    } else {
        printf("\nNenhum jogador venceu. Todos desistiram.\n");
    }
}
#endif
