#ifndef CARTAS_H
#define CARTAS_H
#include <stdio.h>
#include <string.h>
#include "pilha.h"

typedef struct {
    int ID;
    int naipe; // ♥(0)[copas], ♦(1)[ouros], ♠(2)[espadas], ♣(3)[paus]
    int valor_i; //1,2,3,4,5,6,7,8,9,10,11,12,13
    char valor_c[4]; //A,2,3,4,5,6,7,8,9,J,Q,K
}tp_carta;

#include "jogador.h"

int carta_setarvalor(tp_carta *carta, int valor) {
    // Seta o valor da carta atual do baralho para "valor".
    // ele guarda o valor de 2 formas diferentes, uma em caractere (A,2 a 10, J, Q e K) e outra em int (1 a 13)
    carta->valor_i = valor;
    switch (valor) {
        case 1:
        strcpy(carta->valor_c, "A");
        break;

        case 2:
        strcpy(carta->valor_c, "2");
        break;

        case 3:
        strcpy(carta->valor_c, "3");
        break;

        case 4:
        strcpy(carta->valor_c, "4");
        break;

        case 5:
        strcpy(carta->valor_c, "5");
        break;

        case 6:
        strcpy(carta->valor_c, "6");
        break;

        case 7:
        strcpy(carta->valor_c, "7");
        break;

        case 8:
        strcpy(carta->valor_c, "8");
        break;

        case 9:
        strcpy(carta->valor_c, "9");
        break;

        case 10:
        strcpy(carta->valor_c, "10");
        break;

        case 11:
        strcpy(carta->valor_c, "J");
        break;

        case 12:
        strcpy(carta->valor_c, "Q");
        break;

        case 13:
        strcpy(carta->valor_c, "K");
        break;

        default:
        return 0;
    }
    return 1;
}

void baralhoReferencia_inicializar(tp_carta *baralhoReferencia) {
    // Monta o baralho de forma organizada
    // Baralho precisa ser um vetor de struct tp_carta de tamanho 52
    for(int i=0;i<52;i++){
        baralhoReferencia[i].ID = (i+1);
        baralhoReferencia[i].naipe = (i/13);
        carta_setarvalor(&baralhoReferencia[i], ((i%13)+1));
    }
}

