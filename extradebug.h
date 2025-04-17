#ifndef EXTRADEBUG_H
#define EXTRADEBUG_H

void debug1(tp_carta *baralhoReferencia, opc opcoes, tp_pilha *baralhoJogo) {
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[5EBaralho Original P:\n");
    baralhoReferencia_printarP(baralhoReferencia);
    printf("\e[5E");
    programa_pausar();
    limparTela();
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[5EBaralho Embaralhado P:\n");
    baralho_printarP(baralhoReferencia,*baralhoJogo);
    printf("\e[5E");
    programa_pausar();
    limparTela();
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[2EBaralho Original G:\n");
    baralhoReferencia_printarG(baralhoReferencia);
    printf("\e[5E");
    programa_pausar();
    limparTela();
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[2EBaralho Embaralhado G:\n");
    baralho_printarG(baralhoReferencia,*baralhoJogo);
    printf("\e[5E");
    programa_pausar();
    limparTela();
}


#endif