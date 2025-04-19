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

    //Teste da tabela para digitar o valor da aposta
void desenhar_TabelaAposta() {
    printf("\e[s");
    printf("\e[25E");
    printf("\e[112C\e[38;2;244;67;54m██████████████████████████████████\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██████████████████████████████\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██\e[38;2;244;67;54m████\e[38;2;255;255;255m██████████████████\e[38;2;244;67;54m████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██\e[38;2;244;67;54m████\e[38;2;255;255;255m██████████████████\e[38;2;244;67;54m████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██\e[38;2;244;67;54m████\e[38;2;255;255;255m██████████████████\e[38;2;244;67;54m████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██\e[38;2;244;67;54m██████████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██\e[38;2;255;255;255m██████████████████████████████\e[38;2;244;67;54m██\e[E");
    printf("\e[112C██████████████████████████████████\e[E");
    printf("\e[0m");
    printf("\e[H");

    //Coelho
void desenhar_Coelho() {
    printf("\e[s");
    printf("\e[35E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;235;238m██████\e[38;2;0;0;0m████\e[38;2;255;235;238m██\e[E");
    printf("\e[2C\e[38;2;252;228;236m████\e[38;2;0;0;0m██\e[38;2;255;235;238m██\e[38;2;0;0;0m██\e[38;2;252;228;236m████\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;239;154;154m██\e[38;2;252;228;236m██\e[38;2;0;0;0m██\e[38;2;255;235;238m██\e[38;2;0;0;0m██\e[38;2;239;154;154m██\e[38;2;252;228;236m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;239;154;154m██\e[38;2;252;228;236m██\e[38;2;0;0;0m██\e[38;2;255;235;238m██\e[38;2;0;0;0m██\e[38;2;239;154;154m██\e[38;2;252;228;236m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;252;228;236m██████\e[38;2;0;0;0m██\e[38;2;252;228;236m████████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m██\e[38;2;252;228;236m██████\e[38;2;0;0;0m██\e[38;2;252;228;236m████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m██\e[38;2;252;228;236m██████\e[38;2;0;0;0m██\e[38;2;248;187;208m██\e[38;2;252;228;236m██\e[E");
    printf("\e[2C██████\e[38;2;229;115;115m██\e[38;2;252;228;236m████\e[38;2;248;187;208m████\e[E");
    printf("\e[0m");
    printf("\e[H");

    //Urso
void desenhar_Urso() {
    printf("\e[s");
    printf("\e[35E");
    printf("\e[2C\e[38;2;109;76;65m██████\e[38;2;255;235;238m████\e[38;2;109;76;65m██████\e[E");
    printf("\e[2C██\e[38;2;239;154;154m██\e[38;2;109;76;65m██\e[38;2;255;235;238m████\e[38;2;109;76;65m██\e[38;2;239;154;154m██\e[38;2;109;76;65m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;255;235;238m██\e[38;2;109;76;65m██\e[38;2;33;33;33m██\e[38;2;109;76;65m████\e[38;2;33;33;33m██\e[38;2;109;76;65m██\e[38;2;255;235;238m██\e[E");
    printf("\e[2C\e[38;2;109;76;65m████\e[38;2;0;0;0m██\e[38;2;109;76;65m████\e[38;2;0;0;0m██\e[38;2;109;76;65m████\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;121;85;72m██\e[38;2;0;0;0m████\e[38;2;121;85;72m██\e[38;2;109;76;65m████\e[E");
    printf("\e[2C████\e[38;2;121;85;72m████████\e[38;2;109;76;65m████\e[E");
    printf("\e[0m");
    printf("\e[H");

    //Sapo
void desenhar_Sapo() {
    printf("\e[s");
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;235;238m██\e[38;2;56;142;60m██████\e[38;2;255;235;238m██\e[38;2;56;142;60m████\e[38;2;46;125;50m██\e[E");
    printf("\e[2C\e[38;2;255;235;238m██\e[38;2;56;142;60m██\e[38;2;0;0;0m██\e[38;2;56;142;60m██\e[38;2;255;235;238m██\e[38;2;56;142;60m██\e[38;2;0;0;0m██\e[38;2;56;142;60m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;27;94;32m████████████\e[E");
    printf("\e[2C\e[38;2;56;142;60m████████████████\e[E");
    printf("\e[2C████████████\e[38;2;46;125;50m████\e[E");
    printf("\e[2C\e[38;2;67;160;71m██\e[38;2;56;142;60m████████████\e[38;2;46;125;50m██\e[E");
    printf("\e[2C\e[38;2;67;160;71m████\e[38;2;255;235;238m██\e[38;2;56;142;60m██████\e[38;2;255;235;238m██\e[38;2;46;125;50m██\e[E");
    printf("\e[0m");
    printf("\e[H");

    //Esquilo
void desenhar_Esquilo() {
    printf("\e[s");
    printf("\e[35E");
    printf("\e[2C\e[38;2;78;52;46m████\e[38;2;255;235;238m████████\e[38;2;78;52;46m████\e[E");
    printf("\e[2C\e[38;2;255;205;210m██\e[38;2;78;52;46m██\e[38;2;109;76;65m████████\e[38;2;78;52;46m██\e[38;2;255;205;210m██\e[E");
    printf("\e[2C\e[38;2;255;209;128m████\e[38;2;109;76;65m████████\e[38;2;255;209;128m████\e[E");
    printf("\e[2C\e[38;2;33;33;33m██\e[38;2;97;97;97m██\e[38;2;255;204;128m██\e[38;2;109;76;65m████\e[38;2;255;209;128m██\e[38;2;33;33;33m██\e[38;2;97;97;97m██\e[E");
    printf("\e[2C██\e[38;2;33;33;33m██\e[38;2;255;209;128m██\e[38;2;141;110;99m████\e[38;2;255;209;128m██\e[38;2;97;97;97m██\e[38;2;33;33;33m██\e[E");
    printf("\e[2C\e[38;2;255;204;128m██\e[38;2;255;209;128m██\e[38;2;109;76;65m██\e[38;2;0;0;0m████\e[38;2;109;76;65m██\e[38;2;255;204;128m██\e[38;2;255;209;128m██\e[E");
    printf("\e[2C\e[38;2;109;76;65m████\e[38;2;141;110;99m██\e[38;2;255;255;255m████\e[38;2;141;110;99m██\e[38;2;109;76;65m████\e[E");
    printf("\e[2C██\e[38;2;141;110;99m████████████\e[38;2;109;76;65m██\e[E");
    printf("\e[0m");
    printf("\e[H");

    //Gato
void desenhar_Gato() {
    printf("\e[s");
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;235;238m██\e[38;2;255;183;77m██\e[38;2;255;235;238m████████\e[38;2;255;183;77m██\e[38;2;255;235;238m██\e[E");
    printf("\e[2C\e[38;2;255;183;77m██\e[38;2;255;204;128m██\e[38;2;255;183;77m██\e[38;2;255;235;238m████\e[38;2;255;183;77m██\e[38;2;255;204;128m██\e[38;2;255;183;77m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;183;77m████\e[38;2;0;0;0m██\e[38;2;255;183;77m████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;183;77m████\e[38;2;0;0;0m██\e[38;2;255;183;77m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;204;128m██\e[38;2;0;0;0m██\e[38;2;255;204;128m████\e[38;2;0;0;0m██\e[38;2;255;204;128m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;204;128m████████\e[38;2;239;83;80m██\e[38;2;255;204;128m██████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;204;128m████████████\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");

}

    //Rato
void desenhar_Rato() {
    printf("\e[s");
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;158;158;158m██\e[38;2;255;255;255m████████\e[38;2;158;158;158m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;158;158;158m██\e[38;2;255;205;210m██\e[38;2;158;158;158m██\e[38;2;255;255;255m████\e[38;2;158;158;158m██\e[38;2;255;205;210m██\e[38;2;158;158;158m██\e[E");
    printf("\e[2C██\e[38;2;255;205;210m██\e[38;2;158;158;158m████████\e[38;2;255;205;210m██\e[38;2;158;158;158m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;158;158;158m████\e[38;2;0;0;0m██\e[38;2;158;158;158m████\e[E");
    printf("\e[2C██████\e[38;2;239;154;154m████\e[38;2;158;158;158m██████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;158;158;158m████████████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;158;158;158m████████\e[38;2;255;255;255m████\e[E");
    printf("\e[0m");
}

                }
            }
            }
        }

    }

}

int main () {

    windowsconfig();
    char cor[]={"38;2;38;198;218"};
    char lixo;
    scanf("%c",&lixo);
    system("cls");


    desenhar_fundo();
    desenhar_aposta(0);
    desenhar_cabecalho();
    desenhar_corjog(cor);
    desenhar_seletor();
    desenhar_dinheiro();
    desenhar_TabelaAposta();
    desenhar_Coelho();
    desenhar_Urso();
    desenhar_Sapo();
    desenhar_Esquilo();
    desenhar_Gato();
    desenhar_Rato();

    //Valor de dinheiro atual
    printf("\e[13C\e[5B");
    printf("(Valor:)");

    //Nome do jogador
    printf("\e[2C\e[32B");
    printf("[%s]\n",i+1,jogador[i].nome);

    //Tabela de Aposta
    printf("\e[61C\e[28B");
    printf("Insira o valor que");
    printf("\e[61C\e[29B");
    printf("deseja apostar:"); //Aqui foi para descer a linha :P

    printf("\e[61C\e[31B");
    printf("(Valor:)")

    scanf(" %c",&lixo);
    
}
