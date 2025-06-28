
/* sprite_demo.c  —  tudo em um arquivo .c + header
 *
 * Compile sem precisar adicionar outros .c:
 *     gcc sprite_demo.c -O2 -std=c11 -o sprite_demo
 * Em Windows (MinGW‑w64) isso já basta.
 * Rode:  sprite_demo sheet.png
 */

#include "ansi_sprite.h"
#include <stdio.h>
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


void desenhar_round1() {
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                      \e[48;2;0;0;0m                                                                              \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                  \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m              \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                    \e[48;2;0;0;0m                                                                        \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                  \e[48;2;0;0;0m                  \e[48;2;0;79;18m                                                                \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                    \e[48;2;0;0;0m                      \e[48;2;0;79;18m                                                              \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                              \e[48;2;0;0;0m                          \e[48;2;0;79;18m                                                            \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                        \e[48;2;0;0;0m                              \e[48;2;0;79;18m                                                          \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                    \e[48;2;0;0;0m                                  \e[48;2;0;79;18m                                                        \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                  \e[48;2;0;0;0m                                      \e[48;2;0;79;18m                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

SpriteSheet* animacao_carregar_spritesheet(char caminho[]){

    SpriteSheet *sheet = sprite_sheet_load(caminho, 15, 15);
    if (!sheet) {
        printf("Falha ao carregar %s\n", caminho);
        return NULL;
    }
    return sheet;
}

int main()
{
    windowsconfig();
    //Carregamento
    //char sheetPath[] = "anim/um.png";
    //SpriteSheet *sheet = sprite_sheet_load(sheetPath, 15, 15);
    //if (!sheet) { fprintf(stderr, "Falha ao carregar %s\n", sheetPath); return 1; }
    SpriteSheet *round1 = animacao_carregar_spritesheet("anim/um.png");
    if (!round1) printf("Não foi possível carregar um sprite");

    //Uso
    desenhar_round1();
    sprite_animate(round1, 2, 80000, "0;79;18", 68, 23);
    sprite_sheet_free(round1);


    system("pause");
    return 0;
}
