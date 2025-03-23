#ifndef ELEMENTOSVISUAIS_H
#define ELEMENTOSVISUAIS_H

typedef struct{
    int navegador;
    int confirmador;
} tp_cursor;

void cursor_zerarCursor(tp_cursor *cursor) {
    cursor->navegador=0;
    cursor->confirmador=0;
}

void menuinicial_imprimirSimbolo (int navegador) {
    int cor1,cor2;
    
    switch(navegador) {
        case 0:
        cor1=cor2=39;
        break;

        case 1:
        cor1=31;
        cor2=39;
        break;

        case 2:
        cor1=39;
        cor2=31;
        break;
    }

    limparTela();
    printf("\n\n\n\n\n\n\n\n");
    printf("                                      ███████████████                                          \n");
    printf("                                     █████████████████                                         \n");
    printf("                                     █████████████████                                         \n");
    printf("                                      ███████████████                                          \n");
    printf("                         ███       █████████████████████       ███                             \n");
    printf("                       ███████  ███████████████████████████  ███████                           \n");
    printf("                      ████████████████               ████████████████                          \n");
    printf("                     ██████████████                     ██████████████                         \n");
    printf("                    ████████████                          █████████████                        \n");
    printf("                   ████████████                             ████████████                             \e[%dm██    ██████      ██████      ████    ██████\e[39m\n",cor1);
    printf("                  ████████████            ████████           ████████████                            \e[%dm██  ██      ██  ██          ██    ██  ██    ██\e[39m\n",cor1);
    printf("                  ███████████            ██████████           ███████████                            \e[%dm██  ██      ██  ██  ████    ████████  ██████\e[39m\n",cor1);
    printf("                      ██████             ██████████            ██████                          \e[%dm██    ██  ██      ██  ██      ██  ██    ██  ██  ██\e[39m\n",cor1);
    printf("                       █████           ██████████████          █████                             \e[%dm████      ██████      ██████    ██    ██  ██    ██\e[39m\n",cor1);
    printf("                       █████        ████████████████████       █████                           \n");
    printf("                       █████       ██████████████████████      █████                           \n");
    printf("                       █████       ██████████████████████      █████                                                \e[%dm████  ████\e[39m     \n",cor2);
    printf("                      ██████        ████████████████████       ██████                                              \e[%dm████████████\e[39m    \n",cor2);
    printf("                  ███████████         █████  ██  █████        ███████████                                           \e[%dm██████████\e[39m     \n",cor2);
    printf("                  ████████████               ██              ████████████                                        \e[%dm██████    ██████\e[39m  \n",cor2);
    printf("                   ████████████             ████            ████████████                                        \e[%dm██████      ██████\e[39m \n",cor2);
    printf("                    █████████████                         █████████████                                          \e[%dm██████    ██████\e[39m  \n",cor2);
    printf("                     ██████████████                     ██████████████                                              \e[%dm██████████\e[39m     \n",cor2);
    printf("                      ████████████████               ████████████████                                              \e[%dm████████████\e[39m    \n",cor2);
    printf("                       ███████  ███████████████████████████  ███████                                                \e[%dm████  ████\e[39m     \n",cor2);
    printf("                         ███        ███████████████████        ███                              \n");
    printf("                                      ███████████████                                           \n");
    printf("                                     █████████████████                                         \n");
    printf("                                     █████████████████                                                   [Use WASD para navegar pelo menu]\n");
    printf("                                      ███████████████                                                     [Aperte F para confimar a ação]\n");
}

int menuinicial_navegar (tp_cursor *cursor) {
    menuinicial_imprimirSimbolo(cursor->navegador);

    int input;
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 119 && input != 115 && input != 102);

    switch(input) {
        case 119:
        cursor->navegador=1;
        break;

        case 115:
        cursor->navegador=2;
        break;

        case 102:
        if(cursor->navegador > 0) return cursor->navegador; 
        break;
    }

    return 0;
}









#endif