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
#include "async.h"
#include "audio.h"
#include "miscelanea.h"
#include "elementosvisuais.h"
#include "arquivo.h"
#include "cartas.h"
#include "configs.h"
#include "jogador.h"
#include "extradebug.h"
#include "combinacoes.h"
#include "funcoes_async.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN -- INÍCIO DA MAIN //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//Configura o console para windows (liga cores e outros caracteres)
	windowsconfig();

    //Configuração de audio
    audio_init();

    //////////////////////////// INICIALIZAÇÃO - ARQUIVOS - CONFIGURAÇÕES ////////////////////////////////
    
    opc opcoes;

    srand(time(NULL));

    opcoes.debug = 1;

    opcoes.modoDeSalvamento = 1;

    opcoes.nplayersdebug = 6;

    opcoes.VolumeFundo = 0;

    opcoes.VolumeEfeito = 0;

    console_cursor_invisivel(); //deixa cursor invisível

    //Audio
    audio_setar_audios();
    audio_setar_volume_efeito(opcoes.VolumeFundo);
    audio_setar_volume_fundo(opcoes.VolumeEfeito);
    
    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////

    int iniciarJogo,iniciarConfig,etapa=PRE_ROUND, poker_vencedor;
    //tp_jogador jogador[] <- declarado mais pra baixo pq depende de quant

    tp_pilhaSEcarta *baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];
    tp_listasecarta *mao_mesa;
    tp_cursor cursor;

    tp_pote pote;
    pote.maiorAposta=10;
    pote.pote=0;
    pote.maiorApostaJogadorID=-1;
    pote.quantidadeJogadores=0;

    tp_combinacaoMaior aux_ID_maior_combinacao;
    aux_ID_maior_combinacao.ID=-1;
    aux_ID_maior_combinacao.valorMaisAlto=-1;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    //Inicializa os baralhos
	baralhoReferencia_inicializar(baralhoReferencia);
    baralhoJogo=pilhaSEcarta_inicializar();
    baralho_embaralhar(baralhoReferencia,baralhoJogo);
    mao_mesa=listaSEcarta_inicializar();

    pote.quantidadeJogadores=3;
    
    tp_jogador jogador[pote.quantidadeJogadores];
    jogador_inicializar_mao(jogador, pote.quantidadeJogadores);
    debug_jogador_escolherNomes_discreto(jogador, pote.quantidadeJogadores);

    //Distribuição de cartas para os jogadores
    if(!baralho_distribuirCartas_jogadores(baralhoJogo, jogador, pote.quantidadeJogadores)) {
        printf("Erro na distribuição de cartas.\n");
        printf("O programa será encerrado.\n");

        programa_finalizar();
        return 22;
    }

    jogador[0].desistir=1;

    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    //baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    //baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);

    //debug_mostrarMaos (baralhoJogo, jogador, pote.quantidadeJogadores);

    combinacoes_verificar_jogadores(jogador,mao_mesa,&pote);

    combinacao_valor_mais_alto(jogador,pote.quantidadeJogadores);
    jogador_encontrar_maior_combinacao(jogador, &aux_ID_maior_combinacao, pote.quantidadeJogadores);
    poker_vencedor = jogador_vencedor(jogador, pote.quantidadeJogadores, aux_ID_maior_combinacao);
    
    jogo_telaFinal_principal(jogador,&pote,mao_mesa,&cursor,poker_vencedor,1);

    programa_pausar();
    programa_finalizar();
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////