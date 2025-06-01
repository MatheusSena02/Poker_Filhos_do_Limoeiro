#ifndef JOGADOR_H 
#define JOGADOR_H
#include <stdio.h>
#include <string.h>
#include "cartas.h"
#include "elementosvisuais.h"

typedef struct{
    int quant;
    int naipeMaisAlto;
    int valorMaisAlto;
    int naipeMaisAltoReserva;
    int valorMaisAltoReserva;
} tp_combinacaoInfo;

typedef struct{
    tp_combinacaoInfo par;
    tp_combinacaoInfo trinca;
    tp_combinacaoInfo straight;
    tp_combinacaoInfo flush;
    tp_combinacaoInfo fullHouse;
    tp_combinacaoInfo quadra;
    tp_combinacaoInfo straightFlush;
    tp_combinacaoInfo royalFlush;
} tp_combinacoes;

typedef struct{
    int valor;
    int naipe;
} tp_maiorInfo;

typedef struct{
    int ID;
    char nome[30], cor[16];
    tp_listasecarta *mao;
    float dinheiro;
    float aposta;
    int desistir;
    tp_combinacaoInfo comparadorValor[15];
    tp_combinacaoInfo comparadorNaipe[4];
    tp_combinacaoInfo comparadorSequencia;
    tp_combinacoes combinacoes;
    tp_maiorInfo maiorInfo;
}tp_jogador;

typedef struct{
    float maiorAposta;
    float pote;
}tp_pote;


