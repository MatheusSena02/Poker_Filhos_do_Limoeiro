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
	tp_carta baralhoReferencia[52],baralhoB[52];
    tp_listasecarta *mao_mesa;
    
    //////////////////////////// --------- INICIO DO PROGRAMA --------- ////////////////////////////////
    
    //DEFINIR AS CARTAS DA MESA?
    int definir=0;
    //Poe aq as posições da carta no baralhoreferencia (usa o catalogo.exe pra ver), é o segundo numero q aparece
    int IDS[]={0,12,11,9,10};
    

    //DEFINIR AS CARTAS DO JOGADOR?
    int definirJ=0;

    //Poe aq as posições da carta no baralhoreferencia (usa o catalogo.exe pra ver), é o segundo numero q aparece
    int IJS[]={27,33};


    //Para mudar a seed, abra seed.txt
    //Aleatório = 0
    //Pra definir alguma, escreve qualquer numero ou palavra sla, isso vai ser a seed








    FILE *arq = fopen("seed.txt","r");
    int num;
    fscanf(arq,"%d",&num);
    if (num!=0) srand(num);
    else srand(time(NULL));

	baralhoReferencia_inicializar(baralhoReferencia);
    baralhoReferencia_inicializar(baralhoB);
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
    
    if (definir) {
        mao_mesa->info=baralhoB[IDS[0]];
        mao_mesa->prox->info=baralhoB[IDS[1]];
        mao_mesa->prox->prox->info=baralhoB[IDS[2]];
        mao_mesa->prox->prox->prox->info=baralhoB[IDS[3]];
        mao_mesa->prox->prox->prox->prox->info=baralhoB[IDS[4]];
    }
    
    if (definirJ) {
        jogador[0].mao->info=baralhoB[IJS[0]];
        jogador[0].mao->prox->info=baralhoB[IJS[1]];
    }
    
    combinacoes_verificar_valores(&jogador[0],mao_mesa,jogador[0].mao,jogador[0].comparadorValor);
    combinacoes_verificar_naipes(&jogador[0],mao_mesa,jogador[0].mao,jogador[0].comparadorValor);

    combinacoes_verificar_sequencias(&jogador[0],mao_mesa,jogador[0].mao);
    combinacoes_verificar_royalFlush (&jogador[0],mao_mesa, jogador[0].mao); 

    combinacao_imprimir_maocombinada(&jogador[0],mao_mesa, jogador[0].mao);

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

    if (jogador[0].combinacoes.flush.quant>0) printf("O jogador[0] tem um flush de naipe %d\n",jogador[0].combinacoes.flush.naipeMaisAlto);

    if (jogador[0].combinacoes.straight.quant>0) printf("O jogador[0] tem %d straight de",jogador[0].combinacoes.straight.quant);
    if (jogador[0].combinacoes.straight.quant==1) printf(" %d\n",jogador[0].combinacoes.straight.valorMaisAlto);

    if (jogador[0].combinacoes.straightFlush.quant>0) printf("O jogador[0] tem %d straightFlush de",jogador[0].combinacoes.straightFlush.quant);
    if (jogador[0].combinacoes.straightFlush.quant==1) printf(" %d",jogador[0].combinacoes.straightFlush.valorMaisAlto);
    if (jogador[0].combinacoes.straightFlush.quant==1) printf(" naipe %d\n",jogador[0].combinacoes.straightFlush.naipeMaisAlto);

    if (jogador[0].combinacoes.royalFlush.quant>0) printf("O jogador[0] tem %d royalFlush de",jogador[0].combinacoes.royalFlush.quant);
    if (jogador[0].combinacoes.royalFlush.quant==1) printf(" %d\n",jogador[0].combinacoes.royalFlush.naipeMaisAlto);

    printf("O maior valor de carta do jogador[0] é %d\n",jogador[0].maiorInfo.valor);
    printf("O maior valor de naipe do jogador[0] é %d\n",jogador[0].maiorInfo.naipe);
 
    programa_pausar();
    programa_finalizar();

    return 1;
}