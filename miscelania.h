#ifndef MISCENALIA_H
#define MISCELANIA_H
#include <stdio.h>
#include <time.h>

//pro getch
#include <unistd.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#endif




int aleatorio(int min, int max) {
    //Obter numero aleatorio e retornar
    int aleat = (rand() % ((max+1) - min)) + min;
    return aleat;
}

void limparTela() {
//Funciona tipo um system("clear") mas com ANSII Escape Code
    printf("\x1b[H\x1b[0J\x1b[H");
}
    
int getch() {
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

    // Obtém os atributos atuais do terminal
    tcgetattr(STDIN_FILENO, &oldAttr);
    newAttr = oldAttr;
    
    // Desabilita o modo canônico (entrada bufferizada) e o eco
    newAttr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);

    ch = getchar();

    // Restaura as configurações originais do terminal
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
    } while (input != 102 && input != 70);


}

void programa_iniciar () {
    
    int input;
    printf("Por favor coloque o programa em tela cheia\n");
    printf("Aperte F para continuar\n");
    
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102 && input != 70);

}


#endif