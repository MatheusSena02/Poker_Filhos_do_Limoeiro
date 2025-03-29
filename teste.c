#include <stdio.h>
#include <windows.h>

void windowsconfig() {
    // Essa função é de uma biblioteca externa, não influencia diretamente a lógica do jogo
    //Configuração de Console pro Windows (Cores e ANSII Escape Code) ---------------------
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
        SetConsoleOutputCP(65001);

}

int main () {

    windowsconfig();
    //♥
    printf("\n\nteste");
    printf("         \e[1B\e[9D\e");
    printf("\e[107m\e[39m");
    printf(" 1       \e[1B\e[9D\e");
    printf(" 1       \e[1B\e[9D\e");
    

    printf("\e[49m\e[39m");
    printf("\n\n\n\n\n");
    system("pause");


    
}


if(carta->valor_i != 10) printf(" _______ \e[1B\e[9D|       |\e[1B\e[9D| %s     |\e[1B\e[9D|       |\e[1B\e[9D|   %s   |\e[1B\e[9D|       |\e[1B\e[9D|     %s |\e[1B\e[9D|_______|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
else printf(" _______ \e[1B\e[9D|       |\e[1B\e[9D|%s     |\e[1B\e[9D|       |\e[1B\e[9D|   %s   |\e[1B\e[9D|       |\e[1B\e[9D|     %s|\e[1B\e[9D|_______|",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);