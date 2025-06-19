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
        printf("\n=================================================\n");
        printf("🎉 O VENCEDOR DA RODADA É: %s [ID %d]!\n", jogadores[vencedor].nome, vencedor);
        printf("🏆 Valor da mão (comparador): %d\n", jogadores[vencedor].comparadorValor);
        printf("=================================================\n\n");
    } else {
        printf("\n⚠️  Todos os jogadores desistiram. Sem vencedor.\n");
    }
}
#endif
