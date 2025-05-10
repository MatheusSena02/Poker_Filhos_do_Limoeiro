#include <windows.h>
#include <stdio.h>
#include "miscelanea.h"

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

void desenhar_jogadoraposta() {
    printf("\e[28E");
    printf("\e[48;2;0;0;0m                      \e[E");
    printf("\e[48;2;140;158;255m                    \e[48;2;0;0;0m  \e[E");
    printf("\e[48;2;140;158;255m                    \e[48;2;0;0;0m  \e[E");
    printf("\e[0m");
    printf("\e[H");
    
    printf("\e[28E");
    printf("\e[E");
    printf("\e[48;2;140;158;255m");
    printf("01234567890123456789");
    printf("\e[E");
    printf("01234567890123456789");
    printf("\e[E");
    printf("\e[0m");
    printf("\e[H");

}


int main() {
    windowsconfig();

    desenhar_jogadoraposta();

    programa_pausar();
}