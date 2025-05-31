#ifndef COMBINACOES_H
#define COMBINACOES_H

#include "cartas.h"
#include "jogador.h"
#include "listasecarta.h"
#include "pilhasecarta.h"
#include "listadecarta.h"

//Tentativa de Combinação de 1 par
int combinacoes_verificar_valores (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador,tp_combinacaoInfo comparadorValor[]) {

    tp_carta cartas[7];

    int cartas_da_mesa = listaSEcarta_verificar_tamanho(mao_mesa);

    int numcartas = (cartas_da_mesa + 2);

    int cont = 0;
    tp_listasecarta *atu = mao_jogador;

    while (cont < 2) {
        cartas[cont]=atu->info;

        if (jogador->maiorInfo.valor < cartas[cont].valor_i) jogador->maiorInfo.valor=cartas[cont].valor_i;
        if (jogador->maiorInfo.naipe < cartas[cont].naipe) jogador->maiorInfo.naipe=cartas[cont].naipe;

        atu = atu->prox;
        cont++;
    }

    atu = mao_mesa;
    while (cont < numcartas) {
        cartas[cont]=atu->info;
        atu = atu->prox;
        cont++;
    }
   
    
    for(int i=0;i<numcartas;i++) {
        jogador->comparadorValor[cartas[i].valor_i].quant+=1;
        
        if (jogador->comparadorValor[cartas[i].valor_i].naipeMaisAlto < cartas[i].naipe) {
            jogador->comparadorValor[cartas[i].valor_i].naipeMaisAltoReserva = jogador->comparadorValor[cartas[i].valor_i].naipeMaisAlto;
            jogador->comparadorValor[cartas[i].valor_i].naipeMaisAlto=cartas[i].naipe;
        }
    }

    int pares=0;
    int trincas=0;
    int quadras=0;

    for(int i=0;i<15;i++) {
        if (jogador->comparadorValor[i].quant == 2) pares++;
        if (jogador->comparadorValor[i].quant == 3) trincas++;
        if (jogador->comparadorValor[i].quant == 4) quadras++;
    }

    for (int i=0;i<15;i++){
        if (jogador->comparadorValor[i].quant==2) {

            jogador->combinacoes.par.quant = pares;

            if (jogador->combinacoes.par.valorMaisAlto < i) {
                jogador->combinacoes.par.valorMaisAltoReserva = jogador->combinacoes.par.valorMaisAlto;
                jogador->combinacoes.par.valorMaisAlto = i;
            }

            if (jogador->combinacoes.par.naipeMaisAlto < comparadorValor[i].naipeMaisAlto) {
                jogador->combinacoes.par.naipeMaisAltoReserva = jogador->combinacoes.par.naipeMaisAlto;
                jogador->combinacoes.par.naipeMaisAlto = comparadorValor[i].naipeMaisAlto;
            }
        }

        else if (jogador->comparadorValor[i].quant==3) {

            jogador->combinacoes.trinca.quant = trincas;

            if (jogador->combinacoes.trinca.valorMaisAlto < i) {
                jogador->combinacoes.trinca.valorMaisAltoReserva = jogador->combinacoes.trinca.valorMaisAlto;
                jogador->combinacoes.trinca.valorMaisAlto = i;
            }

            if (jogador->combinacoes.trinca.naipeMaisAlto < comparadorValor[i].naipeMaisAlto) {
                jogador->combinacoes.trinca.naipeMaisAltoReserva = jogador->combinacoes.trinca.naipeMaisAlto;
                jogador->combinacoes.trinca.naipeMaisAlto = comparadorValor[i].naipeMaisAlto;
            }
        }

        else if (jogador->comparadorValor[i].quant==4) {

            jogador->combinacoes.quadra.quant = quadras;

            if (jogador->combinacoes.quadra.valorMaisAlto < i) {
                jogador->combinacoes.quadra.valorMaisAltoReserva = jogador->combinacoes.quadra.valorMaisAlto;
                jogador->combinacoes.quadra.valorMaisAlto = i;
            }

            if (jogador->combinacoes.quadra.naipeMaisAlto < comparadorValor[i].naipeMaisAlto) {
                jogador->combinacoes.quadra.naipeMaisAltoReserva = jogador->combinacoes.quadra.naipeMaisAlto;
                jogador->combinacoes.quadra.naipeMaisAlto = comparadorValor[i].naipeMaisAlto;
            }
        }
    }

    if (pares == 1 && trincas == 1) {
        jogador->combinacoes.fullHouse.quant=1;
        jogador->combinacoes.fullHouse.naipeMaisAlto = ((jogador->combinacoes.par.naipeMaisAlto * 2) + (jogador->combinacoes.trinca.naipeMaisAlto * 3));
        jogador->combinacoes.fullHouse.valorMaisAlto = ((jogador->combinacoes.par.valorMaisAlto * 2) + (jogador->combinacoes.trinca.valorMaisAlto * 3));
    }
}

