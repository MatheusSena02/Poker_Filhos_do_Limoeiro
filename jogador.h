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
    int maiorApostaJogadorID;
    int quantidadeJogadores;
}tp_pote;

void desenhar_setas() {
    desenhar_setasdentro();
    Sleep(200);
    desenhar_setasfora();
    Sleep(200);
}


int jogador_escolherQuantidade_navegar(tp_cursor *cursor){
    //Função para permitir a navegação no menu de jogoo usando A,D e F
    // D = 100
    // A = 97
    // F = 102
    // Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
    // O F serve pra confirmar a seleção
    // A posição 0 é a mais a esquerda
     int numeroDeOpcoes=5;

    switch(cursor->navegador) {
        case 0:
            desenhar_doisjog();
        break;

        case 1:
            desenhar_tresjog();
        break;

        case 2:
            desenhar_quatrojog();
        break;

        case 3:
            desenhar_cincojog();
        break;
        
        case 4:
            desenhar_seisjog();
        break;
    }
    
    int input;
    getch();
    do {
        input=-1;
        while (input == -1) {
            desenhar_setas();
            input = getch();  // Verifica se uma tecla foi pressionada
        }
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
                case 0: //confirma 2
                    return 2;
                break;
    
                case 1: //confirma 3
                    return 3;
                break;
    
                case 2: //confirma 4
                    return 4;
                break;

                case 3: //confirma 5
                    return 5;
                break;

                case 4: //confirma 6
                    return 6;
                break;
            }
        break;
    }

    return -1;
}

int jogador_escolherQuantidade(tp_cursor *cursor){

    int quant;

    desenhar_fundojogadores();
    desenhar_tutorial("0;64;50");
    desenhar_njogadores();
    cursor_zerarCursor(cursor);

    do {
        quant=jogador_escolherQuantidade_navegar(cursor);
        audio_play("selecao",0);
    } while (quant==-1);

    audio_play("botao",0);

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
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 100 && input != 97 && input != 102 && input!=120);
    audio_play("selecao",0);
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
                        audio_play("botao",0);
                        if ((1.25*(pote->maiorAposta)) < jogador->dinheiro && pote->maiorAposta>0) {
                            jogador->aposta=(1.25*(pote->maiorAposta));
                            return 0;
                        } else {
                            return -1;
                        }
                    break;
        
                    case 1: //confirma 1
                        audio_play("botao",0);
                        if ((1.5*(pote->maiorAposta)) < jogador->dinheiro && pote->maiorAposta>0) {
                            jogador->aposta=(1.5*(pote->maiorAposta));
                            return 1;
                        } else return -1;
                    break;

                    case 2: //confirma 2
                        audio_play("botao",0);
                        if ((1.75*(pote->maiorAposta)) < jogador->dinheiro && pote->maiorAposta>0) {
                            jogador->aposta=(1.75*(pote->maiorAposta));
                            return 2;
                        } else return -1;
                    break;

                    case 3: //confirma 3
                        audio_play("botao",0);
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
    getch();
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
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 100 && input != 97 && input != 102 && input != 120);
    audio_play("selecao",0);

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
                    audio_play("botao",0);
                    if(pote->maiorAposta>0) {
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
                    } else
                        audio_play("cancel",0);
                        desenhar_popupaviso("Não é possível","aumentar % R$0","");
                break;
    
                case 1: //confirma 1
                    audio_play("botao",0);
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
    audio_play("cancel",0);
    int input;
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);
    audio_play("perda",0);

}

int menu_jogo_jogador_desistir (tp_jogador *jogador,tp_cursor *cursor) {
    //Função para permitir a navegação no menu de jogoo usando e F
    // F = 102
    // Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
    // O F serve pra confirmar a seleção
    // A posição 0 é a mais a esquerda


    desenhar_seletordesistir();
    audio_play("cancel",0);
    int input;
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102 && input!=120);
    if (input==102) return 1;
    else return 0;
}

