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

void desenhar_aumentar_aposta_fundo() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;35;48;54m                                                                      \e[E");
    printf("\e[40C  \e[48;2;255;255;255m      \e[48;2;33;150;243m                                                                \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;255;255;255m  \e[48;2;33;150;243m                                                                  \e[48;2;255;255;255m  \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;33;150;243m                                                                \e[48;2;255;255;255m      \e[48;2;35;48;54m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[H");
}


int main() {
    windowsconfig();

    desenhar_aumentar_aposta_fundo();

    programa_pausar();
}