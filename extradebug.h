#ifndef EXTRADEBUG_H
#define EXTRADEBUG_H

void debug_mostrarBaralhos(tp_carta *baralhoReferencia, opc opcoes, tp_pilhaSEcarta *baralhoJogo) {
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[5EBaralho Embaralhado P:\n");
    baralho_printarP(baralhoJogo);
    printf("\e[5E");
    programa_pausar();
    limparTela();
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[2EBaralho Embaralhado G:\n");
    baralho_printarG(baralhoJogo);
    printf("\e[5E");
    programa_pausar();
    limparTela();
}

void debug_jogador_escolherNomes(tp_jogador jogador[],int quant){
    int cont=0;
    char nomes[6][20]={"Felix","Marzia","Cinna","Ludwig","Jaiden","Pedro"};

    for(int i=0;i<quant;i++){
        switch(cont){
            case 0:
            strcpy(jogador[i].cor,"38;2;38;198;218");
            break;

            case 1:
            strcpy(jogador[i].cor,"38;2;255;23;68");
            break;

            case 2:
            strcpy(jogador[i].cor,"38;2;205;220;57");
            break;

            case 3:
            strcpy(jogador[i].cor,"38;2;255;152;0");
            break;

            case 4:
            strcpy(jogador[i].cor,"38;2;213;0;249");
            break;

            case 5:
            strcpy(jogador[i].cor,"38;2;255;209;128");
            break;
        }
        jogador[i].ID=i;
        jogador[i].dinheiro=0;
        jogador[i].aposta=0;
        strcpy(jogador[i].nome,nomes[i]);
        cont++;
    }
    limparTela();
    printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("                          TODOS OS JOGADORES CADASTRADOS                           \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i=0; i<quant;i++) {
        printf("\e[%sm",jogador[i].cor);
        printf("  Jogador [%d]: %s\n",i+1,jogador[i].nome);
        printf("\e[39m");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void debug_mostrarMaos (tp_carta baralhoReferencia[],tp_jogador jogador[],int quant) {
    printf("Maos dos jogadores:\n");
    for (int i=0;i<quant;i++){
        printf("Jogador %d: ",i);
        carta_printarP(&jogador[i].mao[0]);
        carta_printarP(&jogador[i].mao[1]);
        printf("\n\n\n\n");
    }
    programa_pausar();
    limparTela();
}

#endif