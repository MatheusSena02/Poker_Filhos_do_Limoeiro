#ifndef JOGADOR_H 
#define JOGADOR_H
#include <stdio.h>
#include <string.h>
#include "cartas.h"
#include "elementosvisuais.h"

typedef struct{
    int ID;
    char nome[30], cor[16];
    int mao[2];
    float dinheiro;
    float aposta;
}tp_jogador;

typedef struct{
    float maiorAposta;
    float pote;
}tp_pote;


int jogador_escolherQuantidade(){
    int quant=0, check=0;
    
    printf("Digite a quantidade de jogadores(2-6): \n");
    scanf("%d", &quant);
    
    while(quant<2 || quant>6){
        printf("Quantidade de jogadores inválida!\n");
        printf("Digite um novo Valor: ");
        
        scanf("%d", &quant);
        if(quant>=2 && quant<=6) break;
    }
    return quant;
}

void jogador_cadastroImpressao(tp_jogador jogador[],int player) {
    switch(player) {

        case 1:
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                 INSIRA O JOGADOR 1                                \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                                                                   \n");
            printf("                                      /\\_/\\                                      \n");
            printf("                                    (> o.o <)                                      \n");
            printf("                                    ( '   ' )                                      \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");           
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                               JOGADORES CADASTRADOS                               \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[H\e[8E\e[36C");
        break;

        case 2:
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                 INSIRA O JOGADOR 2                                \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                                                                   \n");
            printf("                                      /\\_/\\                                        \n");
            printf("                                    (> o.o <)                                      \n");
            printf("                                    ( '   ' )                                      \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");           
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                       (\\(\\                                        \n");
            printf("                                      ( -.- )                                      \n");
            printf("                                    o(_('')('')                                    \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                               JOGADORES CADASTRADOS                               \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[%sm",jogador[0].cor);
            printf("  Jogador [1]: %s\n",jogador[0].nome);
            printf("\e[39m");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[H\e[8E\e[36C");
            printf("\e[%sm",jogador[0].cor);
            printf("%.11s",jogador[0].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[36C");

        break;

        case 3:
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                 INSIRA O JOGADOR 3                                \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                                                                   \n");
            printf("                           /\\_/\\                                                   \n");
            printf("                         (> o.o <)                (O)   (O)                          \n");
            printf("                         ( '   ' )                (  ---  )                          \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");           
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                       (\\(\\                                        \n");
            printf("                                      ( -.- )                                      \n");
            printf("                                    o(_('')('')                                    \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                               JOGADORES CADASTRADOS                               \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[%sm",jogador[0].cor);
            printf("  Jogador [1]: %s\n",jogador[0].nome);
            printf("\e[%sm",jogador[1].cor);
            printf("  Jogador [2]: %s\n",jogador[1].nome);
            printf("\e[39m");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[H\e[8E\e[24C");
            printf("\e[%sm",jogador[0].cor);
            printf("%.11s",jogador[0].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[36C");
            printf("\e[%sm",jogador[1].cor);
            printf("%.11s",jogador[1].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[49C");
            
        break;

        case 4:
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                 INSIRA O JOGADOR 4                                \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                                                                   \n");
            printf("                           /\\_/\\                                                   \n");
            printf("                         (> o.o <)                (O)   (O)                          \n");
            printf("                         ( '   ' )                (  ---  )                          \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");           
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                          (\\(\\                      /\\_/\\                         \n");
            printf("                         ( -.- )                  (  'o'  )                           \n");
            printf("                       o(_('')('')                (   .   )                           \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                               JOGADORES CADASTRADOS                               \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[%sm",jogador[0].cor);
            printf("  Jogador [1]: %s\n",jogador[0].nome);
            printf("\e[%sm",jogador[1].cor);
            printf("  Jogador [2]: %s\n",jogador[1].nome);
            printf("\e[%sm",jogador[2].cor);
            printf("  Jogador [3]: %s\n",jogador[2].nome);
            printf("\e[39m");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[H\e[8E\e[24C");
            printf("\e[%sm",jogador[0].cor);
            printf("%.11s",jogador[0].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[24C");
            printf("\e[%sm",jogador[1].cor);
            printf("%.11s",jogador[1].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[49C");
            printf("\e[%sm",jogador[2].cor);
            printf("%.11s",jogador[2].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[49C");
        break;
        
        case 5:
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                 INSIRA O JOGADOR 5                                \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                                                                   \n");
            printf("                    /\\_/\\                                 ()   ()                  \n");
            printf("                  (> o.o <)          (O)   (O)            (• ' •)                    \n");
            printf("                  ( '   ' )          (  ---  )          ~~(     )                    \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");           
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                          (\\(\\                      /\\_/\\                         \n");
            printf("                         ( -.- )                  (  'o'  )                           \n");
            printf("                       o(_('')('')                (   .   )                           \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                               JOGADORES CADASTRADOS                               \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[%sm",jogador[0].cor);
            printf("  Jogador [1]: %s\n",jogador[0].nome);
            printf("\e[%sm",jogador[1].cor);
            printf("  Jogador [2]: %s\n",jogador[1].nome);
            printf("\e[%sm",jogador[2].cor);
            printf("  Jogador [3]: %s\n",jogador[2].nome);
            printf("\e[%sm",jogador[3].cor);
            printf("  Jogador [4]: %s\n",jogador[3].nome);
            printf("\e[39m");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[H\e[8E\e[17C");
            printf("\e[%sm",jogador[0].cor);
            printf("%.11s",jogador[0].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[24C");
            printf("\e[%sm",jogador[1].cor);
            printf("%.11s",jogador[1].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[36C");
            printf("\e[%sm",jogador[2].cor);
            printf("%.11s",jogador[2].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[49C");
            printf("\e[%sm",jogador[3].cor);
            printf("%.11s",jogador[3].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[55C");
        break;
        
        case 6:
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                 INSIRA O JOGADOR 6                                \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                                                                                   \n");
            printf("                    /\\_/\\                                 ()   ()                  \n");
            printf("                  (> o.o <)          (O)   (O)            (• ' •)                    \n");
            printf("                  ( '   ' )          (  ---  )          ~~(     )                    \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");           
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("           \e[90m██\e[39m\e[32m█████████████████████████████████████████████████████████\e[39m\e[90m██\e[39m             \n");
            printf("            \e[90m██\e[39m\e[32m███████████████████████████████████████████████████████\e[39m\e[90m██\e[39m              \n");
            printf("             \e[90m███\e[39m\e[32m███████████████████████████████████████████████████\e[39m\e[90m███\e[39m               \n");
            printf("               \e[90m███████\e[39m\e[32m███████████████████████████████████████\e[39m\e[90m███████\e[39m                 \n");
            printf("                    \e[90m███████████████████████████████████████████\e[39m                                              \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("                   (\\(\\                /\\_/\\            _∩____∩_                   \n");
            printf("                  ( -.- )            (  'o'  )         |  • ᴥ • |                      \n");
            printf("                o(_('')('')          (   .   )        /|    O   |\\                    \n");
            printf("                                                                                   \n");
            printf("                                                                                   \n");
            printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("                               JOGADORES CADASTRADOS                               \n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[%sm",jogador[0].cor);
            printf("  Jogador [1]: %s\n",jogador[0].nome);
            printf("\e[%sm",jogador[1].cor);
            printf("  Jogador [2]: %s\n",jogador[1].nome);
            printf("\e[%sm",jogador[2].cor);
            printf("  Jogador [3]: %s\n",jogador[2].nome);
            printf("\e[%sm",jogador[3].cor);
            printf("  Jogador [4]: %s\n",jogador[3].nome);
            printf("\e[%sm",jogador[4].cor);
            printf("  Jogador [5]: %s\n",jogador[4].nome);
            printf("\e[39m");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\e[H\e[8E\e[17C");
            printf("\e[%sm",jogador[0].cor);
            printf("%.11s",jogador[0].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[17C");
            printf("\e[%sm",jogador[1].cor);
            printf("%.11s",jogador[1].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[36C");
            printf("\e[%sm",jogador[2].cor);
            printf("%.11s",jogador[2].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[36C");
            printf("\e[%sm",jogador[3].cor);
            printf("%.11s",jogador[3].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[55C");
            printf("\e[%sm",jogador[4].cor);
            printf("%.11s",jogador[4].nome);
            printf("\e[39m");
            printf("\e[H\e[25E\e[55C");
        break;
    }
}

void jogador_escolherNomes(tp_jogador jogador[],int quant){
    int cont=0;

    for(int i=0;i<quant;i++){
        limparTela();

        switch(cont){
            case 0:
            strcpy(jogador[i].cor,"38;2;38;198;218");
            break;

            case 1:
            strcpy(jogador[i].cor,"38;2;255;23;68");
            break;

            case 2:
            strcpy(jogador[i].cor,"38;2;255;152;0");
            break;

            case 3:
            strcpy(jogador[i].cor,"38;2;76;175;80");
            break;

            case 4:
            strcpy(jogador[i].cor,"38;2;213;0;249");
            break;

            case 5:
            strcpy(jogador[i].cor,"38;2;255;209;128");
            break;
        }
        jogador[i].ID=i;
        jogador_cadastroImpressao(jogador,(i+1));
        printf("\e[%sm",jogador[i].cor);
        scanf(" %[^\n]s",jogador[i].nome);
        printf("\e[39m");
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


int menu_jogo_navegar_aposta (tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {
    //Função para permitir a navegação no menu de jogoo usando A,D e F
    // D = 100
    // A = 97
    // F = 102
    // Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
    // O F serve pra confirmar a seleção
    // A posição 0 é a mais a esquerda
     int numeroDeOpcoes=2;
    //impressao
    desenhar_aumentar(cursor);
    //^

    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 100 && input != 97 && input != 102);

    switch(input) {
        case 97:
            if ((cursor->navegador - 1)>=0) cursor->navegador-=1;
            else cursor->navegador=(numeroDeOpcoes-1);
        break;
   
        case 100:
            if ((cursor->navegador + 1) < numeroDeOpcoes) cursor->navegador+=1;
            else cursor->navegador=0;
        break;
    
        case 102:
            switch (cursor->navegador) {
                case 0:// confirma 0
                    return 0;
                break;
    
                case 1: //confirma 1
                    return 1;
                break;
            }
        break;
    }
    
    return -1;
}

int menu_jogo_navegar (tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {
    //Função para permitir a navegação no menu de jogoo usando A,D e F
    // D = 100
    // A = 97
    // F = 102
    // Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
    // O F serve pra confirmar a seleção
    // A posição 0 é a mais a esquerda
     int numeroDeOpcoes=3;
    //impressao
    desenhar_seletor(cursor);
    //^

    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 100 && input != 97 && input != 102);

    switch(input) {
        case 97:
            if ((cursor->navegador - 1)>=0) cursor->navegador-=1;
            else cursor->navegador=(numeroDeOpcoes-1);
        break;
   
        case 100:
            if ((cursor->navegador + 1) < numeroDeOpcoes) cursor->navegador+=1;
            else cursor->navegador=0;
        break;
    
        case 102:
            switch (cursor->navegador) {
                case 0:// confirma 0
                    return 0;
                break;
    
                case 1: //confirma 1
                    return 1;
                break;
    
                case 2: //confirma 2
                    return 2;
                break;
            }
        break;
    }
    
    return -1;
}

void desenhar_menu_jogador(tp_jogador jogador) {
    desenhar_cabecalho(jogador.cor,jogador.nome,jogador.ID);
    desenhar_dinheiro(jogador.dinheiro);
}

int jogo_jogador_rodada(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {

    desenhar_pote(pote->pote);
    desenhar_menu_jogador(*jogador);


    desenhar_limpar_seletorEaumentar();
    desenhar_bordaseletor();
    int escolha=-1;
    while(escolha == -1) {
    escolha=menu_jogo_navegar(jogador,cursor,pote);
    if (escolha==0) {
        cursor_zerarCursor(cursor);
        while (menu_jogo_navegar_aposta(jogador,cursor,pote)==-1);   
        }
    }
}

#endif
