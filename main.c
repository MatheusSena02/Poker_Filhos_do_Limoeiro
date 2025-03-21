//Bibliotecas do C
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Bibliotecas próprias
#include "arq.h"
#include  "configs.h"
#include "miscelania.h"

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
    
    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////
    
	int tamh=200,tamv=9,input=-1;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    
    programa_finalizar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////