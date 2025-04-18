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
    //Verifica se o opcoes.txt já foi criado, se não foi, tenta criá-lo
    arq_verificarOpcoes();
    limparTela();
    //Obter variáveis guardadas em opcoes.txt e inicializa srand
    config_inicializacao(&opcoes);

    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////

    int quant,iniciarJogo,iniciarConfig;
    //tp_jogador jogador[quant] <- declarado mais pra baixo pq depende de quant

    tp_pilha baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];

    tp_cursor cursor;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////

	baralhoReferencia_inicializar(baralhoReferencia);
    baralho_embaralharPosicoes(&baralhoJogo);


    do {
        programa_iniciar();
        limparTela();

        cursor_zerarCursor(&cursor);
        while(1) if (menuinicial_navegar(&cursor) > 0) break;

        limparTela();

        if(cursor.navegador==2) {
            cursor_zerarCursor(&cursor);
            while(1) if (config_navegar(&cursor,&opcoes,baralhoReferencia)) break;
            limparTela();
    
        } 

    } while (cursor.navegador!=1);

    if (opcoes.debug) debug1(baralhoReferencia, opcoes, &baralhoJogo);
    
    quant=jogador_escolherQuantidade();
    tp_jogador jogador[quant];
    
    jogador_escolherNomes(jogador, quant);
    programa_pausar();

    if(!baralho_distribuirCartas_jogadores(&baralhoJogo, jogador, quant)) {
        limparTela();
        printf("Erro na distribuição de cartas.\n");
        printf("O programa será encerrado.\n");

        programa_finalizar();
        return 22;
    }


    programa_finalizar();

    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////