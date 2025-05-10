#ifndef JOGADOR_H 
#define JOGADOR_H
#include <stdio.h>
#include <string.h>
#include "cartas.h"
#include "elementosvisuais.h"

typedef struct{
    int ID;
    char nome[30], cor[16];
    tp_listasecarta *mao;
    float dinheiro;
    float aposta;
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
            imprimir_centralizado_float_dinheiro((((pote->pote+(pote->maiorAposta - jogador->aposta))*0.25)+(pote->maiorAposta - jogador->aposta)),18);
            printf("\e[H");
            printf("\e[0m");
        break;

        case 1: //confirma 1
            printf("\e[2C\e[12B");
            printf("\e[48;2;0;77;64m");
            printf("-                 ");
            printf("\e[18D");
            imprimir_centralizado_float_dinheiro((((pote->pote+(pote->maiorAposta - jogador->aposta))*0.5)+(pote->maiorAposta - jogador->aposta)),18);
            printf("\e[H");
            printf("\e[0m");
        break;

        case 2: //confirma 2
            printf("\e[2C\e[12B");
            printf("\e[48;2;0;77;64m");
            printf("-                 ");
            printf("\e[18D");
            imprimir_centralizado_float_dinheiro((((pote->pote+(pote->maiorAposta - jogador->aposta))*0.75)+(pote->maiorAposta - jogador->aposta)),18);
            printf("\e[H");
            printf("\e[0m");
        break;

        case 3: //confirma 3
            printf("\e[2C\e[12B");
            printf("\e[48;2;0;77;64m");
            printf("-                 ");
            printf("\e[18D");
            imprimir_centralizado_float_dinheiro((((pote->pote+(pote->maiorAposta - jogador->aposta))*1)+(pote->maiorAposta - jogador->aposta)),18);
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
                    jogador->aposta=(((pote->pote+(pote->maiorAposta - jogador->aposta))*0.25)+(pote->maiorAposta - jogador->aposta));
                    return 0;
                break;
    
                case 1: //confirma 1
                    jogador->aposta=(((pote->pote+(pote->maiorAposta - jogador->aposta))*0.5)+(pote->maiorAposta - jogador->aposta));
                    return 1;
                break;

                case 2: //confirma 2
                    jogador->aposta=(((pote->pote+(pote->maiorAposta - jogador->aposta))*0.75)+(pote->maiorAposta - jogador->aposta));
                    return 2;
                break;

                case 3: //confirma 3
                    jogador->aposta=(((pote->pote+(pote->maiorAposta - jogador->aposta))*1)+(pote->maiorAposta - jogador->aposta));
                    return 3;
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
    while(input<((jogador->aposta - pote->maiorAposta)+1) || input <= 0) {
        printf("\e[H\e[40E\e[46C");
        printf("                                                               ");
        printf("\e[H\e[40E\e[46C");
        printf("Valor: ");
        scanf("%f",&input);

        if (input<(jogador->aposta - pote->maiorAposta || input <= 0)) printf("\e[H\e[41E\e[46C\e[38;2;244;67;54mValor inválido!\e[38;2;255;255;255m");

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

int jogo_jogador_rodada(tp_jogador *jogador,tp_cursor *cursor,tp_pote *pote) {

    int sel=-1;
    cursor_zerarCursor(cursor);


    desenhar_limpar_seletorEaumentar();
    
    desenhar_pote(pote->pote);
    desenhar_menu_jogador(*jogador);
    desenhar_marcadormaojogador();
    desenhar_porcoaposta();
    desenhar_maiorAposta(pote->maiorAposta);

    desenhar_mao_jogador(*jogador);

    desenhar_limpar_seletorEaumentar();
    desenhar_bordaseletor();

    int escolha=-1;


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
    desenhar_dinheiro(jogador->dinheiro);
    desenhar_maiorAposta(pote->maiorAposta);
    desenhar_jogadoraposta(jogador->aposta);

    jogo_jogador_rodada_finalizar(jogador,cursor,pote);

}

int jogador_inicializar_mao(tp_jogador jogador[], int quant ){
    for(int i=0;i<quant;i++){
    jogador[i].mao=listaSEcarta_inicializar(); 
    }
}



#endif
