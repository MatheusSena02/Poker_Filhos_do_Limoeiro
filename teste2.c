#include <stdio.h>
#include <windows.h>

#include <windows.h>
#include <stdio.h>

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


void desenhar_fundo() {
    printf("\e[48;2;0;77;64m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}



void desenhar_aposta() {
    printf("\e[62C\e[38;2;244;67;54m██████████████████████████████\e[E");
    printf("\e[62C██\e[38;2;255;255;255m██████████████████████████\e[38;2;244;67;54m██\e[E");
    printf("\e[62C██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[62C██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[62C██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[62C██\e[38;2;255;255;255m██████████████████████████\e[38;2;244;67;54m██\e[E");
    printf("\e[62C██████████████████████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cabecalho() {
    printf("\e[31E");
    printf("\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[38;2;128;203;196m████████████████████\e[38;2;0;0;0m██\e[E");
    printf("██████████████████████\e[E");
    printf("\e[20C██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[20C██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

int main () {

    windowsconfig();
    int cor=34;
    char lixo;
    scanf("%c",&lixo);
    system("cls");


    desenhar_fundo();
    desenhar_aposta();
    desenhar_cabecalho();

    scanf(" %c",&lixo);
    
}
