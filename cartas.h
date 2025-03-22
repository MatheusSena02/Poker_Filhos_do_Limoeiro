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
} tp_carta;

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

void baralho_inicializar(tp_carta *baralho) {
    // Monta o baralho de forma organizada
    // Baralho precisa ser um vetor de struct tp_carta de tamanho 52
    for(int i=0;i<52;i++){
        baralho[i].ID = (i+1);
        baralho[i].naipe = (i/13);
        carta_setarvalor(&baralho[i], ((i%13)+1));
    }
}

void carta_printar(tp_carta *carta, int estiloCarta) {
    // Printa a carta dada, de acordo com o estilo selecionado 
    char  simbolo_naipe[4][8] = {"\u2665", "\u2666", "\u2660", "\u2663"};  // ♥, ♦, ♠, ♣;
    if (estiloCarta == 1) {
 
        if(carta->naipe == 0 || carta->naipe == 1) {

            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m    \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D    \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m   \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D   \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        } else {
    
            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m    \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D    \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m   \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D   \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        }

    } else {

        if(carta->naipe == 0 || carta->naipe == 1) {

            if(carta->valor_i != 10) printf(" ___ \e[1B\e[5D|\e[91m\e[1m%s\e[22m\e[39m  |\e[1B\e[5D| \e[91m\e[1m%s\e[22m\e[39m |\e[1B\e[5D|__\e[91m\e[1m%s\e[22m\e[39m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf(" ___ \e[1B\e[5D|\e[91m\e[1m%s\e[22m\e[39m |\e[1B\e[5D| \e[91m\e[1m%s\e[22m\e[39m |\e[1B\e[5D|_\e[91m\e[1m%s\e[22m\e[39m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);

        } else {

            if(carta->valor_i != 10) printf(" ___ \e[1B\e[5D|\e[1m%s\e[22m  |\e[1B\e[5D| \e[1m%s\e[22m |\e[1B\e[5D|__\e[1m%s\e[22m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf(" ___ \e[1B\e[5D|\e[1m%s\e[22m |\e[1B\e[5D| \e[1m%s\e[22m |\e[1B\e[5D|_\e[1m%s\e[22m|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
        
        }
    }

    printf("\e[3A\e[2C");
}

void baralho_printar (tp_carta *carta, int estiloCarta) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralho
    //Precisa receber um vetor do struct tp_carta, de tamanho 52
    for (int i=0;i<52;i++){
        carta_printar(&carta[i],estiloCarta);
        fflush(stdout);
        if (i==12||i==25||i==38) printf("\e[5E");
    }
}


int embaralhar_cartas(tp_pilha *baralhoJogo){
    int cpf_carta, veri, gaveta[52], tam_gaveta=0;
    pilha_inicializar(baralhoJogo);
    for(int i=0;(!pilha_cheia(baralhoJogo));i++){
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














#endif