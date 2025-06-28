//Defines
#define PRE_ROUND 0
#define PRIMEIRO_ROUND 1
#define SEGUNDO_ROUND 2
#define TERCEIRO_ROUND 3
#define MOSTRAR_CARTAS 4

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

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
#include "arvore.h"

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

    int iniciarJogo,iniciarConfig,etapa=PRE_ROUND, poker_vencedor,loopMusicaFinal=1,continua=1;
    //tp_jogador jogador[] <- declarado mais pra baixo pq depende de quant

    ArvoreComb arvore = arv_comb_inicializar();
    EstatisticasComb estat;
    iniciar_estatisticas(&estat);

    tp_pilhaSEcarta *baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];
    tp_listasecarta *mao_mesa;
    tp_cursor cursor;

    tp_pote pote;
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

    pote.maiorAposta=opcoes.apostaMinimaInicial;
    jogadores_setar_dinheiroInicial(jogador,pote.quantidadeJogadores,opcoes.dinheiroInicial);

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

    while(continua) {
        switch(etapa){
            case PRE_ROUND:
                animacao_animar_round1();
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();

                jogo_rodada_round_completo (jogador,&pote,&mao_mesa,&cursor);

                etapa = PRIMEIRO_ROUND;

            break;

            case PRIMEIRO_ROUND:
                animacao_animar_round2();
                if(condicao_rodada(jogador,&mao_mesa,pote.quantidadeJogadores)) {
                    baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                    baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                    baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                }
                
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);
                
                jogo_rodada_round_completo (jogador,&pote,&mao_mesa,&cursor);
            
                etapa = SEGUNDO_ROUND;
            
            break;

            case SEGUNDO_ROUND:
                async_thread_t musicadejogo2 = async_run(som_comecar_musicadejogo_2,&opcoes.VolumeFundo);
                animacao_animar_round3();
                
                if(condicao_rodada(jogador,&mao_mesa,pote.quantidadeJogadores)) {
                    baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                }
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);
                
                jogo_rodada_round_completo (jogador,&pote,&mao_mesa,&cursor);

                etapa = TERCEIRO_ROUND;

            break;

            case TERCEIRO_ROUND:
                async_thread_t musicadejogo3 = async_run(som_comecar_musicadejogo_3,&opcoes.VolumeFundo);
                animacao_animar_round4();

                if(condicao_rodada(jogador,&mao_mesa,pote.quantidadeJogadores)) {
                    baralho_distribuirCartas_mesa(baralhoJogo, &mao_mesa);
                }
                
                desenhar_fundo();
                if(opcoes.debug>0) printf("E%d\e[H", etapa);
                desenhar_mesaapoiodamesa();
                jogo_zerar_apostas(jogador, &pote, pote.quantidadeJogadores);

                jogo_rodada_round_desistencia (jogador,&pote,&mao_mesa,&cursor);

                etapa = MOSTRAR_CARTAS;
                continue;
            
            break;

            case MOSTRAR_CARTAS:
                async_thread_t musicadejogo4 = async_run(som_comecar_musicadejogo_4,&opcoes);
                combinacoes_verificar_jogadores(jogador,mao_mesa,&pote);
                
                combinacao_valor_mais_alto(jogador,pote.quantidadeJogadores);
                jogador_encontrar_maior_combinacao(jogador, &aux_ID_maior_combinacao, pote.quantidadeJogadores);
                poker_vencedor = jogador_vencedor(jogador, pote.quantidadeJogadores, aux_ID_maior_combinacao);
                int total = 0;
                if (jogador[poker_vencedor].combinacoes.par.quant > 0) total++;
                if (jogador[poker_vencedor].combinacoes.trinca.quant > 0) total++;
                if (jogador[poker_vencedor].combinacoes.straight.quant > 0) total++;
                if (jogador[poker_vencedor].combinacoes.flush.quant > 0) total++;
                if (jogador[poker_vencedor].combinacoes.fullHouse.quant > 0) total++;
                if (jogador[poker_vencedor].combinacoes.quadra.quant > 0) total++;
                if (jogador[poker_vencedor].combinacoes.straightFlush.quant > 0) total++;
                if (jogador[poker_vencedor].combinacoes.royalFlush.quant > 0) total++;

                arvore = arv_comb_inserir(arvore, etapa, total);
                jogador[poker_vencedor].dinheiro += pote.pote;
                jogo_telaFinal_misterio();
                opcoes.loopMusica=0;
                audio_play("finalselect",0);
                while(audio_is_playing("musicafinalpt1"));
                jogo_telaFinal_principal(jogador,&pote,mao_mesa,&cursor,poker_vencedor,opcoes.debug);
                salvar_estatisticas(&estat, "estatisticas.txt");
            break;

            default:
            break;
        }
    }
    arv_comb_salvar_em_arquivo(arvore, "combinacoes.txt");
    arv_comb_destruir(arvore);

    programa_finalizar();
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- FIM DA MAIN -- //
////////////////////////////////////////////////////////////////////////////////////////////////////////////