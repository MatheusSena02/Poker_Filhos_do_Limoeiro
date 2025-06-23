#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <string.h>
#include "configs.h"
#include "jogador.h"

char nomeArquivoHistorico[100] = "jogadas.txt";

// Inicia o histórico: cria ou limpa o arquivo
int historico_iniciar(opc *opcoes) {
    FILE *arq = fopen(nomeArquivoHistorico, "w");
    if (!arq) return 0;
    fprintf(arq, "===== REGISTRO DE JOGADAS =====\n\n");
    fclose(arq);
    return 1;
}

// Registra uma jogada no arquivo
int historico_registrar(tp_jogador *jogador, const char *mensagem) {
    FILE *arq = fopen(nomeArquivoHistorico, "a");
    if (!arq) return 0;
    fprintf(arq, "[%s] %s\n", jogador->nome, mensagem);
    fclose(arq);
    return 1;
}

// Escreve cabeçalho de rodada
int historico_inicio_rodada(int numeroRodada) {
    FILE *arq = fopen(nomeArquivoHistorico, "a");
    if (!arq) return 0;
    fprintf(arq, "\n--- INÍCIO DA RODADA %d ---\n", numeroRodada);
    fclose(arq);
    return 1;
}

#endif
