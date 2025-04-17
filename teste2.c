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

void desenhar_fundo() {
    printf("\x1b[48;2;0;77;64m");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("                                                                                                                                                            \x1b[E");
    printf("\x1b[0m");
}



void desenhar_aposta() {
    printf("\e[62C\e[38;2;244;67;54m██████████████████████████████\e[0m\e[E");
    printf("\e[62C\e[38;2;244;67;54m██\e[38;2;255;255;255m██████████████████████████\e[38;2;244;67;54m██\e[0m\e[E");
    printf("\e[62C\e[38;2;244;67;54m██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[0m\e[E");
    printf("\e[62C\e[38;2;244;67;54m██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[0m\e[E");
    printf("\e[62C\e[38;2;244;67;54m██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[0m\e[E");
    printf("\e[62C\e[38;2;244;67;54m██\e[38;2;255;255;255m██████████████████████████\e[38;2;244;67;54m██\e[0m\e[E");
    printf("\e[62C\e[38;2;244;67;54m██████████████████████████████\e[0m\e[E");
}

int main () {

    windowsconfig();
    int cor=34;
    char lixo;
    scanf("%c",&lixo);
    system("cls");


    desenhar_fundo();
    printf("\e[H");
    desenhar_aposta();

    scanf(" %c",&lixo);
    
}
