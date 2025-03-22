//Bibliotecas do C
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

//Bibliotecas próprias
#include "arquivo.h"
#include  "configs.h"
#include "miscelanea.h"
#include "cartas.h"
#include "pilha.h"
#include "jogador.h"

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
    
    int quant=jogador_escolherQuantidade();
    tp_jogador jogador[quant];
    
    tp_pilha baralhoJogo;
	tp_carta baralho[52];
	baralho_inicializar(baralho);
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    
    jogador_escolherNomes(jogador, quant);
    //baralho_printar(baralho,opcoes.estiloCarta);
    //embaralhar_cartas(&baralhoJogo);
    //pilha_imprimir(baralhoJogo);
    





    programa_finalizar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////