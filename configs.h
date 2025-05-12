#ifndef CONFIGS_H
#define CONFIGS_H

typedef struct {
	int debug, modoDeSalvamento, nplayersdebug;
}opc;

void arq_atualizarOpcoes (opc *opcoes) {
    // Função para gerar o conteudo de opcoes.txt com conteúdo obtido in-game
    FILE *arq;
    arq=fopen("opcoes.txt","w");
    if (arq) {
        fprintf(arq,"--- Opções ---\n\n");
        fprintf(arq,"//Modo de debug ( 0 = Desativado [Padrão] / 1 = Simples / 2 = Facilita Testes)\n");
        fprintf(arq,"// Simples -> prinfs de avisos e monitoramento\n");
        fprintf(arq,"//Facilita Testes -> Simples + pula partes do jogo para facilitar os testes\n");
        fprintf(arq,"debug = %d\n\n",opcoes->debug);
        fprintf(arq,"//Número de Players do Modo Debug ( 6 = [Padrão])\n");
        fprintf(arq,"// Só é utilizado no modo debug 2\n");
        fprintf(arq,"NumeroDePlayersDebug = %d\n\n",opcoes->nplayersdebug);
        fprintf(arq,"// Seleciona como será formatado o .txt que salva o histórico cada partida ( 1 = Data e Hora [Padrão] / 0 = partida.txt )\n");
        fprintf(arq,"// Recomendação:  Windows / OnlineGDB = 1 / Replit = 0\n");
        fprintf(arq,"ModoDeSalvamento = %d\n\n",opcoes->modoDeSalvamento);
        fprintf(arq,"\n\n\n\n\n\n//-->Esse código foi feito para rodar em sistemas Windows e é onde funciona normalmente\n");
        fprintf(arq,"//-->Em sites que rodam Linux, algumas funções são diferentes, o que causa erro na função de obtenção de Data e Hora\n");
        fclose(arq);
    }
}

void config_inverter(int *a) {
	//Inverte uma configuração/booleano entre 0 e 1
	if (*a==1) *a=0;
	else *a=1; 
}

void config_alternar(int *a,int numeroDeEstados) {
	//Alterna uma configuracão em inteiros entre 0 a numeroDeEstados
	if (((*a)+1)<numeroDeEstados) *a+=1;
	else *a=0; 
}

void config_alternar_semZero(int *a,int numeroDeEstados) {
	//Alterna uma configuracão em inteiros entre 0 a numeroDeEstados
	if (((*a)+1)<=numeroDeEstados) *a+=1;
	else *a=1; 
}

void config_inicializacao(opc *opcoes) {
    //Definir Seed como Tempo
    srand(time(NULL));
    //Obter variáveis guardadas em opcoes.txt
    if (!arq_lerOpcoes(&opcoes->debug,"debug = ","debug = %d")) opcoes->debug = 0;

	#ifdef _WIN32
    if (!arq_lerOpcoes(&opcoes->modoDeSalvamento,"ModoDeSalvamento = ","ModoDeSalvamento = %d")) opcoes->modoDeSalvamento = 1;
	#else
	if (!arq_lerOpcoes(&opcoes->modoDeSalvamento,"ModoDeSalvamento = ","ModoDeSalvamento = %d")) opcoes->modoDeSalvamento = 0;
	#endif

    if (!arq_lerOpcoes(&opcoes->nplayersdebug,"NumeroDePlayersDebug = ","NumeroDePlayersDebug = %d")) opcoes->nplayersdebug = 6;

}

