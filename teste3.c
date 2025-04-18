#include <stdio.h>
#include <windows.h>

#include <windows.h>
#include <stdio.h>

typedef struct{
    int navegador;
    int confirmador;
} tp_cursor;

void cursor_zerarCursor(tp_cursor *cursor) {
    cursor->navegador=0;
    cursor->confirmador=0;
}

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

void imprimir_float_centralizado(float valor, int largura) {
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



void desenhar_aposta(float totalApostado) {
    printf("\e[62C\e[48;2;244;67;54m                              \e[E");
    printf("\e[62C  \e[48;2;255;255;255m      \e[38;2;255;119;110mTOTAL APOSTADO\e[39m      \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E",totalApostado);
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m                          \e[48;2;244;67;54m  \e[E");
    printf("\e[62C                              \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[3E\e[68C\e[48;2;244;67;54m\e[38;2;252;228;236mR$ ");
    imprimir_float_centralizado(totalApostado,15);

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

void desenhar_corjog(char cor[]) {
    printf("\e[34E");
    printf("\e[%sm████████████████████\e[E",cor);
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("████████████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_seletor() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[38;2;0;0;0m██████████████████████\e[2C██████████████████████\e[2C██████████████████████\e[E");
    printf("\e[40C██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██████████████████\e[38;2;0;0;0m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██████████████████\e[38;2;0;0;0m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██████████████████\e[38;2;0;0;0m██\e[E");
    printf("\e[40C██\e[38;2;255;255;255m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██████████\e[38;2;96;125;139m████\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██\e[38;2;255;255;255m████████████\e[38;2;96;125;139m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██\e[38;2;255;255;255m████████████\e[38;2;96;125;139m██\e[38;2;0;0;0m██\e[E");
    printf("\e[40C██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██████████████████\e[38;2;0;0;0m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██████████████████\e[38;2;0;0;0m██\e[38;2;96;125;139m██\e[38;2;255;255;255m██\e[38;2;96;125;139m██████████████████\e[38;2;0;0;0m██\e[E");
    printf("\e[42C██████████████████████\e[2C██████████████████████\e[2C██████████████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_dinheiro() {
    printf("\e[s");
    printf("\e[E");
    printf("\e[8C\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[4C\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[4C\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C██████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m████\e[38;2;0;0;0m██████████\e[38;2;255;255;255m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██████████████████\e[E");
    printf("\e[4C██\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[4C\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[8C\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

int menu_jogo_navegar() {

    return 1
}

int main () {
    windowsconfig();
    char cor[]={"38;2;38;198;218"};
    char lixo;
    tp_cursor cursor;
    cursor_zerarCursor(&cursor);

    windowsconfig();

    scanf("%c",&lixo);
    system("cls");

    printf("\e[?25l");
    desenhar_fundo();
    desenhar_aposta(0);
    desenhar_cabecalho();
    desenhar_corjog(cor);
    desenhar_dinheiro();

    while(menu_jogo_navegar);

    scanf(" %c",&lixo);
    
}
