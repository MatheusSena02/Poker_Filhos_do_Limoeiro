#ifndef CARTAS_H
#define CARTAS_H
#include <stdio.h>
#include <string.h>

typedef struct {
    int ID;
    int naipe; // ♥(0)[copas], ♦(1)[ouros], ♠(2)[espadas], ♣(3)[paus]
    int valor_i; //1,2,3,4,5,6,7,8,9,10,11,12,13
    char valor_c[4]; //A,2,3,4,5,6,7,8,9,J,Q,K
}tp_carta;

#include "pilhaLEcarta.h"
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

void carta_printarP(tp_carta *carta) {
    // Printa a carta dada
    char  simbolo_naipe[4][8] = {"\u2665", "\u2666", "\u2660", "\u2663"};  // ♥, ♦, ♠, ♣;
 
        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m    \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D    \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m   \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D   \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m    \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D    \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m   \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D   \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        }
    printf("\e[3A\e[1C");
}

void carta_printarP_verso() {
    // Printa a carta dada
    printf("xxxxx\e[1B\e[5D\e[41;37m\e[1mx\e[22mxxxx\e[1B\e[5Dxx\e[1mx\e[22mxx\e[1B\e[5Dxxxx\e[1mx\e[22m\e[49;39m");
    printf("\e[3A\e[1C");
}

void carta_printarG_verso() {
    // Printa a carta dada
    printf("         \e[1B\e[9D\e[41;37mXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[49m\e[39m");
    printf("\e[7A\e[1C");
}

void carta_printarG(tp_carta *carta) {
    // Printa a carta dada
    char  simbolo_naipe[4][8] = {"\u2665", "\u2666", "\u2660", "\u2663"};  // ♥, ♦, ♠, ♣;
 
        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf("         \e[1B\e[9D\e[107m\e[91m         \e[1B\e[9D  %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s  \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("         \e[1B\e[9D\e[107m\e[91m         \e[1B\e[9D %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf("         \e[1B\e[9D\e[107m\e[30m         \e[1B\e[9D  %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s  \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("         \e[1B\e[9D\e[107m\e[30m         \e[1B\e[9D %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
        }

    printf("\e[7A\e[1C");
}

void baralho_printarP (tp_pilhaLEcarta *baralhoJogo) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralhoJogo usando cartas pequenas
    //Precisa receber uma pilhaLEcarta 
    int cont=0;
    tp_pilhaLEcarta *pilha_aux;
    tp_pilhaLEcarta_item carta;
    //cria e inicializa uma pilha auxiliar
    pilha_aux=pilhaLEcarta_inicializar();
    
    while (!pilhaLEcarta_verificar_vazia(baralhoJogo))
          {
           pilhaLEcarta_pop(baralhoJogo,&carta);
           carta_printarP(&carta);
           fflush(stdout);
           pilhaLEcarta_push(pilha_aux, carta);
           if (cont==12||cont==25||cont==38||cont==51) printf("\e[5E");
           cont++;           
           }
   
   while (!pilhaLEcarta_verificar_vazia(pilha_aux))
          {
           pilhaLEcarta_pop(pilha_aux,&carta);
           pilhaLEcarta_push(baralhoJogo, carta);           
           }
    pilha_aux = pilhaLEcarta_destruir(pilha_aux);

}

void baralho_printarG (tp_pilhaLEcarta *baralhoJogo) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralhoJogo usando cartas grandes
    //Precisa receber uma pilhaLEcarta 

    int cont=0;
    tp_pilhaLEcarta *pilha_aux;
    tp_pilhaLEcarta_item carta;
    //cria e inicializa uma pilha auxiliar
    pilha_aux=pilhaLEcarta_inicializar();
    
    while (!pilhaLEcarta_verificar_vazia(baralhoJogo))
          {
           pilhaLEcarta_pop(baralhoJogo,&carta);
           carta_printarG(&carta);
           fflush(stdout);
           pilhaLEcarta_push(pilha_aux, carta);
           if (cont==12||cont==25||cont==38||cont==51) printf("\e[8E");
           cont++;  
           }
   
   while (!pilhaLEcarta_verificar_vazia(pilha_aux))
          {
           pilhaLEcarta_pop(pilha_aux,&carta);
           pilhaLEcarta_push(baralhoJogo, carta);           
           }
    pilha_aux = pilhaLEcarta_destruir(pilha_aux);

}


int baralho_embaralhar(tp_carta baralhoReferencia[],tp_pilhaLEcarta *baralhoJogo){
    int aleat;
    tp_carta aux;
    for(int i=0;i<52;i++){
        aleat=aleatorio(i, 51);
        aux = baralhoReferencia[i];
        baralhoReferencia[i] = baralhoReferencia[aleat];
        baralhoReferencia[aleat] = aux;
    }
    for (int i=0;i<52;i++){
        pilhaLEcarta_push(baralhoJogo,baralhoReferencia[i]);
    }
}

int baralho_distribuirCartas_jogadores(tp_pilhaLEcarta *baralhoJogo, tp_jogador jogador[], int quant){
    tp_pilhaLEcarta_item e;
    for(int i = 0; i < quant; i++){
        if (!pilhaLEcarta_pop(baralhoJogo, &e)) return 0;
        jogador[i].mao[0] = e;
        if (!pilhaLEcarta_pop(baralhoJogo, &e)) return 0;
        jogador[i].mao[1] = e;
    }
    return 1;
}

int mesa_mao_inicializar(int mao_mesa[]){
    for(int i=0;i<5;i++){
        mao_mesa[i]=-1;
    }
}

/*int baralho_distribuirCartas_mesa(tp_pilhaLEcarta *baralhoJogo, int mao_mesa[]){
    int cm;
    
    for(int i=0;i<5;i++){
        if(mao_mesa[i] == -1){
            pilhaLEcarta_pop(baralhoJogo, &cm);
            mao_mesa[i] = cm;
            return i;
        }
        
    }
    return -1;


}

int baralho_mesa_numeroCartas(int mao_mesa[]){
    int numeroCartas = 0;
    for(int i=0;i<5;i++){
        if(mao_mesa[i] != -1){
            numeroCartas++;
        }
    }
}
*/













#endif