void desenhar_menu_jogador(tp_jogador jogador) {
    desenhar_cabecalho(jogador.cor,jogador.nome,jogador.ID);
    desenhar_dinheirocifra(jogador.dinheiro);
    desenhar_jogadoraposta(jogador.aposta);
}

void carta_printarG(tp_carta *carta);
void carta_printarG_verso();

void desenhar_mao_jogador(tp_jogador jogador){
    printf("\e[26E\e[64C");
    printf("\e[48;2;29;78;99m");
    carta_printarG(&jogador.mao->info);
    printf("\e[7C");
    printf("\e[48;2;29;78;99m");
    carta_printarG(&jogador.mao->prox->info);
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_mao_jogador_iniciar(tp_jogador jogador) {
    printf("\e[48;2;29;78;99m");
    printf("\e[25E\e[58C");
    printf("  Pressione W para começar a jogada");
    printf("\e[H");

    printf("\e[26E\e[64C");
    carta_printarG_verso();
    printf("\e[7C");
    printf("\e[48;2;29;78;99m");
    carta_printarG_verso();
    printf("\e[H");
    
    int input;
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 119);

    audio_play("som2carta",0);
    printf("\e[25E\e[58C");
    printf("\e[48;2;29;78;99m");
    printf("                                   ");
    printf("\e[H");

    desenhar_mao_jogador(jogador);
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
    if (jogador->desistir==1) audio_play("perda",0);
    else audio_play("dinheiro",0);
}