int jogador_escolherQuantidade(){
    console_cursor_visivel();
    int quant=0, check=0;
    
    printf("Digite a quantidade de jogadores(2-6): \n");
    scanf("%d", &quant);
    
    while(quant<2 || quant>6){
        printf("Quantidade de jogadores inválida!\n");
        printf("Digite um novo Valor: ");
        
        scanf("%d", &quant);
        if(quant>=2 && quant<=6) break;
    }
    console_cursor_invisivel();
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
            desenhar_inserirjogadormesa();
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
            desenhar_inserirjogadormesa();
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
            printf("\e[H\e[26E\e[36C");

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
            desenhar_inserirjogadormesa();
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
            printf("\e[H\e[26E\e[36C");
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
            desenhar_inserirjogadormesa();
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
            printf("\e[H\e[26E\e[24C");
            printf("\e[%sm",jogador[1].cor);
            printf("%.11s",jogador[1].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[49C");
            printf("\e[%sm",jogador[2].cor);
            printf("%.11s",jogador[2].nome);
            printf("\e[39m");
            printf("\e[H\e[26E\e[49C");
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
            desenhar_inserirjogadormesa();
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
            printf("\e[H\e[26E\e[24C");
            printf("\e[%sm",jogador[1].cor);
            printf("%.11s",jogador[1].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[36C");
            printf("\e[%sm",jogador[2].cor);
            printf("%.11s",jogador[2].nome);
            printf("\e[39m");
            printf("\e[H\e[26E\e[49C");
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
            desenhar_inserirjogadormesa();
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
            printf("\e[H\e[26E\e[17C");
            printf("\e[%sm",jogador[1].cor);
            printf("%.11s",jogador[1].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[36C");
            printf("\e[%sm",jogador[2].cor);
            printf("%.11s",jogador[2].nome);
            printf("\e[39m");
            printf("\e[H\e[26E\e[36C");
            printf("\e[%sm",jogador[3].cor);
            printf("%.11s",jogador[3].nome);
            printf("\e[39m");
            printf("\e[H\e[8E\e[55C");
            printf("\e[%sm",jogador[4].cor);
            printf("%.11s",jogador[4].nome);
            printf("\e[39m");
            printf("\e[H\e[26E\e[55C");
        break;
    }
}

void jogador_inicializacao(tp_jogador *jogador) {
    for(int i=0;i<15;i++){
        jogador->comparadorValor[i].quant=0;
        jogador->comparadorValor[i].naipeMaisAlto=-1;
        jogador->comparadorValor[i].naipeMaisAltoReserva=-1;
        jogador->comparadorValor[i].valorMaisAlto=-1;
        jogador->comparadorValor[i].valorMaisAltoReserva=-1;
    }
    
    for(int i=0;i<4;i++){
        jogador->comparadorNaipe[i].quant=0;
        jogador->comparadorNaipe[i].naipeMaisAlto=-1;
        jogador->comparadorNaipe[i].naipeMaisAltoReserva=-1;
        jogador->comparadorNaipe[i].valorMaisAlto=-1;
        jogador->comparadorNaipe[i].valorMaisAltoReserva=-1;
    }

    jogador->combinacoes.par.quant=0;
    jogador->combinacoes.par.naipeMaisAlto=-1;
    jogador->combinacoes.par.valorMaisAlto=-1;
    jogador->combinacoes.par.naipeMaisAltoReserva=-1;
    jogador->combinacoes.par.valorMaisAltoReserva=-1;

    jogador->combinacoes.trinca.quant=0;
    jogador->combinacoes.trinca.naipeMaisAlto=-1;
    jogador->combinacoes.trinca.valorMaisAlto=-1;
    jogador->combinacoes.trinca.naipeMaisAltoReserva=-1;
    jogador->combinacoes.trinca.valorMaisAltoReserva=-1;

    jogador->combinacoes.straight.quant=0;
    jogador->combinacoes.straight.naipeMaisAlto=-1;
    jogador->combinacoes.straight.valorMaisAlto=-1;
    jogador->combinacoes.straight.naipeMaisAltoReserva=-1;
    jogador->combinacoes.straight.valorMaisAltoReserva=-1;

    jogador->combinacoes.flush.quant=0;
    jogador->combinacoes.flush.naipeMaisAlto=-1;
    jogador->combinacoes.flush.valorMaisAlto=-1;
    jogador->combinacoes.flush.naipeMaisAltoReserva=-1;
    jogador->combinacoes.flush.valorMaisAltoReserva=-1;

    jogador->combinacoes.fullHouse.quant=0;
    jogador->combinacoes.fullHouse.naipeMaisAlto=-1;
    jogador->combinacoes.fullHouse.valorMaisAlto=-1;
    jogador->combinacoes.fullHouse.naipeMaisAltoReserva=-1;
    jogador->combinacoes.fullHouse.valorMaisAltoReserva=-1;

    jogador->combinacoes.quadra.quant=0;
    jogador->combinacoes.quadra.naipeMaisAlto=-1;
    jogador->combinacoes.quadra.valorMaisAlto=-1;
    jogador->combinacoes.quadra.naipeMaisAltoReserva=-1;
    jogador->combinacoes.quadra.valorMaisAltoReserva=-1;

    jogador->combinacoes.straightFlush.quant=0;
    jogador->combinacoes.straightFlush.naipeMaisAlto=-1;
    jogador->combinacoes.straightFlush.valorMaisAlto=-1;
    jogador->combinacoes.straightFlush.naipeMaisAltoReserva=-1;
    jogador->combinacoes.straightFlush.valorMaisAltoReserva=-1;

    jogador->combinacoes.royalFlush.quant=0;
    jogador->combinacoes.royalFlush.naipeMaisAlto=-1;
    jogador->combinacoes.royalFlush.valorMaisAlto=-1;
    jogador->combinacoes.royalFlush.naipeMaisAltoReserva=-1;
    jogador->combinacoes.royalFlush.valorMaisAltoReserva=-1;
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
        jogador[i].dinheiro=1000;
        jogador[i].aposta=0;
        jogador[i].desistir=0;

        jogador[i].maiorInfo.naipe=-1;
        jogador[i].maiorInfo.valor=-1;

        jogador_inicializacao(&jogador[i]);
        
        jogador_cadastroImpressao(jogador,(i+1));

        printf("\e[%sm",jogador[i].cor);
        console_cursor_visivel();
        scanf(" %[^\n]s",jogador[i].nome);
        console_cursor_invisivel();
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

void desenhar_aumentar_aposta_percentual_selecao(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {

    char corfora[4][18]={"38;2;129;212;250","38;2;129;212;250","38;2;129;212;250","38;2;129;212;250"};
    char cordentro[4][18]={"38;2;33;150;243","38;2;33;150;243","38;2;33;150;243","38;2;33;150;243"};
    strcpy(corfora[cursor->navegador],"38;2;227;242;253");
    strcpy(cordentro[cursor->navegador],"38;2;140;158;255");

    //0
    printf("\e[48;2;33;150;243m\e[39E");
    printf("\e[54C\e[%sm██25%%\e[E",corfora[0]);
    printf("\e[52C██\e[%sm██\e[%sm██\e[E",cordentro[0],corfora[0]);
    printf("\e[54C██\e[E");
    printf("\e[0m");
    printf("\e[H");
    //1
    printf("\e[48;2;33;150;243m\e[39E");
    printf("\e[68C\e[%sm██50%%\e[E",corfora[1]);
    printf("\e[66C██\e[%sm██\e[%sm██\e[E",cordentro[1],corfora[1]);
    printf("\e[68C██\e[E");
    printf("\e[0m");
    printf("\e[H");
    //2
    printf("\e[48;2;33;150;243m\e[39E");
    printf("\e[84C\e[%sm██75%%\e[E",corfora[2]);
    printf("\e[82C██\e[%sm██\e[%sm██\e[E",cordentro[2],corfora[2]);
    printf("\e[84C██\e[E");
    printf("\e[0m");
    printf("\e[H");
    //3
    printf("\e[48;2;33;150;243m\e[39E");
    printf("\e[98C\e[%sm██100%%\e[E",corfora[3]);
    printf("\e[96C██\e[%sm██\e[%sm██\e[E",cordentro[3],corfora[3]);
    printf("\e[98C██\e[E");
    printf("\e[0m");
    printf("\e[H");

    switch (cursor->navegador) {
        case 0:// confirma 0
            printf("\e[2C\e[12B");
            printf("\e[48;2;0;77;64m");
            printf("-                 ");
            printf("\e[18D");
            imprimir_centralizado_float_dinheiro((1.25*(pote->maiorAposta)),18);
            printf("\e[H");
            printf("\e[0m");
        break;

        case 1: //confirma 1
            printf("\e[2C\e[12B");
            printf("\e[48;2;0;77;64m");
            printf("-                 ");
            printf("\e[18D");
            imprimir_centralizado_float_dinheiro((1.5*(pote->maiorAposta)),18);
            printf("\e[H");
            printf("\e[0m");
        break;

        case 2: //confirma 2
            printf("\e[2C\e[12B");
            printf("\e[48;2;0;77;64m");
            printf("-                 ");
            printf("\e[18D");
            imprimir_centralizado_float_dinheiro((1.75*(pote->maiorAposta)),18);
            printf("\e[H");
            printf("\e[0m");
        break;

        case 3: //confirma 3
            printf("\e[2C\e[12B");
            printf("\e[48;2;0;77;64m");
            printf("-                 ");
            printf("\e[18D");
            imprimir_centralizado_float_dinheiro((2*(pote->maiorAposta)),18);
            printf("\e[H");
            printf("\e[0m");
        break;
    }
}

int menu_jogo_navegar_aposta_percentual (tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {
    //Função para permitir a navegação no menu de jogoo usando A,D e F
    // D = 100
    // A = 97
    // F = 102
    // Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
    // O F serve pra confirmar a seleção
    // A posição 0 é a mais a esquerda
     int numeroDeOpcoes=4;
    //impressao
    desenhar_aumentar_aposta_percentual_barrinha();
    desenhar_aumentar_aposta_percentual_selecao(jogador,cursor,pote);

    //^

    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 100 && input != 97 && input != 102 && input!=120);

    switch(input) {
        case 97:
            if ((cursor->navegador - 1)>=0) cursor->navegador-=1;
        break;
   
        case 100:
            if ((cursor->navegador + 1) < numeroDeOpcoes) cursor->navegador+=1;
        break;

        case 120:
            return -2;
        break;
    
        case 102:
                switch (cursor->navegador) {
                    case 0:// confirma 0
                        if ((1.25*(pote->maiorAposta)) < jogador->dinheiro && pote->maiorAposta>0) {
                            jogador->aposta=(1.25*(pote->maiorAposta));
                            return 0;
                        } else return -1;
                    break;
        
                    case 1: //confirma 1
                        if ((1.5*(pote->maiorAposta)) < jogador->dinheiro && pote->maiorAposta>0) {
                            jogador->aposta=(1.5*(pote->maiorAposta));
                            return 1;
                        } else return -1;
                    break;

                    case 2: //confirma 2
                        if ((1.75*(pote->maiorAposta)) < jogador->dinheiro && pote->maiorAposta>0) {
                            jogador->aposta=(1.75*(pote->maiorAposta));
                            return 2;
                        } else return -1;
                    break;

                    case 3: //confirma 3
                        if ((2*(pote->maiorAposta)) < jogador->dinheiro && pote->maiorAposta>0) {
                            jogador->aposta=(2*(pote->maiorAposta));
                            return 3;
                        } else return -1;
                    break;
                }
        break;
    }
    
    return -1;
}

void menu_jogo_navegar_aposta_absoluto(tp_jogador *jogador,tp_pote *pote){
    float input=-1;
    printf("\e[39E\e[42C");
    printf("\e[48;2;33;150;243m\e[38;2;255;255;255m");
    printf("\e[E\e[46C                      ");

    console_cursor_visivel();
    while(input<(pote->maiorAposta) || input <= 0 || input > jogador ->dinheiro) {
        printf("\e[H\e[40E\e[46C");
        printf("                                                               ");
        printf("\e[H\e[40E\e[46C");
        printf("Valor: ");
        scanf("%f",&input);

        if (input<(pote->maiorAposta)  || input <= 0 || input > jogador ->dinheiro) printf("\e[H\e[41E\e[46C\e[38;2;244;67;54mValor inválido!\e[38;2;255;255;255m");

    }

    jogador->aposta=input;
    console_cursor_invisivel();
    printf("\e[0m");
    printf("\e[H");
}

int menu_jogo_navegar_aposta_absoluta (tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {
    //Função para permitir a confirmação do jogador usando F
    // F = 102
    // O F serve pra confirmar a seleção


    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102 && input!=120);

    switch(input) {
        case 120:
            return -2;
        break;
    
        case 102:
            menu_jogo_navegar_aposta_absoluto(jogador,pote);
            return 0;
        break;
    }
    
    
    return -1;
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
     int sel=-1;
    //impressao
    desenhar_aumentar(cursor);
    //^

    printf("\e[2C\e[12B");
    printf("\e[48;2;0;77;64m");
    printf("                 ");
    printf("\e[H");
    printf("\e[0m");

    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 100 && input != 97 && input != 102 && input != 120);

    switch(input) {
        case 97:
            if ((cursor->navegador - 1)>=0) cursor->navegador-=1;
            else cursor->navegador=(numeroDeOpcoes-1);
        break;
   
        case 100:
            if ((cursor->navegador + 1) < numeroDeOpcoes) cursor->navegador+=1;
            else cursor->navegador=0;
        break;
    
        case 120:
        return -2;
        break;

        case 102:
            switch (cursor->navegador) {
                case 0:// confirma 0
                    cursor_zerarCursor(cursor);
                    desenhar_aumentar_aposta_fundo();
                    desenhar_aumentar_aposta_percentual();
                    while (sel==-1) {
                        sel=menu_jogo_navegar_aposta_percentual(jogador,cursor,pote);
                        if(sel==-2) {
                            cursor_zerarCursor(cursor);
                            return -1;
                        }
                    };
                    return 0;
                break;
    
                case 1: //confirma 1
                    desenhar_aumentar_aposta_absoluto();
                    while (sel==-1) {
                        sel=menu_jogo_navegar_aposta_absoluta(jogador,cursor,pote);
                        if(sel==-2) {
                            return -1;
                        }
                    }
                    return 1;
                break;
            }
        break;
    }
    
    return -1;
}

int menu_jogo_jogador_desqualificado (tp_jogador *jogador,tp_cursor *cursor) {
    //Função para permitir a navegação no menu de jogoo usando e F
    // F = 102
    // Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
    // O F serve pra confirmar a seleção
    // A posição 0 é a mais a esquerda


    desenhar_seletorficoupobre();

    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);
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
    desenhar_seletor(cursor,pote->maiorAposta,jogador->aposta);
    //^

    switch(cursor->navegador) {
        case 0:
            desenhar_cabecalho_jogador_dinheiro(jogador->ID);
        break;

        case 1:
            desenhar_cabecalho_jogador_triste(jogador->ID);
        break;

        case 2:
            desenhar_cabecalho_jogador_neutro(jogador->ID);
        break;
    }
    
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
    desenhar_dinheirocifra(jogador.dinheiro);
    desenhar_jogadoraposta(jogador.aposta);
}

void carta_printarG(tp_carta *carta);
void carta_printarG_verso();

void desenhar_mao_jogador(tp_jogador jogador) {
    printf("\e[48;2;29;78;99m");
    printf("\e[25E\e[58C");
    printf("  Pressione W para começar a rodada");
    printf("\e[H");

    printf("\e[26E\e[64C");
    carta_printarG_verso();
    printf("\e[7C");
    printf("\e[48;2;29;78;99m");
    carta_printarG_verso();
    printf("\e[H");
    
    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 119);

    printf("\e[25E\e[58C");
    printf("\e[48;2;29;78;99m");
    printf("                                   ");
    printf("\e[H");

    printf("\e[26E\e[64C");
    printf("\e[48;2;29;78;99m");
    carta_printarG(&jogador.mao->info);
    printf("\e[7C");
    printf("\e[48;2;29;78;99m");
    carta_printarG(&jogador.mao->prox->info);
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_maiorAposta(float valor) {
    printf("\e[48;2;255;193;7m");
    printf("\e[41E\e[132C");
    printf("\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Aposta mais alta:",22);
    printf("\e[H");
    printf("\e[42E\e[132C");
    imprimir_centralizado_float_dinheiro(valor,22);

    printf("\e[0m");
    printf("\e[H");
}

void jogo_jogador_rodada_finalizar(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {

    printf("\e[2C\e[12B");
    printf("\e[48;2;0;77;64m");
    printf("                  ");
    printf("\e[H");
    printf("\e[0m");

    desenhar_aumentar_aposta_fundo();
    printf("\e[H");
    printf("\e[39E\e[42C");
    printf("\e[48;2;33;150;243m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Aperte F para finalizar a jogada",70);
    printf("\e[H");
    printf("\e[0m");
    while((getch())!=102);
}

void jogo_jogador_rodada_mostrar_maoMesa(tp_listasecarta *maomesa) {
    printf("\e[11E\e[53C\e[48;2;163;114;49m");
    
        tp_listasecarta *atu = maomesa;
        while (atu != NULL) {
            printf("\e[48;2;163;114;49m");
            carta_printarG(&atu->info);
            atu = atu->prox;
    }
    printf("\e[0m\e[H");
}

int jogo_jogador_rodada_mostrar_possibilidades(tp_jogador *jogador) {
    printf("\e[1E\e[137C\e[48;2;121;134;203m");
    char corletra[9][18]={"38;2;100;124;209","38;2;100;124;209","38;2;100;124;209","38;2;100;124;209","38;2;100;124;209","38;2;100;124;209","38;2;100;124;209","38;2;100;124;209","38;2;100;124;209"};
    
    if (jogador->combinacoes.par.quant==1) strcpy(corletra[0],"38;2;194;205;240");
    if (jogador->combinacoes.par.quant==2) strcpy(corletra[1],"38;2;194;205;240");
    if (jogador->combinacoes.trinca.quant>0) strcpy(corletra[2],"38;2;194;205;240");
    if (jogador->combinacoes.quadra.quant>0) strcpy(corletra[3],"38;2;194;205;240");
    if (jogador->combinacoes.fullHouse.quant>0) strcpy(corletra[4],"38;2;194;205;240");
    if (jogador->combinacoes.flush.quant>0) strcpy(corletra[5],"38;2;194;205;240");
    if (jogador->combinacoes.straight.quant>0) strcpy(corletra[6],"38;2;194;205;240");
    if (jogador->combinacoes.straightFlush.quant>0) strcpy(corletra[7],"38;2;194;205;240");
    if (jogador->combinacoes.royalFlush.quant>0) strcpy(corletra[8],"38;2;194;205;240");

    imprimir__centralizado_string_max20("Combinações",18);
    printf("\e[1E\e[136C");
    imprimir__centralizado_string_max20("Possíveis",18);
    
    printf("\e[2E\e[136C");
    printf("\e[%sm",corletra[0]);

    imprimir__centralizado_string_max20("Par",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[1]);

    imprimir__centralizado_string_max20("2 Pares",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[2]);

    imprimir__centralizado_string_max20("Trinca",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[3]);

    imprimir__centralizado_string_max20("Quadra",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[4]);

    imprimir__centralizado_string_max20("Full House",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[5]);

    imprimir__centralizado_string_max20("Flush",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[6]);

    imprimir__centralizado_string_max20("Straight",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[7]);

    imprimir__centralizado_string_max20("Straight Flush",18);

    printf("\e[1E\e[136C");
    printf("\e[%sm",corletra[8]);

    imprimir__centralizado_string_max20("Royal Flush",18);
    
    printf("\e[0m\e[H");
}

int combinacoes_verificar_valores (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador,tp_combinacaoInfo comparadorValor[]);
int combinacoes_verificar_naipes (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador,tp_combinacaoInfo comparadorValor[]);
int combinacoes_verificar_sequencias (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador);
int combinacoes_verificar_royalFlush (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador);

int jogo_jogador_rodada(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote,tp_listasecarta *mao_mesa) {

    int sel=-1;
    cursor_zerarCursor(cursor);


    desenhar_limpar_seletorEaumentar();
    
    desenhar_pote(pote->pote);
    desenhar_menu_jogador(*jogador);
    desenhar_marcadormaojogador();
    desenhar_porcoaposta();
    desenhar_maiorAposta(pote->maiorAposta);
    jogo_jogador_rodada_mostrar_maoMesa(mao_mesa);

    desenhar_areacombinacoes();

    desenhar_mao_jogador(*jogador);
    
    desenhar_limpar_seletorEaumentar();
    desenhar_bordaseletor();

    jogador_inicializacao(jogador);
    combinacoes_verificar_valores(jogador,mao_mesa,jogador->mao,jogador->comparadorValor);
    combinacoes_verificar_naipes(jogador,mao_mesa,jogador->mao,jogador->comparadorValor);
    combinacoes_verificar_sequencias(jogador,mao_mesa,jogador->mao);
    combinacoes_verificar_royalFlush(jogador,mao_mesa,jogador->mao); 
    
    jogo_jogador_rodada_mostrar_possibilidades(jogador);
    
    desenhar_tutorial("0;77;64");

    int escolha=-1;


    if (jogador->dinheiro==0) {
        desenhar_cabecalho_jogador_triste(jogador->ID);
        menu_jogo_jogador_desqualificado(jogador,cursor);
        jogador->desistir=1;
        return 1;
    }
    
    while(escolha == -1) {
        sel=-1;
        escolha=menu_jogo_navegar(jogador,cursor,pote);
        
        if (escolha==0) {
            cursor_zerarCursor(cursor);
            while (sel==-1){
                sel=menu_jogo_navegar_aposta(jogador,cursor,pote);
                if (sel==-2) {
                    cursor_zerarCursor(cursor);
                    desenhar_limpar_seletorEaumentar();
                    desenhar_bordaseletor();
                    escolha=-1;
                    break;
                }        
            }
        }

        else if (escolha==1) {
            jogador->desistir=1;
        }

        else if (escolha==2) {
            if ((pote->maiorAposta - jogador->aposta) < 0) jogador->aposta=jogador->dinheiro;
            else {
                jogador->dinheiro+=jogador->aposta;
                jogador->aposta += (pote->maiorAposta - jogador->aposta);
            }
        }
    }

    jogador->dinheiro-=jogador->aposta;
    pote->pote+=jogador->aposta;
    if (jogador->aposta > pote->maiorAposta) pote->maiorAposta=jogador->aposta;

    desenhar_pote(pote->pote);
    desenhar_dinheirocifra(jogador->dinheiro);
    desenhar_maiorAposta(pote->maiorAposta);
    desenhar_jogadoraposta(jogador->aposta);

    jogo_jogador_rodada_finalizar(jogador,cursor,pote);
    return 1;
}

int jogador_inicializar_mao(tp_jogador jogador[], int quant ){
    for(int i=0;i<quant;i++){
    jogador[i].mao=listaSEcarta_inicializar(); 
    }
}


int condicao_rodada(tp_jogador jogador[], tp_listasecarta **mao_mesa, int quant){
int veri=0;
for(int i=0;i<quant;i++){
    if(jogador[i].desistir == 1){
       veri++; 
    }
}
 if(veri>= quant - 1){
       return 0;
    }
if(listaSEcarta_verificar_tamanho(*mao_mesa)>=5){
   return 0;
}
return 1;
}

void jogo_zerar_apostas(tp_jogador jogador[], tp_pote *pote, int quant){
    for(int i=0;i<quant;i++){
        jogador[i].aposta=0;
    }
    pote->maiorAposta=0;
}

int jogo_rodada_verificar_continuarRodada(tp_jogador jogador[],tp_pote *pote,int quant) {
    int veri=0;
    for(int i=0;i<quant;i++){
        if (jogador[i].aposta!=pote->maiorAposta) veri=1;
        break;
    }
    return veri;
}


#endif
