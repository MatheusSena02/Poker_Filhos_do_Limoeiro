#ifndef MISCELANEA_H
#define MISCELANEA_H
#include <stdio.h>
#include <time.h>

//pro getch
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif




int aleatorio(int min, int max) {
    //Obter numero aleatorio e retornar
    int aleat = (rand() % ((max+1) - min)) + min;
    return aleat;
}

void limparTela() {
//Funciona tipo um system("clear") mas com ANSII Escape Code
//Vai funcionar tanto em LINUX (replit) quanto em WINDOWS
    printf("\e[H\e[0J\e[H");
}


void imprimir_float_centralizado(float valor, int largura) {
    //Imprime um valor dado de forma certralizada (e com 2 casas decimais)
    //Em largura coloca o espaço maximo que pode ocupar
    char texto[64];
    
    //Converte o valor em string com 2 casas decimais
    snprintf(texto, sizeof(texto), "%.2f", valor);
    
    //Troca ponto por vírgula
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '.') {
            texto[i] = ',';
            break;
        }
    }
    
    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%s\n", texto);
        return;
    }

    //Calcula quantos espaços são necessários
    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime o número
    printf("%s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}


int getch() {
// Essa função é de uma biblioteca externa, não influencia diretamente a lógica do jogo
//Serve pra ler um input do usuário sem esperar pelo enter
// Como usar no windows e linux (dessa forma pega nos 2):     while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada

#ifdef _WIN32

	if (_kbhit()) {
        return _getch();
	}
    return -1; 

#else
    struct termios oldAttr, newAttr;
    int ch;

    tcgetattr(STDIN_FILENO, &oldAttr);
    newAttr = oldAttr;
    
    newAttr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldAttr);
    
    return ch;

#endif
}

void programa_finalizar () {
    
    int input;
    printf("\e[65;0H");
    printf("Aperte F para encerrar o programa\n");
    
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);


}

void programa_pausar () {
    
    int input;
    printf("Aperte F para continuar...\n");
    
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);


}

void programa_iniciar () {
    
    int input;
    printf("Se possível, use a resolução 1280 x 720p\n");
    printf("Por favor coloque o programa em tela cheia\n");
    printf("Aperte F para continuar\n");
    
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);

}

#endif