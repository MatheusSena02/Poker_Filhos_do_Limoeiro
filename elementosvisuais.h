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

void imprimir__centralizado_float(float valor, int largura) {
    //Imprime um valor dado de forma certralizada (e com 2 casas decimais)
    //Em largura coloca o espaço maximo que pode ocupar
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

void imprimir__centralizado_string_max20(char texto[], int largura) {
    //Imprime uma string dada de forma certralizada (e com 2 casas decimais)
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.20s\n", texto);
        return;
    }

    //Calcula quantos espaços são necessários
    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime a string
    printf("%.20s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}

void imprimir__centralizado_string_max100(char texto[], int largura) {
    //Imprime uma string dada de forma certralizada (e com 2 casas decimais)
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.100s\n", texto);
        return;
    }

    //Calcula quantos espaços são necessários
    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime a string
    printf("%.100s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}

void imprimir_centralizado_float_dinheiro(float valor, int largura) {
    char texto[64];
    
    //Converte o valor em string com 2 casas decimais
    snprintf(texto, sizeof(texto), "R$ %.2f", valor);
    
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
    } while (input != 119 && input != 115 && input != 102); //119 = W / 115 = S / 192 - F

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



void desenhar_pote(float totalApostado) {
    printf("\e[62C\e[48;2;244;67;54m                              \e[E");
    printf("\e[62C  \e[48;2;255;255;255m      \e[38;2;255;119;110m     POTE     \e[39m      \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m                          \e[48;2;244;67;54m  \e[E");
    printf("\e[62C                              \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[3E\e[68C\e[48;2;244;67;54m\e[38;2;252;228;236m");
    imprimir_centralizado_float_dinheiro(totalApostado,18);


    printf("\e[0m");
    printf("\e[H");
}

//Coelho
void desenhar_coelho() {
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
}
    
//Urso
void desenhar_urso() {
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
    }
    
//Sapo
void desenhar_sapo() {
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
}
    
//Esquilo
void desenhar_esquilo() {
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
}
   
//Gato
void desenhar_gato() {
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
void desenhar_rato() {
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

void desenhar_cabecalho(char cor[],char nome[],int ID) {
    printf("\e[31E");
    printf("\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[48;2;128;203;196m\e[s                    \e[38;2;0;0;0m██\e[E");
    printf("\e[u");
    imprimir__centralizado_string_max20(nome,20);
    printf("\e[49m\e[E");
    printf("\e[38;2;0;0;0m██████████████████████\e[E");
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

    desenhar_corjog(cor);

    switch (ID) {
        case 0:
        desenhar_gato();
        break;

        case 1:
        desenhar_coelho();
        break;

        case 2:
        desenhar_sapo();
        break;

        case 3:
        desenhar_esquilo();
        break;

        case 4:
        desenhar_rato();
        break;

        case 5:
        desenhar_urso();
        break;
    }
}

void desenhar_dinheiro(float dinheiro) {
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

    printf("\e[2C\e[11B");
    printf("\e[48;2;0;77;64m");
    printf("\e[1m");
    printf("                  ");
    printf("\e[18D");
    imprimir_centralizado_float_dinheiro(dinheiro,18);
    printf("\e[H");
    printf("\e[0m");
}

void desenhar_bordaseletor() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[38;2;35;48;54m██████████████████████\e[2C██████████████████████\e[2C██████████████████████\e[E");
    printf("\e[40C██\e[22C██\e[22C██\e[22C██\e[E");
    printf("\e[40C██\e[22C██\e[22C██\e[22C██\e[E");
    printf("\e[40C██\e[22C██\e[22C██\e[22C██\e[E");
    printf("\e[42C██████████████████████\e[2C██████████████████████\e[2C██████████████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_seletor(tp_cursor *cursor) {
    char corfundo[3][18]={"48;2;96;125;139","48;2;96;125;139","48;2;96;125;139"};
    strcpy(corfundo[cursor->navegador],"48;2;33;150;243");
    char corletra[3][18]={"38;2;74;74;74","38;2;74;74;74","38;2;74;74;74"};
    strcpy(corletra[cursor->navegador],"38;2;255;209;255");

    printf("\e[s");
    printf("\e[39E");
    printf("\e[42C\e[48;2;255;255;255m    \e[%sm            \e[48;2;255;255;255m      \e[2C    \e[%sm              \e[48;2;255;255;255m    \e[2C      \e[%sm            \e[48;2;255;255;255m    \e[E",corfundo[0],corfundo[1],corfundo[2]);
    printf("\e[42C  \e[%sm     \e[%smAUMENTAR     \e[48;2;255;255;255m  \e[2C  \e[%sm     \e[%smDESISTIR     \e[48;2;255;255;255m  \e[2C  \e[%sm      \e[%smPAGAR       \e[48;2;255;255;255m  \e[E",corfundo[0],corletra[0],corfundo[1],corletra[1],corfundo[2],corletra[2]);
    printf("\e[42C\e[%sm                      \e[2C\e[%sm                      \e[2C\e[%sm                      \e[E",corfundo[0],corfundo[1],corfundo[2]);
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_aumentar(tp_cursor *cursor) {
    char corletra[3][18]={"38;2;74;74;74","38;2;74;74;74"};
    strcpy(corletra[cursor->navegador],"38;2;255;209;255");

    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;35;48;54m                                                                      \e[E");
    printf("\e[40C  \e[48;2;255;255;255m      \e[48;2;33;150;243m                                                                \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;255;255;255m  \e[48;2;33;150;243m                                                                  \e[48;2;255;255;255m  \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;33;150;243m                                                                \e[48;2;255;255;255m      \e[48;2;35;48;54m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[H");

    printf("\e[39E\e[42C");
    printf("\e[48;2;33;150;243m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("COMO QUER FAZER O AUMENTO?",70);
    printf("\e[E\e[42C");
    printf("\e[%sm",corletra[0]);
    imprimir__centralizado_string_max100("PERCENTUAL",35);
    printf("\e[%sm",corletra[1]);
    imprimir__centralizado_string_max100("VALOR ABSOLUTO",35);
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_limpar_seletorEaumentar() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;0;77;64m                                                                      \e[E");
    printf("\e[40C                                                                          \e[E");
    printf("\e[40C                                                                          \e[E");
    printf("\e[40C                                                                          \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}







#endif