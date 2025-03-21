//Bibliotecas do C
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

//Bibliotecas próprias
#include "arq.h"
#include  "configs.h"
#include "miscelania.h"
#include "cartas.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//Configura o console para windows (liga cores e outros caracteres)
    #ifdef _WIN32
	windowsconfig();
    #endif

    //////////////////////////// INICIALIZAÇÃO - ARQUIVOS - CONFIGURAÇÕES ////////////////////////////////
    
	//Variáveis das configurações -> opcoes.txt
    opc opcoes;
    //Verifica se o opcoes.txt já foi criadof
    if (!arq_verificarOpcoes()) return 10;
    //Obter variáveis guardadas em opcoes.txt e inicializa srand
    inicializacao(&opcoes);
    programa_iniciar();
    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////
    
	tp_carta baralho[53];
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    

    baralho[0].naipe=0;
    carta_setarvalor(&baralho[0],1);
    baralho[1].naipe=1;
    carta_setarvalor(&baralho[1],2);
    baralho[2].naipe=2;
    carta_setarvalor(&baralho[2],3);
    baralho[3].naipe=3;
    carta_setarvalor(&baralho[3],10);
    
    carta_printar(&baralho[0],opcoes.estiloCarta);
    carta_printar(&baralho[1],opcoes.estiloCarta);
    carta_printar(&baralho[2],opcoes.estiloCarta);
    carta_printar(&baralho[3],opcoes.estiloCarta);






    programa_finalizar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////