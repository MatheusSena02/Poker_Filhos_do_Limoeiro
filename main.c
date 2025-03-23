//Bibliotecas do C
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

//Bibliotecas próprias
#include "miscelanea.h"
#include "elementosvisuais.h"
#include "arquivo.h"
#include "cartas.h"
#include "configs.h"
#include "pilha.h"
#include "jogador.h"
#include "extradebug.h"


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
    limparTela();

    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////

    tp_cursor cursor;
    cursor_zerarCursor(&cursor);
    while(1) if (menuinicial_navegar(&cursor) > 0) break;

    limparTela();

    int quant,iniciarJogo,iniciarConfig;
    //tp_jogador jogador[quant] <- declarado mais pra baixo pq depende de quant

    tp_pilha baralhoJogo;
	tp_carta baralhoReferencia[52];
	baralhoReferencia_inicializar(baralhoReferencia);
    baralho_embaralharPosicoes(&baralhoJogo);

    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////

    if(cursor.navegador==2) {
        cursor_zerarCursor(&cursor);
        while(1) if (config_navegar(&cursor,&opcoes,baralhoReferencia)) break;

    } else if (cursor.navegador==1) {
        if (opcoes.debug) debug1(baralhoReferencia, opcoes, &baralhoJogo);

        quant=jogador_escolherQuantidade();
        tp_jogador jogador[quant];
    
        jogador_escolherNomes(jogador, quant);

    }





    programa_finalizar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////