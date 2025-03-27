#ifndef JOGADOR_H 
#define JOGADOR_H
#include <stdio.h>
#include <string.h>

typedef struct{
    int ID;
    char nome[30];
}tp_jogador;

int jogador_escolherQuantidade() {
    int quant = 0;
    char buffer[100];  // Buffer para capturar a entrada bruta
    
    while (1) {  // Loop infinito que sai quando entrada válida
        printf("Digite a quantidade de jogadores(2-6): ");
        
        fflush(stdin);  // Garante que não haja caracteres sobrando
        
        //Lê toda a linha como string para validação
        fgets(buffer, sizeof(buffer), stdin);
        
        //Remove o \n do final da string
        buffer[strcspn(buffer, "\n")] = 0;
        
        //Converte a string para inteiro
        if (sscanf(buffer, "%d", &quant) == 1) {
            if (quant >= 2 && quant <= 6) {
                return quant;
            } else {
                printf("Quantidade de jogadores inválida!\n");
            }
        } else {
            printf("Por favor, digite apenas números inteiros!\n");
        }
    }
}

//Caso o nome seja repetido, para não confundir os jogadores
int jogador_nomeExistente(tp_jogador jogador[], int quant, char nome[]){
    for(int i = 0; i < quant; i++) {
        if(strcmp(jogador[i].nome, nome) == 0) {
            return 1;
        }
    }
    return 0;
}

void jogador_escolherNomes(tp_jogador jogador[],int quant){
    
    for(int i = 0;i < quant ;i++){
        printf("Digite o nome do jogador %d : ", i + 1);
        scanf("%s",jogador[i].nome);
    if(strlen(jogador[i].nome) == 0){
        printf("Nome inválido! Tente Novamente.\n");
        i--;
        continue;

        while (jogador_nomeExistente(jogador, i, jogador[i].nome)){
            printf("O nome já existe! Tente outro: ", jogador[i].nome);
            scanf("%s", jogador[i].nome);
            }
        }
    }
}

void jogador_cadastrado(tp_jogador jogador[], int quant) {

    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("              JOGADORES CADASTRADOS        \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");

    for (int i = 0; i < quant; i++) {
        printf("Jogador %d: %s\n", i + 1, jogador[i].nome);
    }
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    if (quant >= 2) {
        printf("                                 Jogador 1: %s      Jogador 2: %s    \n", jogador[0].nome, jogador[1].nome);}
        printf("            %s      %s       \n", "█████████████",   "█████████████");
        printf("             %s        %s     \n", "███████████",     "███████████");
        printf("                                                          \n");
        printf("         %s              \n", "███████████████████████████████████████");
        printf("         %s              \n", "███████████████████████████████████████");
        printf("%s  %s  %s    \n", "███████", "███████████████████████████████████████", "███████");
        printf("%s  %s  %s    \n", "███████", "███████████████████████████████████████", "███████");
        printf("%s  %s  %s    \n", "███████", "███████████████████████████████████████", "███████");
        printf("%s  %s  %s    \n", "███████", "███████████████████████████████████████", "███████");
        printf("%s  %s  %s    \n", "███████", "███████████████████████████████████████", "███████");
        printf("%s  %s  %s    \n", "███████", "███████████████████████████████████████", "███████");
        if (quant >= 4) {printf("  Jogador 3: %s                                         Jogador 4: %s \n", jogador[2].nome, jogador[3].nome);}
        printf("         %s              \n", "███████████████████████████████████████");
        printf("         %s              \n", "███████████████████████████████████████");
        printf("                                                          \n");
        printf("             %s        %s     \n", "███████████",     "███████████");
        printf("            %s      %s       \n", "█████████████",   "█████████████");
        if (quant >= 6) {printf("               Jogador 5: %s       Jogador 6: %s         \n", jogador[4].nome, jogador[5].nome);}
}


#endif
