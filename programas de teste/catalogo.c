//Bibliotecas do C
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Bibliotecas próprias
#include "miscelanea.h"
#include "elementosvisuais.h"
#include "arquivo.h"
#include "cartas.h"
#include "configs.h"
#include "jogador.h"
#include "extradebug.h"
#include "combinacoesteste.h"

int main()
{

    windowsconfig();

    int quant;

    tp_pilhaSEcarta *baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];
    tp_listasecarta *mao_mesa;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    //Inicializa os baralhos

    FILE *arq = fopen("seed.txt","r");
    int num;
    fscanf(arq,"%d",&num);
    if (num!=0) srand(num);
    else srand(time(NULL));

	baralhoReferencia_inicializar(baralhoReferencia);

    for (int i=0;i<52;i++){
        printf("%d|%d",baralhoReferencia[i].ID,i);
        carta_printarP(&baralhoReferencia[i]);
        if(i==12||i==25||i==38||i==51) printf("\n\n\n\n\n");
    }

    programa_pausar();
    programa_finalizar();

    return 1;
}