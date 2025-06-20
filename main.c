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
    
	//Variáveis das configurações -> opcoes.txt
    opc opcoes;
    //Verifica se o opcoes.txt já foi criado, se não foi, tenta criá-lo
    arq_verificarOpcoes();
    limparTela();
    //Obter variáveis guardadas em opcoes.txt e inicializa srand
    config_inicializacao(&opcoes);
    console_cursor_invisivel(); //deixa cursor invisível

    //Audio
    audio_setar_audios();
    audio_setar_volume_efeito(opcoes.VolumeEfeito);
    audio_setar_volume_fundo(opcoes.VolumeFundo);
    
    //////////////////////////// ------- DECLARAÇÃO DE VARIÁVEIS ------- ////////////////////////////////

    int iniciarJogo,iniciarConfig,etapa=PRE_ROUND;
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

    //Menu inicial e configurações

    do {
        
        programa_iniciar();
        if (!audio_is_playing("temainicial")) audio_play("temainicial",1);
        limparTela();

        cursor_zerarCursor(&cursor);
        desenhar_fundoinicial();
        desenhar_fichainicial();

        audio_setar_volume_efeito(opcoes.VolumeEfeito);
        audio_setar_volume_fundo(opcoes.VolumeFundo);

        while(1) if (menuinicial_navegar(&cursor) > 0) break;

        audio_play("botao",0);
        
        if (cursor.navegador==1){
            audio_setar_volume_efeito(opcoes.VolumeEfeito);
            audio_setar_volume_fundo(opcoes.VolumeFundo);
            async_thread_t comecarintro = async_run(som_comecar_intro,&opcoes.VolumeFundo);
            if (opcoes.debug!=2) Sleep(1000);
            if (opcoes.debug!=2) desenhar_fundo_espiral_com_cor("0;0;0");
        }

        if(cursor.navegador==2) {
            limparTela();
            cursor_zerarCursor(&cursor);
            while(1) if (config_navegar(&cursor,&opcoes,baralhoReferencia)) break;
            limparTela();
    
        } 

    } while (cursor.navegador!=1);

    //Mostrar baralhos se debug for 1
    if (opcoes.debug == 1) debug_mostrarBaralhos(baralhoReferencia, opcoes, baralhoJogo);
    
    //Se debug estiver desligado, escolhe quantidade de players
    if (opcoes.debug>1) pote.quantidadeJogadores=opcoes.nplayersdebug;
    else pote.quantidadeJogadores=jogador_escolherQuantidade(&cursor);

    tp_jogador jogador[pote.quantidadeJogadores];
    jogador_inicializar_mao(jogador, pote.quantidadeJogadores);

    //Se debug for diferente de 2, escolhe os nomes dos players
    if (opcoes.debug==2) debug_jogador_escolherNomes(jogador, pote.quantidadeJogadores);
    else {
        desenhar_fundopreto();
        jogador_escolherNomes(jogador, pote.quantidadeJogadores);
    }

    programa_pausar();

    async_thread_t musicadejogo1 = async_run(som_comecar_musicadejogo_1,&opcoes.VolumeFundo);
    
    limparTela();

    //Distribuição de cartas para os jogadores
    if(!baralho_distribuirCartas_jogadores(baralhoJogo, jogador, pote.quantidadeJogadores)) {
        printf("Erro na distribuição de cartas.\n");
        printf("O programa será encerrado.\n");

        programa_finalizar();
        return 22;
    }

    if (opcoes.debug==1) debug_mostrarMaos (baralhoJogo, jogador, pote.quantidadeJogadores);

    while(1) {
        switch(etapa){
            case PRE_ROUND:
                // esse aq vai ser o pre round onde n tem nenhuma carta na mesa ainda
                // porem tem as cartas dos jogadores
                //aq vai ocorrer as primeiras apostas e dessistencias
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();

                do {
                    for(int i=0;i<pote.quantidadeJogadores;i++) {
                        if (!jogador[i].desistir) jogo_jogador_rodada(&jogador[i],&cursor,&pote,mao_mesa,jogador);
                    }
                } while(jogo_rodada_verificar_continuarRodada(jogador,&pote,pote.quantidadeJogadores));

                etapa = PRIMEIRO_ROUND;

            break;

            case PRIMEIRO_ROUND:
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa); // aq ja temos o primeiro round com tres cartas na mesa;
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);
                
                do {
                    for(int i=0;i<pote.quantidadeJogadores;i++) {
                        if (!jogador[i].desistir) jogo_jogador_rodada(&jogador[i],&cursor,&pote,mao_mesa,jogador);
                    }
                } while(jogo_rodada_verificar_continuarRodada(jogador,&pote,pote.quantidadeJogadores));
            
                etapa = SEGUNDO_ROUND;
            
            break;

            case SEGUNDO_ROUND:
                async_thread_t musicadejogo2 = async_run(som_comecar_musicadejogo_2,&opcoes.VolumeFundo);
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa); // aq temos o segundo roud adicionando mais uma carta a mesa

                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);
                
                do {
                    for(int i=0;i<pote.quantidadeJogadores;i++) {
                        if (!jogador[i].desistir) jogo_jogador_rodada(&jogador[i],&cursor,&pote,mao_mesa,jogador);
                    }
                } while(jogo_rodada_verificar_continuarRodada(jogador,&pote,pote.quantidadeJogadores));

                etapa = TERCEIRO_ROUND;

            break;

            case TERCEIRO_ROUND:
                async_thread_t musicadejogo3 = async_run(som_comecar_musicadejogo_3,&opcoes.VolumeFundo);
                baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa); // aq temos o terceiro round e o ultimo antes de mostrar as cartas, adicionando tmb mais uma carta a mesa
                
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);

                do {
                    for(int i=0;i<pote.quantidadeJogadores;i++) {
                        if (!jogador[i].desistir) jogo_jogador_rodada(&jogador[i],&cursor,&pote,mao_mesa,jogador);
                    }
                } while(jogo_rodada_verificar_continuarRodada(jogador,&pote,pote.quantidadeJogadores));

                etapa = MOSTRAR_CARTAS;
            
            break;

            case MOSTRAR_CARTAS:
                if(opcoes.debug>0) printf("E%d\n", etapa);
                combinacao_valor_mais_alto(jogador,pote.quantidadeJogadores);
                

                for(int i=0;i<pote.quantidadeJogadores;i++){
                    if(jogador[i].combinacoes.combinacaoMaior.ID > aux_ID_maior_combinacao.ID){
                       aux_ID_maior_combinacao.ID = jogador[i].combinacoes.combinacaoMaior.ID;
                    }
                    else if(jogador[i].combinacoes.combinacaoMaior.ID == aux_ID_maior_combinacao.ID){
                        aux_ID_maior_combinacao.ID = jogador[i].combinacoes.combinacaoMaior.valorMaisAlto;
                    }

                }
                
                // aq vai ter as comparações de quem tem a maior mão e vai decidir quem será o vencedor
            break;

            default:
            break;
        }

        if(!condicao_rodada(jogador,&mao_mesa,pote.quantidadeJogadores)) break;
    }

    programa_finalizar();
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////