void jogo_jogador_rodada_mostrar_maoMesa(tp_listasecarta *maomesa) {
    printf("\e[11E\e[53C\e[48;2;163;114;49m");
    
        tp_listasecarta *atu = maomesa;
        int cont=0;
        while (atu != NULL) {
            printf("\e[48;2;163;114;49m");
            carta_printarG(&atu->info);
            atu = atu->prox;
            cont++;
        }
        switch(cont){
            case 3:
            audio_play("som3carta",0);
            break;
            case 4:
            audio_play("som4carta",0);
            break;
            case 5:
            audio_play("som5carta",0);
            break;
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


void redesenhar_tela_completa(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote,tp_listasecarta *mao_mesa){

    desenhar_limpar_seletorEaumentar();
    
    desenhar_pote(pote->pote);
    desenhar_marcadormaojogador();
    jogo_jogador_rodada_mostrar_maoMesa(mao_mesa);

    desenhar_mao_jogador(*jogador);
    
    desenhar_limpar_seletorEaumentar();
    desenhar_bordaseletor();
    
    desenhar_tutorial("0;77;64");
}

void baralhoReferencia_inicializar(tp_carta *baralhoReferencia);
void carta_printarP(tp_carta *carta);
void carta_printarP_verso();

int menu_popupguia(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote,tp_listasecarta *mao_mesa){
    desenhar_popupbase();
    desenhar_popguia();

    tp_carta baralho[52];
    baralhoReferencia_inicializar(baralho);

    printf("\e[H\e[0m");
    printf("\e[48;2;44;37;28m");
    printf("\e[13E\e[44C");

    carta_printarP(&baralho[0]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[12]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[11]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[10]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[9]);


    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[44C");

    carta_printarP(&baralho[36]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[35]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[34]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[33]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[32]);

    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[44C");

    carta_printarP(&baralho[8]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[21]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[34]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[47]);
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();

    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[44C");

    carta_printarP(&baralho[0]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[13]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[26]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[2]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[28]);

    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[44C");

    carta_printarP(&baralho[40]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[42]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[44]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[45]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[50]);

    printf("\e[H\e[0m");
    




    printf("\e[48;2;44;37;28m");
    printf("\e[13E\e[88C");

    carta_printarP(&baralho[9]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[47]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[20]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[32]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[5]);

    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[88C");

    carta_printarP(&baralho[6]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[19]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[32]);
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();

    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[88C");

    carta_printarP(&baralho[10]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[49]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[17]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[30]);
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();

    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[88C");

    carta_printarP(&baralho[0]);
    printf("\e[48;2;44;37;28m");
    carta_printarP(&baralho[39]);
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();

    printf("\e[48;2;44;37;28m");
    printf("\e[5E\e[88C");

    carta_printarP(&baralho[51]);
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();
    printf("\e[48;2;44;37;28m");
    carta_printarP_verso();

    printf("\e[H\e[0m");
    
    printf("\e[H\e[0m");
    
    printf("\e[13E\e[26C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Royal Flush",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[38C");
    printf("01");

    printf("\e[3E\e[26C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Straight Flush",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[38C");
    printf("02");

    printf("\e[3E\e[26C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Quadra",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[38C");
    printf("03");

    printf("\e[3E\e[26C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Full House",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[38C");
    printf("04");

    printf("\e[3E\e[26C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Flush",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[38C");
    printf("05");

    printf("\e[H\e[0m");

    printf("\e[13E\e[70C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Straight",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[82C");
    printf("06");

    printf("\e[3E\e[70C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Trinca",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[82C");
    printf("07");

    printf("\e[3E\e[70C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Dois Pares",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[82C");
    printf("08");

    printf("\e[3E\e[70C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Par",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[82C");
    printf("09");

    printf("\e[3E\e[70C");
    printf("\e[48;2;44;37;28m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Carta Alta",26);
    printf("\e[48;2;218;159;38m\e[38;2;0;0;0m");
    printf("\e[2E\e[82C");
    printf("10");

    printf("\e[H\e[0m");

    printf("\e[38;2;255;255;255m");
    printf("\e[39E\e[48;2;44;37;28m");
    imprimir__centralizado_string_max200("Combinações possíveis em ordem decrescente (Royal Flush > Par)",155);
    printf("\e[H\e[0m");

    printf("\e[38;2;0;0;0m");
    desenhar_tutorial("143;120;89");
    printf("\e[0m");

    int input;
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102 && input!=120);

    audio_play("cancel",0);

    desenhar_popupbaselimpar();
    desenhar_mesaapoiodamesa();
    redesenhar_tela_completa(jogador,cursor,pote,mao_mesa);
}



int menu_popupjogadores(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote,tp_listasecarta *mao_mesa,tp_jogador jogadores[]){
    desenhar_popupbase();
    printf("\e[38;2;0;0;0m");
    desenhar_tutorial("143;120;89");
    printf("\e[0m");

    for (int i=0;i<6;i++){
        if (i < pote->quantidadeJogadores){
            switch(i){
                case 0:
                    if (jogadores[i].desistir==0) {
                        if (jogadores[i].ID==pote->maiorApostaJogadorID) desenhar_cartagatocoroa();
                        else desenhar_cartagato();

                        printf("\e[15E\e[36C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[NOME]",20);
                        printf("\e[E\e[36C");
                        printf("\e[48;2;239;208;174m");
                        printf("\e[38;2;65;43;36m");
                        imprimir__centralizado_string_max20(jogadores[i].nome,20);
                        printf("\e[E\e[36C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[MAIOR APOSTA]",20);
                        printf("\e[E\e[36C");
                        printf("\e[48;2;255;187;73m");
                        printf("\e[38;2;255;255;255m");
                        imprimir_centralizado_float_dinheiro(jogadores[i].aposta,20);
                        printf("\e[H\e[0m");

                    } else desenhar_cartagatodesistido();
                break;

                case 1:
                    if (jogadores[i].desistir==0) {
                        if (jogadores[i].ID==pote->maiorApostaJogadorID) desenhar_cartacoelhocoroa();
                        else desenhar_cartacoelho();

                        printf("\e[15E\e[68C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[NOME]",20);
                        printf("\e[E\e[68C");
                        printf("\e[48;2;239;208;174m");
                        printf("\e[38;2;65;43;36m");
                        imprimir__centralizado_string_max20(jogadores[i].nome,20);
                        printf("\e[E\e[68C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[MAIOR APOSTA]",20);
                        printf("\e[E\e[68C");
                        printf("\e[48;2;255;187;73m");
                        printf("\e[38;2;255;255;255m");
                        imprimir_centralizado_float_dinheiro(jogadores[i].aposta,20);
                        printf("\e[H\e[0m");

                    } else desenhar_cartacoelhodesistido();
                break;

                case 2:
                    if (jogadores[i].desistir==0) {
                        if (jogadores[i].ID==pote->maiorApostaJogadorID) desenhar_cartasapocoroa();
                        else desenhar_cartasapo();

                        printf("\e[15E\e[98C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[NOME]",20);
                        printf("\e[E\e[98C");
                        printf("\e[48;2;239;208;174m");
                        printf("\e[38;2;65;43;36m");
                        imprimir__centralizado_string_max20(jogadores[i].nome,20);
                        printf("\e[E\e[98C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[MAIOR APOSTA]",20);
                        printf("\e[E\e[98C");
                        printf("\e[48;2;255;187;73m");
                        printf("\e[38;2;255;255;255m");
                        imprimir_centralizado_float_dinheiro(jogadores[i].aposta,20);
                        printf("\e[H\e[0m");

                    } else desenhar_cartasapodesistido();
                break;

                case 3:
                    if (jogadores[i].desistir==0) {
                        if (jogadores[i].ID==pote->maiorApostaJogadorID) desenhar_cartaesquilocoroa();
                        else desenhar_cartaesquilo();

                        printf("\e[33E\e[36C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[NOME]",20);
                        printf("\e[E\e[36C");
                        printf("\e[48;2;239;208;174m");
                        printf("\e[38;2;65;43;36m");
                        imprimir__centralizado_string_max20(jogadores[i].nome,20);
                        printf("\e[E\e[36C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[MAIOR APOSTA]",20);
                        printf("\e[E\e[36C");
                        printf("\e[48;2;255;187;73m");
                        printf("\e[38;2;255;255;255m");
                        imprimir_centralizado_float_dinheiro(jogadores[i].aposta,20);
                        printf("\e[H\e[0m");

                    } else desenhar_cartaesquilodesistido();
                break;

                case 4:
                    if (jogadores[i].desistir==0) {
                        if (jogadores[i].ID==pote->maiorApostaJogadorID) desenhar_cartaratocoroa();
                        else desenhar_cartarato();

                        printf("\e[33E\e[68C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[NOME]",20);
                        printf("\e[E\e[68C");
                        printf("\e[48;2;239;208;174m");
                        printf("\e[38;2;65;43;36m");
                        imprimir__centralizado_string_max20(jogadores[i].nome,20);
                        printf("\e[E\e[68C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[MAIOR APOSTA]",20);
                        printf("\e[E\e[68C");
                        printf("\e[48;2;255;187;73m");
                        printf("\e[38;2;255;255;255m");
                        imprimir_centralizado_float_dinheiro(jogadores[i].aposta,20);
                        printf("\e[H\e[0m");

                    } else desenhar_cartaratodesistido();
                break;

                case 5:
                    if (jogadores[i].desistir==0) {
                        if (jogadores[i].ID==pote->maiorApostaJogadorID) desenhar_cartaursocoroa();
                        else desenhar_cartaurso();

                        printf("\e[33E\e[98C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[NOME]",20);
                        printf("\e[E\e[98C");
                        printf("\e[48;2;239;208;174m");
                        printf("\e[38;2;65;43;36m");
                        imprimir__centralizado_string_max20(jogadores[i].nome,20);
                        printf("\e[E\e[98C");
                        printf("\e[48;2;204;164;120m");
                        printf("\e[38;2;122;99;69m");
                        imprimir__centralizado_string_max20("[MAIOR APOSTA]",20);
                        printf("\e[E\e[98C");
                        printf("\e[48;2;255;187;73m");
                        printf("\e[38;2;255;255;255m");
                        imprimir_centralizado_float_dinheiro(jogadores[i].aposta,20);
                        printf("\e[H\e[0m");

                    } else desenhar_cartaursodesistido();
                break;
            }
        }
        else {
            switch(i){
                case 0:
                    desenhar_cartagatoausente();
                break;

                case 1:
                    desenhar_cartacoelhoausente();
                break;

                case 2:
                    desenhar_cartasapoausente();
                break;

                case 3:
                    desenhar_cartaesquiloausente();
                break;

                case 4:
                    desenhar_cartaratoausente();
                break;

                case 5:
                    desenhar_cartaursoausente();
                break;
            }
        }
    }

    int input;
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102 && input!=120);
    audio_play("cancel",0);

    desenhar_popupbaselimpar();
    desenhar_mesaapoiodamesa();
    redesenhar_tela_completa(jogador,cursor,pote,mao_mesa);
}

int menu_jogo_navegar (tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote,tp_listasecarta *mao_mesa, tp_jogador jogadores[]) {
    //Função para permitir a navegação no menu de jogoo usando A,D e F
    // D = 100
    // A = 97
    // F = 102
    // Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
    // O F serve pra confirmar a seleção
    // A posição 0 é a mais a esquerda
     int numeroDeOpcoes=5;
    //impressao
    desenhar_seletor(cursor,pote->maiorAposta,jogador->aposta);
    //^

    switch(cursor->navegador) {
        case 1:
            desenhar_cabecalho_jogador_dinheiro(jogador->ID);
        break;

        case 2:
            desenhar_cabecalho_jogador_triste(jogador->ID);
        break;

        case 3:
            desenhar_cabecalho_jogador_neutro(jogador->ID);
        break;

        case 0:
            desenhar_cabecalho_jogador_neutro(jogador->ID);
        break;
        
        case 4:
            desenhar_cabecalho_jogador_neutro(jogador->ID);
        break;
    }
    
    int input;
    getch();
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 100 && input != 97 && input != 102);
    audio_play("selecao",0);

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
                case 0:
                    audio_play("botao",0);
                    menu_popupjogadores(jogador,cursor,pote,mao_mesa,jogadores);
                    return -1;
                break;
    
                case 1: //confirma 0
                    audio_play("botao",0);
                    return 0;
                break;
    
                case 2: //confirma 1
                    audio_play("botao",0);
                    return 1;
                break;

                case 3: //confirma 2
                    audio_play("botao",0);
                    return 2;
                break;

                case 4:
                    audio_play("botao",0);
                    menu_popupguia(jogador,cursor,pote,mao_mesa);
                    return -1;
                break;
            }
        break;
    }
    
    return -1;
}

int jogo_jogador_rodada(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote,tp_listasecarta *mao_mesa,tp_jogador jogadores[]) {

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

    desenhar_mao_jogador_iniciar(*jogador);
    
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
        escolha=menu_jogo_navegar(jogador,cursor,pote,mao_mesa,jogadores);

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
            if (menu_jogo_jogador_desistir(jogador,cursor)) {
                jogador->desistir=1;
                audio_play("perda",0);
                return 1;
            }
            else {
                desenhar_limpar_seletorEaumentar();
                desenhar_bordaseletor();
                escolha=-1;
            }
        }

        else if (escolha==2) {
            if ((pote->maiorAposta - jogador->aposta) < 0) jogador->aposta=jogador->dinheiro;
            else {
                jogador->dinheiro+=jogador->aposta;
                jogador->aposta += (pote->maiorAposta - jogador->aposta);
            }
        }
    }
    
    desenhar_jogadoreslimpar();
    desenhar_guialimpar();

    jogador->dinheiro-=jogador->aposta;
    pote->pote+=jogador->aposta;
    if (jogador->aposta > pote->maiorAposta) {
        pote->maiorApostaJogadorID=jogador->ID;
        pote->maiorAposta=jogador->aposta;
    }

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
    pote->maiorApostaJogadorID=-1;
}

int jogo_rodada_verificar_continuarRodada(tp_jogador jogador[],tp_pote *pote,int quant) {
    int veri=0;
    for(int i=0;i<quant;i++){
        if (jogador[i].aposta!=pote->maiorAposta && jogador[i].desistir==0) {
            veri=1;
            break;
        }
    }
    return veri;
}


#endif
