#ifndef COMBINACOES.H
#define COMBINACOES.H

<<<<<<< Updated upstream
#include "cartas.h"
#include "jogador.h"

=======
>>>>>>> Stashed changes
//Tentativa de Combinação de 1 par
void combinacao_1par_verificar (tp_jogador *jogador, tp_carta baralho[], tp_carta mesa[]) {
    tp_carta cartas[2];

    int cartas_da_mesa;
    int cartas_total = 0;

    //Pegar as cartas do jogador
    cartas[0] = baralho[jogador->mao[0]];
    cartas[1] = baralho[jogador->mao[1]];
    cartas_total = 2;

   //Pegar as cartas da mesa
   for(int i = 0; i< cartas_da_mesa; i++) {
    cartas[i + 2] = mesa;
    cartas_total++;
   }

   int quant_de_cartas = 2 + mesa[i];

   int pares = 0;

   //Comparar as cartas para achar 1 par
    for(int i = 0; i < cartas_total; i++) {
        for (int j = i+1; j < total; j++) {
            if(cartas[i].valor_i == cartas[j].valor_i) {
                pares++;
            }
        }
    }

if (pares == 1) {
    printf("Combinção formaqda: Um Par");
} else if (pares == 2) {
    printf("Combinação formada: Dois Pares");
} else {
    ("   ");
    }
}

#endif