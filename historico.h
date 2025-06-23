#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <string.h>
#include "jogador.h"
#include "configs.h"
#include "arquivo.h"

char nomeArquivoHistorico[100];

int historico_iniciar(opc *opcoes) {
    if (opcoes->modoDeSalvamento == 1) {
        if (!arq_gerarcData(nomeArquivoHistorico)) {
            strcpy(nomeArquivoHistorico, "partida.txt");
        }
    } else {
        strcpy(nomeArquivoHistorico, "partida.txt");
        FILE *arq = fopen(nomeArquivoHistorico, "w");
        if (arq) fclose(arq);
    }
    return 1;
}

int historico_registrar(tp_jogador *jogador, char acao[]) {
    FILE *arq = fopen(nomeArquivoHistorico, "a");
    if (!arq) return 0;

    fprintf(arq, "%s: %s\n", jogador->nome, acao);

    fclose(arq);
    return 1;
}

#endif
