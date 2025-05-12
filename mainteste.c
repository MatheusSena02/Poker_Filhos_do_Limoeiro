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
#include "combinacoesteste.h"

int main()
{

    windowsconfig();

    int quant;

    tp_pilhaSEcarta *baralhoJogo;       //BARALHO PARA OS JOGADORES
	tp_carta baralhoReferencia[52];
    tp_listasecarta *mao_mesa;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    //Inicializa os baralhos

    srand(time(NULL));

	baralhoReferencia_inicializar(baralhoReferencia);
    baralhoJogo=pilhaSEcarta_inicializar();

    baralho_embaralhar(baralhoReferencia,baralhoJogo);
    mao_mesa=listaSEcarta_inicializar();

    
    quant=1;
    tp_jogador jogador[quant];

    jogador_inicializar_mao(jogador, quant);
    debug_jogador_escolherNomes(jogador, quant);

    //Distribuição de cartas para os jogadores
    if(!baralho_distribuirCartas_jogadores(baralhoJogo, jogador, quant)) {
        printf("Erro na distribuição de cartas.\n");
        printf("O programa será encerrado.\n");

        programa_finalizar();
        return 22;
    }

    debug_mostrarMaos (baralhoJogo, jogador, quant);
    limparTela();

    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);
    baralho_distribuirCartas_mesa(baralhoJogo,&mao_mesa);

    combinacoes_verificar_valores(jogador,mao_mesa,jogador[0].mao,jogador[0].comparadorValor);
    combinacoes_verificar_naipes(jogador,mao_mesa,jogador[0].mao,jogador[0].comparadorValor);


    if (jogador[0].combinacoes.par.quant>0) printf("O jogador[0] tem %d par(es) de",jogador[0].combinacoes.par.quant);
    if (jogador[0].combinacoes.par.quant==1) printf(" %d\n",jogador[0].combinacoes.par.valorMaisAlto);
    if (jogador[0].combinacoes.par.quant==2) printf(" %d e %d\n",jogador[0].combinacoes.par.valorMaisAlto,jogador[0].combinacoes.par.valorMaisAltoReserva);

    if (jogador[0].combinacoes.trinca.quant>0) printf("O jogador[0] tem %d trinca(s) de",jogador[0].combinacoes.trinca.quant);
    if (jogador[0].combinacoes.trinca.quant==1) printf(" %d\n",jogador[0].combinacoes.trinca.valorMaisAlto);
    if (jogador[0].combinacoes.trinca.quant==2) printf(" %d e %d\n",jogador[0].combinacoes.trinca.valorMaisAlto,jogador[0].combinacoes.trinca.valorMaisAltoReserva);

    if (jogador[0].combinacoes.quadra.quant>0) printf("O jogador[0] tem %d quadra(s) de",jogador[0].combinacoes.quadra.quant);
    if (jogador[0].combinacoes.quadra.quant==1) printf(" %d\n",jogador[0].combinacoes.quadra.valorMaisAlto);
    if (jogador[0].combinacoes.quadra.quant==2) printf(" %d e %d\n",jogador[0].combinacoes.quadra.valorMaisAlto,jogador[0].combinacoes.quadra.valorMaisAltoReserva);

    if (jogador[0].combinacoes.fullHouse.quant>0) printf("O jogador[0] tem um fulHouse\n");

    if (jogador[0].combinacoes.flush.quant>0) printf("O jogador[0] tem um flush\n");

    printf("O maior valor de carta do jogador[0] é %d\n",jogador[0].maiorInfo.valor);
    printf("O maior valor de naipe do jogador[0] é %d\n",jogador[0].maiorInfo.naipe);

    programa_pausar();
    programa_finalizar();

    return 1;
}