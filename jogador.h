#ifndef JOGADOR_H 
#define JOGADOR_H
#include <stdio.h>
#include <string.h>
typedef struct{
    int ID;
    char nome[30];
}tp_jogador;

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

void jogador_escolherNomes(tp_jogador jogador[],int quant){
    
    for(int i=0;i<quant;i++){
        printf("Digite o nome do jogador %d : ", i+1);
        scanf("%s",jogador[i].nome);
    }
    
}




#endif