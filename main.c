//Defines
#define PRE_ROUND 0
#define PRIMEIRO_ROUND 1
#define SEGUNDO_ROUND 2
#define TERCEIRO_ROUND 3
#define MOSTRAR_CARTAS 4

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
#include "combinacoes.h"


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

    int quant,iniciarJogo,iniciarConfig,etapa=PRE_ROUND;;
    //tp_jogador jogador[quant] <- declarado mais pra baixo pq depende de quant

    tp_pilhaSEcarta *baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];
    tp_listasecarta *mao_mesa;
    tp_cursor cursor;

    tp_pote pote;
    pote.maiorAposta=1;
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
    if (opcoes.debug>1) quant=3;
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

    while(1) {
        switch(etapa){
            case PRE_ROUND:
            if(opcoes.debug>0) printf("=== Entrou em ETAPA %d ===\n", etapa);
            // esse aq vai ser o pre round onde n tem nenhuma carta na mesa ainda
            // porem tem as cartas dos jogadores
            //aq vai ocorrer as primeiras apostas e dessistencias

                for(int i=0;i<quant;i++) {
                    jogo_jogador_rodada(&jogador[i],&cursor,&pote);
                }
                etapa = PRIMEIRO_ROUND;

            break;

            case PRIMEIRO_ROUND:
            if(opcoes.debug>0) printf("=== Entrou em ETAPA %d ===\n", etapa);
            baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa); // aq ja temos o primeiro round com tres cartas na mesa;
            baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
            baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
            for(int i=0;i<quant;i++) {
                    jogo_jogador_rodada(&jogador[i],&cursor,&pote);
                }
            etapa = SEGUNDO_ROUND;
            break;

            case SEGUNDO_ROUND:
            if(opcoes.debug>0) printf("=== Entrou em ETAPA %d ===\n", etapa);
            baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa); // aq temos o segundo roud adicionando mais uma carta a mesa
            for(int i=0;i<quant;i++) {
                    jogo_jogador_rodada(&jogador[i],&cursor,&pote);
                }
            etapa = TERCEIRO_ROUND;
            break;

            case TERCEIRO_ROUND:

            if(opcoes.debug>0) printf("=== Entrou em ETAPA %d ===\n", etapa);
            baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa); // aq temos o terceiro round e o ultimo antes de mostrar as cartas, adicionando tmb mais uma carta a mesa
            for(int i=0;i<quant;i++) {
                    jogo_jogador_rodada(&jogador[i],&cursor,&pote);
                }
            etapa = MOSTRAR_CARTAS;
            break;

            case MOSTRAR_CARTAS:
            // aq vai ter as comparações de quem tem a maior mão e vai decidir quem será o vencedor
            break;

            default:
            break;
        }

        if(!condicao_rodada(jogador,&mao_mesa,quant)) break;
    }

    programa_finalizar();

    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////