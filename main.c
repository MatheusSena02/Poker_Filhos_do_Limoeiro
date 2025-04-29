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
    console_cursor_invisivel(); //deixa cursor invisível

    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////

    int quant,iniciarJogo,iniciarConfig;
    //tp_jogador jogador[quant] <- declarado mais pra baixo pq depende de quant

    tp_pilhaSEcarta *baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];
    tp_listasecarta *mao_mesa;
    tp_cursor cursor;

    tp_pote pote;
    pote.maiorAposta=0;
    pote.pote=0;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    //Inicializa os baralhos
	baralhoReferencia_inicializar(baralhoReferencia);
    baralhoJogo=pilhaSEcarta_inicializar();
    baralho_embaralhar(baralhoReferencia,baralhoJogo);
    mao_mesa=listaSEcarta_inicializar();

    //Menu inicial e configurações
    do {
        programa_iniciar();
        limparTela();

        cursor_zerarCursor(&cursor);
        desenhar_fundoinicial();
        desenhar_fichainicial();

        while(1) if (menuinicial_navegar(&cursor) > 0) break;

        limparTela();

        if(cursor.navegador==2) {
            cursor_zerarCursor(&cursor);
            while(1) if (config_navegar(&cursor,&opcoes,baralhoReferencia)) break;
            limparTela();
    
        } 

    } while (cursor.navegador!=1);

    //Mostrar baralhos se debug for 1
    if (opcoes.debug == 1) debug_mostrarBaralhos(baralhoReferencia, opcoes, baralhoJogo);
    
    //Se debug estiver desligado, escolhe quantidade de players
    if (opcoes.debug>1) quant=6;
    else quant=jogador_escolherQuantidade();

    tp_jogador jogador[quant];
    jogador_inicializar_mao(jogador, quant);

    //Se debug for diferente de 2, escolhe os nomes dos players
    if (opcoes.debug==2) debug_jogador_escolherNomes(jogador, quant);
    else jogador_escolherNomes(jogador, quant);

    programa_pausar();
    limparTela();

    //Distribuição de cartas para os jogadores
    if(!baralho_distribuirCartas_jogadores(baralhoJogo, jogador, quant)) {
        printf("Erro na distribuição de cartas.\n");
        printf("O programa será encerrado.\n");

        programa_finalizar();
        return 22;
    }

    if (opcoes.debug==1) debug_mostrarMaos (baralhoReferencia, jogador, quant);

    
    desenhar_fundo();
    for(int i=0;i<quant;i++) {
    jogo_jogador_rodada(&jogador[i],&cursor,&pote);
    }

    programa_finalizar();

    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////