#ifndef CARTAS_H
#define CARTAS_H
#include <stdio.h>
#include <string.h>

typedef struct {
    int ID;
    int naipe; // ♥(0)[espadas], ♦(1)[ouros], ♠(2)[espadas], ♣(3)[paus]
    int valor_i; //1,2,3,4,5,6,7,8,9,10,11,12,13
    char valor_c[4]; //A,2,3,4,5,6,7,8,9,J,Q,K
} tp_carta;

int carta_setarvalor(tp_carta *carta, int valor) {
    // Seta o valor da carta atual do baralho para "valor".
    // valor serve para a função de printar, na parte dos números e letras
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
    for(int i=0;i<52;i++){
        baralho[i].naipe = (i/13);
        carta_setarvalor(&baralho[i], ((i%13)+1));
    }
}

void carta_printar(tp_carta *carta, int estiloCarta) {
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

#endif