void config_impressao(opc *opcoes,int pos,tp_carta baralho[]) {
	//Imprime o menu de configuração
	limparTela();
	int cor[4]={39,39,39,39};
	cor[pos] = 31;

	printf("===================================================================\n");
	printf("=----------------------------\e[1mOPÇÕES\e[22m-------------------------------=\n");
	printf("===================================================================\n");
	printf("=        0 = Falso/Desativado | 1 = Verdadeiro/Ativado            =\n");
	printf("===================================================================\n");
	printf("=           Use WASD para navegar e F para selecionar             =\n");
	printf("===================================================================\n\n");
	printf("\e[%dm => \e[1mModo de Debug = %d\e[39m\e[22m\n",cor[0],opcoes->debug);
	printf("\e[33m// Modo de debug \e[3m( \e[93m0 = Desativado [Padrão]\e[33m / 1 = Simples / 2 = Facilita Testes)\e[39m\e[23m\n");
	printf("\e[33m// Simples -> prinfs de avisos e monitoramento\e[39m\n");
    printf("\e[33m// Facilita Testes -> Simples + pula partes do jogo para facilitar os testes\e[39m\n\n");
	printf("===================================================================\n\n");
	printf("\e[%dm => \e[1mNúmero de Players do Modo Debug = %d\e[39m\e[22m\n",cor[1],opcoes->nplayersdebug);
	printf("\e[33m// Só é utilizado no modo debug 2 \e[3m( \e[93m6 = 6 Players [Padrão] \e[33m)\e[39m\e[23m\n\n");
	printf("===================================================================\n\n");
    printf("\e[%dm => \e[1mModo de Salvamento = %d\e[39m\e[22m\n",cor[2],opcoes->modoDeSalvamento);
	printf("\e[33m// Seleciona a formatação do .txt que salva o histórico\e[39m\n");
	printf("\e[33m//\e[3m ( \e[93m1 = Data e Hora [Padrão]\e[33m / 0 = partida.txt)\e[39m\n\e[23m");
	printf("\e[33m// Recomendação:  Windows / OnlineGDB = 1 / Replit = 0\e[39m\n\n");
	printf("===================================================================\n\n");

	printf("\n\n\e[%dmSalvar configurações e reiniciar o programa\e[39m\n",cor[3]);
}

int config_navegar (tp_cursor *cursor,opc *opcoes,tp_carta baralho[]) {
	//Função para permitir a navegação no menu de configuração usando W,S e F
	// W = 119
	// S = 115
	// F = 102
	// Conforme navegador muda de valor, é como se indicasse qual opção ta com o mouse em cima
	// O F serve pra confirmar a seleção
	// A posição 0 é a mais alta
	int numeroDeOpcoes=4;
	config_impressao(opcoes,cursor->navegador,baralho);

    int input;
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 119 && input != 115 && input != 102 && input != 120);

    switch(input) {
        case 119:
        	if ((cursor->navegador - 1)>=0) cursor->navegador-=1;
			else cursor->navegador=(numeroDeOpcoes-1);
        break;

        case 115:
        	if ((cursor->navegador + 1) < numeroDeOpcoes) cursor->navegador+=1;
			else cursor->navegador=0;
        break;

        case 102:
			switch (cursor->navegador) {
				case 0:
					config_alternar(&opcoes->debug,3);
				break;

                case 1:
					config_alternar_semZero(&opcoes->nplayersdebug,6);
				break;

				case 2:
					config_inverter(&opcoes->modoDeSalvamento);
				break;

				case 3:
					arq_atualizarOpcoes(opcoes);
					return 1;
				break;
			}
        break;

        case 120:
        arq_atualizarOpcoes(opcoes);
        return 1;
    }

	return 0;
}



// Só pra windows -----------------------------------------------------------------------------------------------------
#ifdef _WIN32
#include <windows.h>

void windowsconfig() {
    // Essa função é de uma biblioteca externa, não influencia diretamente a lógica do jogo
    // Configuração de Console pro Windows (Cores, ANSI Escape Code e Tamanho) -------------

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    // Habilita processamento de ANSI Escape Sequences
    if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }

    // Define código de página UTF‑8
    SetConsoleOutputCP(CP_UTF8);

    // Redimensiona buffer e janela para 100 colunas × 40 linhas
    COORD newSize = { 156, 44 };
    // Ajusta o tamanho do buffer de tela
    SetConsoleScreenBufferSize(hOut, newSize);

    // Define a área visível da janela igual ao tamanho do buffer
    SMALL_RECT displayArea = {
        0,               // Left
        0,               // Top
        newSize.X - 1,   // Right
        newSize.Y - 1    // Bottom
    };
    SetConsoleWindowInfo(hOut, TRUE, &displayArea);
}

//Só pra linux --------------------------------------------------------------------------------------------------------
#else
#include <locale.h>

    void linuxconfig() {
			// Essa função é de uma biblioteca externa, não influencia diretamente a lógica do jogo
        setlocale(LC_ALL, "pt_BR.UTF-8");
    }

#endif

#endif