#ifndef CONFIGS_H
#define CONFIGS_H

typedef struct {
	int debug, modoDeSalvamento, estiloCarta;
}opc;

void inicializacao(opc *opcoes) {
    //Definir Seed como Tempo
    srand(time(0));
    //Obter variáveis guardadas em opcoes.txt
    arq_lerOpcoes(&opcoes->debug,"debug = ","debug = %d");
    arq_lerOpcoes(&opcoes->estiloCarta,"EstiloCarta = ","EstiloCarta = %d");
    arq_lerOpcoes(&opcoes->modoDeSalvamento,"ModoDeSalvamento = ","ModoDeSalvamento = %d");
}



// Só pra windows -----------------------------------------------------------------------------------------------------
#ifdef _WIN32
#include <windows.h>

	void windowsconfig() {
		//Configuração de Console pro Windows (Cores e ANSII Escape Code) ---------------------
	        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	        DWORD dwMode = 0;
	        if (GetConsoleMode(hOut, &dwMode)) {
	            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	            SetConsoleMode(hOut, dwMode);
	        }
	        SetConsoleOutputCP(65001);
	
	}
#endif

#endif