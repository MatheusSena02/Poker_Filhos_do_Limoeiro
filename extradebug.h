#ifndef EXTRADEBUG_H
#define EXTRADEBUG_H

void debug1(tp_carta *baralhoReferencia, opc opcoes, tp_pilha *baralhoJogo) {
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[5EBaralho Original:\n");
    baralhoReferencia_printar(baralhoReferencia,opcoes.estiloCarta);
    printf("\e[5E");
    programa_pausar();
    limparTela();
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[5EBaralho Embaralhado:\n");
    baralho_printar(baralhoReferencia,opcoes.estiloCarta,*baralhoJogo);
    printf("\e[5E");
    programa_pausar();
    limparTela();
}


#endif