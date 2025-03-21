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
	#else
	linuxconfig();
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
    
	tp_carta baralho[52];
	baralho_inicializar(baralho);
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    
    
    baralho_printar(baralho,opcoes.estiloCarta);
    
    





    programa_finalizar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////