void carta_printarP(tp_carta *carta, int estiloCarta) {
    // Printa a carta dada, de acordo com o estilo selecionado 
    char  simbolo_naipe[4][8] = {"\u2665", "\u2666", "\u2660", "\u2663"};  // ♥, ♦, ♠, ♣;
    if (estiloCarta == 1) {
        //Printa o estilo 1
 
        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m    \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D    \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m   \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D   \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m    \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D    \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m   \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D   \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        }

    } else {
        //Printa o estilo 0

        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf(" ___ \e[1B\e[5D|\e[91m\e[1m%s\e[22m\e[39m  |\e[1B\e[5D| \e[91m\e[1m%s\e[22m\e[39m |\e[1B\e[5D|__\e[91m\e[1m%s\e[22m\e[39m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf(" ___ \e[1B\e[5D|\e[91m\e[1m%s\e[22m\e[39m |\e[1B\e[5D| \e[91m\e[1m%s\e[22m\e[39m |\e[1B\e[5D|_\e[91m\e[1m%s\e[22m\e[39m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);

        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf(" ___ \e[1B\e[5D|\e[1m%s\e[22m  |\e[1B\e[5D| \e[1m%s\e[22m |\e[1B\e[5D|__\e[1m%s\e[22m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf(" ___ \e[1B\e[5D|\e[1m%s\e[22m |\e[1B\e[5D| \e[1m%s\e[22m |\e[1B\e[5D|_\e[1m%s\e[22m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
        
        }
    }

    printf("\e[3A\e[1C");
}

void carta_printarG(tp_carta *carta, int estiloCarta) {
    // Printa a carta dada, de acordo com o estilo selecionado 
    char  simbolo_naipe[4][8] = {"\u2665", "\u2666", "\u2660", "\u2663"};  // ♥, ♦, ♠, ♣;
    if (estiloCarta == 1) {
        //Printa o estilo 1
 
        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf("         \e[1B\e[9D\e[107m\e[91m         \e[1B\e[9D  %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s  \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("         \e[1B\e[9D\e[107m\e[91m         \e[1B\e[9D %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf("         \e[1B\e[9D\e[107m\e[30m         \e[1B\e[9D  %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s  \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("         \e[1B\e[9D\e[107m\e[30m         \e[1B\e[9D %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
        }

    } else {
        //Printa o estilo 0

        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf(" _______ \e[1B\e[9D|       |\e[1B\e[9D| \e[91m%s\e[39m     |\e[1B\e[9D|       |\e[1B\e[9D|   \e[91m%s\e[39m   |\e[1B\e[9D|       |\e[1B\e[9D|     \e[91m%s\e[39m |\e[1B\e[9D|_______|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf(" _______ \e[1B\e[9D|       |\e[1B\e[9D|\e[91m%s\e[39m     |\e[1B\e[9D|       |\e[1B\e[9D|   \e[91m%s\e[39m   |\e[1B\e[9D|       |\e[1B\e[9D|     \e[91m%s\e[39m|\e[1B\e[9D|_______|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);

        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf(" _______ \e[1B\e[9D|       |\e[1B\e[9D| %s     |\e[1B\e[9D|       |\e[1B\e[9D|   %s   |\e[1B\e[9D|       |\e[1B\e[9D|     %s |\e[1B\e[9D|_______|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf(" _______ \e[1B\e[9D|       |\e[1B\e[9D|%s     |\e[1B\e[9D|       |\e[1B\e[9D|   %s   |\e[1B\e[9D|       |\e[1B\e[9D|     %s|\e[1B\e[9D|_______|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
        
        }
    }

    printf("\e[7A\e[1C");
}

void baralhoReferencia_printarP (tp_carta *baralhoReferencia, int estiloCarta) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralho Referencia usando cartas pequenas
    //Precisa receber um vetor do struct tp_carta, de tamanho 52
    for (int i=0;i<52;i++){
        carta_printarP(&baralhoReferencia[i],estiloCarta);
        fflush(stdout);
        if (i==12||i==25||i==38||i==51) printf("\e[5E");
    }
}

void baralhoReferencia_printarG (tp_carta *baralhoReferencia, int estiloCarta) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralho Referencia usando cartas grandes
    //Precisa receber um vetor do struct tp_carta, de tamanho 52
    for (int i=0;i<52;i++){
        carta_printarG(&baralhoReferencia[i],estiloCarta);
        fflush(stdout);
        if (i==12||i==25||i==38||i==51) printf("\e[8E");
    }
}

void baralho_printarP (tp_carta *baralhoReferencia, int estiloCarta,tp_pilha baralhoJogo) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralhoReferencia com base nas posições embaralhadas na pilha BaralhoJogo usando cartas pequenas
    //Precisa receber um vetor do struct tp_carta, de tamanho 52, a configuração opcoes->EstiloCarta e a pilha que contém o embaralhamento de posições
    tp_item cartaPos;
    for (int i=0;!pilha_verificar_vazia(&baralhoJogo);i++){
        pilha_pop(&baralhoJogo,&cartaPos);
        carta_printarP(&baralhoReferencia[cartaPos],estiloCarta);
        fflush(stdout);
        if (i==12||i==25||i==38||i==51) printf("\e[5E");
    }
}

void baralho_printarG (tp_carta *baralhoReferencia, int estiloCarta,tp_pilha baralhoJogo) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralhoReferencia com base nas posições embaralhadas na pilha BaralhoJogo usando cartas grandes
    //Precisa receber um vetor do struct tp_carta, de tamanho 52, a configuração opcoes->EstiloCarta e a pilha que contém o embaralhamento de posições
    tp_item cartaPos;
    for (int i=0;!pilha_verificar_vazia(&baralhoJogo);i++){
        pilha_pop(&baralhoJogo,&cartaPos);
        carta_printarG(&baralhoReferencia[cartaPos],estiloCarta);
        fflush(stdout);
        if (i==12||i==25||i==38||i==51) printf("\e[8E");
    }
}


int baralho_embaralharPosicoes(tp_pilha *baralhoJogo){
    int cpf_carta, veri, gaveta[52], tam_gaveta=0;
    pilha_inicializar(baralhoJogo);
    for(int i=0;(!pilha_verificar_cheia(baralhoJogo));i++){
        veri=0;
        cpf_carta=aleatorio(0, 51);
        if(i==0){
            gaveta[0]=cpf_carta;
            pilha_push(baralhoJogo,cpf_carta);
            tam_gaveta++;
        }
        else{
            for(int j=0;j<tam_gaveta;j++){
                if(gaveta[j] == cpf_carta){
                    veri = 1;
                }
            }
                
            if(veri==0){
                gaveta[i]=cpf_carta;
                pilha_push(baralhoJogo,cpf_carta);
                tam_gaveta++;
            }
            else{
                if(veri==1){
                    i-=1;    
                }
            }
            
        }
    }    
}

void distribuirCartas(tp_pilha *baralhoJogo, tp_jogador jogador[], int quant){
    int e;
    for(int i = 0; i < quant; i++){
        pilha_pop(baralhoJogo, &e);
        jogador[i].mao_jogador[0] = e;
        pilha_pop(baralhoJogo, &e);
        jogador[i].mao_jogador[1] = e;
        printf("|%d|%d|", jogador[i].mao_jogador[0], jogador[i].mao_jogador[1]);
    }
}














#endif