int combinacoes_verificar_naipes (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador,tp_combinacaoInfo comparadorValor[]) {

    tp_carta cartas[7];

    int cartas_da_mesa = listaSEcarta_verificar_tamanho(mao_mesa);

    int numcartas = (cartas_da_mesa + 2);

    int cont = 0;
    tp_listasecarta *atu = mao_jogador;

    while (cont < 2) {
        cartas[cont]=atu->info;

        if (jogador->maiorInfo.valor < cartas[cont].valor_i) jogador->maiorInfo.valor=cartas[cont].valor_i;
        if (jogador->maiorInfo.naipe < cartas[cont].naipe) jogador->maiorInfo.naipe=cartas[cont].naipe;

        atu = atu->prox;
        cont++;
    }

    atu = mao_mesa;
    while (cont < numcartas) {
        cartas[cont]=atu->info;
        atu = atu->prox;
        cont++;
    }
   
    
    for(int i=0;i<numcartas;i++) {
        
        jogador->comparadorNaipe[cartas[i].naipe].quant+=1;
        
        if (jogador->comparadorNaipe[cartas[i].naipe].valorMaisAlto < cartas[i].valor_i) {
            jogador->comparadorNaipe[cartas[i].naipe].valorMaisAltoReserva = jogador->comparadorNaipe[cartas[i].naipe].valorMaisAlto;
            jogador->comparadorNaipe[cartas[i].naipe].valorMaisAlto=cartas[i].valor_i;
        }
    }
    

    int flush=0;


    for(int i=0;i<4;i++) {
        if (jogador->comparadorNaipe[i].quant >= 5) flush++;
    }

    for (int i=0;i<4;i++){
        if (jogador->comparadorNaipe[i].quant>=5) {

            jogador->combinacoes.par.quant = flush;

            if (jogador->combinacoes.flush.naipeMaisAlto < i) {
                jogador->combinacoes.flush.naipeMaisAltoReserva = jogador->combinacoes.flush.naipeMaisAlto;
                jogador->combinacoes.flush.naipeMaisAlto = i;
            } 

            if (jogador->combinacoes.flush.naipeMaisAlto < jogador->comparadorNaipe[i].naipeMaisAlto) {
                jogador->combinacoes.flush.naipeMaisAltoReserva = jogador->combinacoes.flush.naipeMaisAlto;
                jogador->combinacoes.flush.naipeMaisAlto = jogador->comparadorNaipe[i].naipeMaisAlto;
            }
        }
    }
}

int vetor_inteiro_busca_maiorValor(const int vet[], int ini, int fim) {
    int maior  = vet[ini];
    int indice = ini;

    for (int i = ini + 1; i <= fim; i++) {
        if (vet[i] > maior) {
            maior  = vet[i];
            indice = i;
        } else if (vet[i] == maior) {
            indice = i;
        }
    }
    return indice;
}


int vetor_inteiro_maiorValor(int vet[],int ini,int fim) {
    int maior=0;

    for(int i=ini;i<=fim;i++){
        if (vet[i]>=maior) maior=vet[i];
    }

    return maior;
}

int combinacoes_verificar_sequencias (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador) {

    tp_carta cartas[7];

    int cartas_da_mesa = listaSEcarta_verificar_tamanho(mao_mesa);

    int numcartas = (cartas_da_mesa + 2);

    int cont = 0;
    tp_listasecarta *atu = mao_jogador;

    while (cont < 2) {
        cartas[cont]=atu->info;

        if (jogador->maiorInfo.valor < cartas[cont].valor_i) jogador->maiorInfo.valor=cartas[cont].valor_i;
        if (jogador->maiorInfo.naipe < cartas[cont].naipe) jogador->maiorInfo.naipe=cartas[cont].naipe;

        atu = atu->prox;
        cont++;
    }

    atu = mao_mesa;
    while (cont < numcartas) {
        cartas[cont]=atu->info;
        atu = atu->prox;
        cont++;
    }
    
    //Até aq foi pra guardar no vetor

    tp_listadecarta *maoOrdenada;
    maoOrdenada = listaDEcarta_inicializar();

    for(int i=0;i<numcartas;i++) {
        listaDEcarta_inserir_ordenado(maoOrdenada,cartas[i]);
    }

    tp_listadecarta_no *atual = maoOrdenada->ini;
    while (atual!= NULL) {
        carta_printarP(&(atual->info));
        atual=atual->prox;
    }

    printf("\n\n\n\n");

    int ultimovalor=-1;
    int contSequencia[8]={0,0,0,0,0,0,0,0};
  

    atual = maoOrdenada->ini;

    for (int i=0;i<numcartas;i++) {
        if (atual->info.valor_i==(ultimovalor+1)) contSequencia[i]=contSequencia[i-1]+1;
        else if (atual->info.valor_i==ultimovalor) contSequencia[i]=contSequencia[i-1];
        else contSequencia[i]=0;
        carta_printarP(&(atual->info));
        ultimovalor=atual->info.valor_i;
        atual=atual->prox;
    }

    atual = maoOrdenada->fim;

    int maiorSequencia = vetor_inteiro_maiorValor(contSequencia,0,6);
    int PosMaiorSequencia = vetor_inteiro_busca_maiorValor(contSequencia,0,6);
    printf("Maior Sequencia: %d Posição: %d ",maiorSequencia,PosMaiorSequencia);
    if (maiorSequencia>0) {
        int PosAVoltar = (numcartas-1) - PosMaiorSequencia;
        printf("Pos a voltar: %d ",PosAVoltar);
        for(int i=0;i<PosAVoltar;i++){
            maoOrdenada->fim=atual->ant;
            free(atual);
            maoOrdenada->fim->prox=NULL;
            atual = maoOrdenada->fim;
        }

        printf("\n\n\n\n");
        for (int i=0;i<numcartas;i++) printf("[%d] ",contSequencia[i]);


        printf("\n\n\n\n");
        atual = maoOrdenada->ini;
        while (atual!= NULL) {
            carta_printarP(&(atual->info));
            atual=atual->prox;
        }
        printf("\n\n\n\n");


    }

}

#endif