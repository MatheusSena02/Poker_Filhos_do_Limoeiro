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
    //OBS: o float deve ocupar no máximo um espaço de 64 caracteres (2 casas decimais + vírgula inclusas)
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

void imprimir_centralizado_float_dinheiro(float valor, int largura) {
    //Imprime um valor dado de forma certralizada (e com 2 casas decimais) e com R$
    //OBS: o float+"R$ " deve ocupar no máximo um espaço de 64 caracteres (2 casas decimais + vírgula inclusas)
    //Em largura coloca o espaço maximo que pode ocupar
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
    //Imprime uma string (de ate 20 caracteres) dada de forma certralizada
    //Caso a string seja maior q 20 caracteres, o texto vai ser cortado
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.20s\n", texto);
        return;
    }

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
    //Imprime uma string (de ate 100 caracteres) dada de forma certralizada
    //Caso a string seja maior q 100 caracteres, o texto vai ser cortado
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.100s\n", texto);
        return;
    }

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

void imprimir__centralizado_string_max200(char texto[], int largura) {
    //Imprime uma string (de ate 200 caracteres) dada de forma certralizada
    //Caso a string seja maior q 200 caracteres, o texto vai ser cortado
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.200s\n", texto);
        return;
    }

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

void desenhar_fundoinicial() {
    printf("\e[48;2;17;52;66m                                                                                                                                                            \e[E");
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
    fflush(stdout);
}

void desenhar_fichainicial() {
    printf("\e[7E");
    printf("\e[36C\e[38;2;0;0;0m██████████████\e[E");
    printf("\e[30C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[26C██████████████████████████████████\e[E");
    printf("\e[24C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[22C██\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██\e[E");
    printf("\e[20C██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[E");
    printf("\e[18C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████████████████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[16C██████████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[16C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[14C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██████████████████████████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[14C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[14C██████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████████████\e[38;2;0;0;0m██\e[38;2;255;255;255m██████████████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[14C██████████████\e[38;2;255;255;255m████████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████████\e[38;2;0;0;0m██████████████\e[E");
    printf("\e[14C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[14C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██████████████████████████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[16C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[16C██████████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[18C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████████████████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[20C██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[E");
    printf("\e[22C██\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██\e[E");
    printf("\e[24C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[26C██████████████████████████████████\e[E");
    printf("\e[30C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[36C██████████████\e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[48;2;17;52;66m");
    printf("\e[12E\e[87C[WASD -> Selecionar]\e[E");
    printf("\e[87C[F -> Confirmar] [X -> Voltar]");
    printf("\e[0m");
    printf("\e[H");

    fflush(stdout);
}

void desenhar_jogar(int cor) {
    char cora[]={"38;2;255;255;255"};
    if (cor==1) strcpy(cora,"38;2;213;0;0");
    printf("\e[16E");
    printf("\e[86C\e[%sm██████████\e[2C██████████\e[2C██████████\e[2C██████████\e[2C██████████\e[E",cora);
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[8C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C██████████\e[2C████████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[86C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[86C██████████\e[2C██████████\e[2C██████████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[0m");
    printf("\e[H");
    fflush(stdout);
}

void desenhar_configurar(int cor) {
    char cora[]={"38;2;158;158;158"};
    if (cor==2) strcpy(cora,"38;2;213;0;0");
    printf("\e[27E");
    printf("\e[112C\e[%sm████\e[E",cora);
    printf("\e[106C████\e[2C████\e[2C████\e[E");
    printf("\e[106C████████████████\e[E");
    printf("\e[108C████████████\e[E");
    printf("\e[104C████████\e[4C████████\e[E");
    printf("\e[104C████████\e[4C████████\e[E");
    printf("\e[108C████████████\e[E");
    printf("\e[106C████████████████\e[E");
    printf("\e[106C████\e[2C████\e[2C████\e[E");
    printf("\e[112C████\e[E");
    printf("\e[0m");
    printf("\e[H");
    fflush(stdout);
}

void menuinicial_imprimirSimbolo (int navegador) {
    int cor;
    
    switch(navegador) {
        case 0:
        cor=0;
        break;

        case 1:
        cor=1;
        break;

        case 2:
        cor=2;
        break;
    }
    desenhar_jogar(cor);
    desenhar_configurar(cor);

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

void desenhar_coelho() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;255;255m████████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;188;210m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C██████\e[38;2;255;116;116m██\e[38;2;255;255;255m████\e[38;2;255;188;210m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelhodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;255;255m████\e[E");
    printf("\e[2C\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;255;116;116m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;188;210m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelhotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;255;255m████████\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C██\e[38;2;0;151;246m██\e[38;2;255;255;255m██\e[38;2;255;116;116m██\e[38;2;255;255;255m██\e[38;2;0;151;246m██\e[38;2;255;188;210m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquilo() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;85;49;42m████\e[38;2;255;255;255m████████\e[38;2;85;49;42m████\e[E");
    printf("\e[2C\e[38;2;255;206;211m██\e[38;2;85;49;42m██\e[38;2;120;75;62m████████\e[38;2;85;49;42m██\e[38;2;255;206;211m██\e[E");
    printf("\e[2C\e[38;2;255;210;124m████\e[38;2;120;75;62m████████\e[38;2;255;210;124m████\e[E");
    printf("\e[2C\e[38;2;27;27;27m██\e[38;2;97;97;97m██\e[38;2;255;205;124m██\e[38;2;120;75;62m████\e[38;2;255;210;124m██\e[38;2;27;27;27m██\e[38;2;97;97;97m██\e[E");
    printf("\e[2C██\e[38;2;27;27;27m██\e[38;2;255;210;124m██\e[38;2;153;110;98m████\e[38;2;255;210;124m██\e[38;2;97;97;97m██\e[38;2;27;27;27m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m██\e[38;2;255;210;124m██\e[38;2;120;75;62m██\e[38;2;0;0;0m████\e[38;2;120;75;62m██\e[38;2;255;205;124m██\e[38;2;255;210;124m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m████\e[38;2;153;110;98m██\e[38;2;255;255;255m████\e[38;2;153;110;98m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C██\e[38;2;153;110;98m████████████\e[38;2;120;75;62m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquilodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;85;49;42m████\e[38;2;255;255;255m████████\e[38;2;85;49;42m████\e[E");
    printf("\e[2C\e[38;2;255;206;211m██\e[38;2;85;49;42m██\e[38;2;120;75;62m████████\e[38;2;85;49;42m██\e[38;2;255;206;211m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m██\e[38;2;255;194;0m██\e[38;2;120;75;62m████████\e[38;2;255;194;0m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;120;75;62m████\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[E");
    printf("\e[2C██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;153;110;98m████\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m██\e[38;2;255;194;0m██\e[38;2;120;75;62m██\e[38;2;0;0;0m████\e[38;2;120;75;62m██\e[38;2;255;194;0m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C████\e[38;2;153;110;98m██\e[38;2;255;255;255m████\e[38;2;153;110;98m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C██\e[38;2;153;110;98m████\e[38;2;255;65;50m████\e[38;2;153;110;98m████\e[38;2;120;75;62m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquilotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;85;49;42m████\e[38;2;255;255;255m████████\e[38;2;85;49;42m████\e[E");
    printf("\e[2C\e[38;2;255;206;211m██\e[38;2;85;49;42m██\e[38;2;120;75;62m████████\e[38;2;85;49;42m██\e[38;2;255;206;211m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m████████████████\e[E");
    printf("\e[2C\e[38;2;255;210;124m████\e[38;2;255;205;124m██\e[38;2;120;75;62m████\e[38;2;255;210;124m██████\e[E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;210;124m██\e[38;2;153;110;98m████\e[38;2;255;210;124m██\e[38;2;0;0;0m████\e[E");
    printf("\e[2C\e[38;2;255;205;124m██\e[38;2;0;151;246m██\e[38;2;120;75;62m██\e[38;2;0;0;0m████\e[38;2;120;75;62m██\e[38;2;0;151;246m██\e[38;2;255;210;124m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m██\e[38;2;0;151;246m██\e[38;2;153;110;98m██\e[38;2;255;255;255m████\e[38;2;153;110;98m██\e[38;2;0;151;246m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C██\e[38;2;0;151;246m██\e[38;2;153;110;98m████████\e[38;2;0;151;246m██\e[38;2;120;75;62m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gato() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████████\e[38;2;255;184;66m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[38;2;255;205;124m████\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m████████\e[38;2;255;82;79m██\e[38;2;255;205;124m██████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m████████████\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gatodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████████\e[38;2;255;184;66m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;255;236;18m██\e[38;2;255;205;124m████\e[38;2;255;236;18m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m████████\e[38;2;255;82;79m██\e[38;2;255;205;124m██████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m████\e[38;2;255;65;50m████\e[38;2;255;205;124m████\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gatotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████████\e[38;2;255;184;66m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[38;2;255;205;124m████\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m████\e[38;2;0;151;246m██\e[38;2;255;205;124m██\e[38;2;255;82;79m██\e[38;2;0;151;246m██\e[38;2;255;205;124m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;151;246m██\e[38;2;255;205;124m████\e[38;2;0;151;246m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_rato() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████████\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C██\e[38;2;255;200;206m██\e[38;2;151;151;151m████████\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;151;151;151m████\e[38;2;0;0;0m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C██████\e[38;2;255;146;146m████\e[38;2;151;151;151m██████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m████████████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;151;151;151m████████\e[38;2;255;255;255m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ratodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████████\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C██\e[38;2;255;200;206m██\e[38;2;151;151;151m████████\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C██████\e[38;2;255;146;146m████\e[38;2;151;151;151m██████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m████\e[38;2;255;58;43m████\e[38;2;151;151;151m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;151;151;151m████████\e[38;2;255;255;255m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ratotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████████\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C██\e[38;2;255;200;206m██\e[38;2;151;151;151m████████\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m████\e[38;2;151;151;151m████\e[38;2;0;0;0m████\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;255;146;146m████\e[38;2;0;140;244m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;0;140;244m██\e[38;2;151;151;151m████\e[38;2;0;140;244m██\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;151;151;151m████\e[38;2;0;140;244m██\e[38;2;255;255;255m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapo() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;135;48m████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m██\e[38;2;0;135;48m██\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;86;23m████████████\e[E");
    printf("\e[2C\e[38;2;0;135;48m████████████████\e[E");
    printf("\e[2C████████████\e[38;2;0;117;39m████\e[E");
    printf("\e[2C\e[38;2;0;154;59m██\e[38;2;0;135;48m████████████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;117;39m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;135;48m████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;255;235;33m██\e[38;2;0;135;48m██\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;255;235;33m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;86;23m████████████\e[E");
    printf("\e[2C\e[38;2;0;135;48m████\e[38;2;255;58;43m████████\e[38;2;0;135;48m████\e[E");
    printf("\e[2C████████████\e[38;2;0;117;39m████\e[E");
    printf("\e[2C\e[38;2;0;154;59m██\e[38;2;0;135;48m████████████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;117;39m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;135;48m████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m████\e[E");
    printf("\e[2C\e[38;2;0;135;48m████\e[38;2;0;140;244m██\e[38;2;0;135;48m██████\e[38;2;0;140;244m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;0;86;23m██████\e[38;2;0;140;244m██\e[38;2;0;86;23m██\e[E");
    printf("\e[2C\e[38;2;0;135;48m████\e[38;2;0;140;244m██\e[38;2;0;135;48m██████\e[38;2;0;140;244m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;0;135;48m██████\e[38;2;0;140;244m██\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m██\e[38;2;0;135;48m████████████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;117;39m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_urso() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;120;75;62m██████\e[38;2;255;255;255m████\e[38;2;120;75;62m██████\e[E");
    printf("\e[2C██\e[38;2;255;155;155m██\e[38;2;120;75;62m██\e[38;2;255;255;255m████\e[38;2;120;75;62m██\e[38;2;255;155;155m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;120;75;62m██\e[38;2;27;27;27m██\e[38;2;120;75;62m████\e[38;2;27;27;27m██\e[38;2;120;75;62m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m████\e[38;2;0;0;0m██\e[38;2;120;75;62m████\e[38;2;0;0;0m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;133;84;70m██\e[38;2;0;0;0m████\e[38;2;133;84;70m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C████\e[38;2;133;84;70m████████\e[38;2;120;75;62m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ursodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;107;68;56m██████\e[38;2;255;255;255m████\e[38;2;107;68;56m██████\e[E");
    printf("\e[2C██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[38;2;255;255;255m████\e[38;2;107;68;56m██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;107;68;56m██\e[38;2;255;189;0m██\e[38;2;107;68;56m████\e[38;2;255;189;0m██\e[38;2;107;68;56m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;107;68;56m████\e[38;2;255;189;0m██\e[38;2;107;68;56m████\e[38;2;255;189;0m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;120;76;63m██\e[38;2;0;0;0m████\e[38;2;120;76;63m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████\e[38;2;120;76;63m██\e[38;2;255;58;43m████\e[38;2;120;76;63m██\e[38;2;107;68;56m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ursotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;107;68;56m██████\e[38;2;255;255;255m████\e[38;2;107;68;56m██████\e[E");
    printf("\e[2C██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[38;2;255;255;255m████\e[38;2;107;68;56m██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;107;68;56m██\e[38;2;0;0;0m██\e[38;2;107;68;56m████\e[38;2;0;0;0m██\e[38;2;107;68;56m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;107;68;56m██\e[38;2;0;0;0m████\e[38;2;107;68;56m████\e[38;2;0;0;0m████\e[38;2;107;68;56m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;0;0;0m████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;120;76;63m████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[E");
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

void desenhar_cabecalho_jogador_neutro (int ID) {
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

void desenhar_cabecalho_jogador_triste (int ID) {
    switch (ID) {
        case 0:
        desenhar_gatotriste();
        break;

        case 1:
        desenhar_coelhotriste();
        break;

        case 2:
        desenhar_sapotriste();
        break;

        case 3:
        desenhar_esquilotriste();
        break;

        case 4:
        desenhar_ratotriste();
        break;

        case 5:
        desenhar_ursotriste();
        break;
    }
}

void desenhar_cabecalho_jogador_dinheiro (int ID) {
    switch (ID) {
        case 0:
        desenhar_gatodinheiro();
        break;

        case 1:
        desenhar_coelhodinheiro();
        break;

        case 2:
        desenhar_sapodinheiro();
        break;

        case 3:
        desenhar_esquilodinheiro();
        break;

        case 4:
        desenhar_ratodinheiro();
        break;

        case 5:
        desenhar_ursodinheiro();
        break;
    }
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
    desenhar_cabecalho_jogador_neutro(ID);
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

void desenhar_dinheirocifra(float dinheiro) {
    printf("\e[E");
    printf("\e[8C\e[38;2;164;119;32m██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
    printf("\e[4C██\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;166;98;12m██\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
    printf("\e[4C\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;223;152;18m██████\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[E");
    printf("\e[2C\e[38;2;164;119;32m██\e[38;2;59;35;6m████\e[38;2;223;152;18m██\e[38;2;166;98;12m██\e[38;2;59;35;6m██████\e[38;2;164;119;32m██\e[E");
    printf("\e[2C\e[38;2;102;58;9m██\e[38;2;59;35;6m████\e[38;2;223;152;18m██████\e[38;2;59;35;6m████\e[38;2;102;58;9m██\e[E");
    printf("\e[2C\e[38;2;164;119;32m██\e[38;2;59;35;6m██████\e[38;2;166;98;12m██\e[38;2;223;152;18m██\e[38;2;59;35;6m████\e[38;2;164;119;32m██\e[E");
    printf("\e[4C\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;223;152;18m██████\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[E");
    printf("\e[4C\e[38;2;164;119;32m██\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;166;98;12m██\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
    printf("\e[8C██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
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

void desenhar_marcadormaojogador() {
    printf("\e[24E");
    printf("\e[56C\e[38;2;10;209;173m████\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m████\e[E");
    printf("\e[56C██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C████\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_porcoaposta() {
    printf("\e[33E");
    printf("\e[138C\e[48;2;255;193;7m  \e[2C  \e[2C\e[48;2;255;235;59m  \e[E");
    printf("\e[138C  \e[48;2;255;193;7m      \e[48;2;255;235;59m  \e[E");
    printf("\e[138C\e[48;2;255;152;0m    \e[48;2;244;67;54m  \e[48;2;255;152;0m    \e[E");
    printf("\e[138C\e[48;2;255;205;210m          \e[E");
    printf("\e[138C\e[48;2;0;0;0m  \e[48;2;255;205;210m      \e[48;2;0;0;0m  \e[E");
    printf("\e[138C\e[48;2;255;205;210m  \e[48;2;229;115;115m  \e[48;2;239;154;154m  \e[48;2;229;115;115m  \e[48;2;255;205;210m  \e[E");
    printf("\e[132C  \e[48;2;239;154;154m  \e[2C\e[48;2;255;205;210m  \e[48;2;239;154;154m      \e[48;2;255;205;210m  \e[2C\e[48;2;239;154;154m  \e[48;2;255;205;210m  \e[E");
    printf("\e[130C\e[48;2;255;152;0m                          \e[E");
    printf("\e[130C  \e[48;2;255;193;7m                      \e[48;2;255;152;0m  \e[E");
    printf("\e[130C  \e[48;2;255;193;7m                      \e[48;2;255;152;0m  \e[E");
    printf("\e[130C                          \e[E");

    

    printf("\e[0m");
    printf("\e[H");
}

void desenhar_inserirjogadormesa() {
    printf("\e[16C\e[38;2;102;65;20m██████████████████████████████████████████████████\e[E");
    printf("\e[12C████\e[38;2;74;47;16m██████████████████████████████████████████████████\e[38;2;102;65;20m████\e[E");
    printf("\e[8C████\e[38;2;74;47;16m████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;74;47;16m████\e[38;2;102;65;20m████\e[E");
    printf("\e[6C████\e[38;2;74;47;16m██\e[38;2;10;87;73m████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;10;87;73m████\e[38;2;74;47;16m██\e[38;2;102;65;20m████\e[E");
    printf("\e[6C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C████\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m████████████████████████████████████████████████████████████\e[38;2;74;47;16m██\e[38;2;102;65;20m████\e[E");
    printf("\e[4C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████\e[38;2;244;67;54m██\e[38;2;255;255;255m██\e[38;2;0;77;64m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;77;64m██████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████\e[38;2;255;255;255m████\e[38;2;0;77;64m██\e[38;2;255;255;255m████\e[38;2;0;77;64m██████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[38;2;0;77;64m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;0;77;64m██████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C████\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████████████████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m████\e[38;2;102;65;20m██\e[E");
    printf("\e[6C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[6C████\e[38;2;74;47;16m██\e[38;2;10;87;73m████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;10;87;73m████\e[38;2;74;47;16m██\e[38;2;102;65;20m████\e[E");
    printf("\e[8C████\e[38;2;74;47;16m████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;74;47;16m████\e[38;2;102;65;20m████\e[E");
    printf("\e[12C████\e[38;2;74;47;16m██████████████████████████████████████████████████\e[38;2;102;65;20m████\e[E");
    printf("\e[16C██████████████████████████████████████████████████\e[E");
    printf("\e[0m");
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

void desenhar_aumentar_aposta_percentual() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;35;48;54m                                                                      \e[E");
    printf("\e[40C  \e[48;2;255;255;255m      \e[48;2;33;150;243m                                                                \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;255;255;255m  \e[48;2;33;150;243m                                                                  \e[48;2;255;255;255m  \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;33;150;243m                                                                \e[48;2;255;255;255m      \e[48;2;35;48;54m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[H");
}

void desenhar_aumentar_aposta_percentual_barrinha() {
    printf("\e[40E");
    printf("\e[58C\e[48;2;41;121;255m        \e[6C          \e[6C        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_aumentar_aposta_absoluto() {
    
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
    imprimir__centralizado_string_max100("DIGITE O VALOR A SER APOSTADO",70);
    printf("\e[E\e[46C Aperte F para digitar");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadoraposta(float aposta) {
    printf("\e[28E");
    printf("\e[48;2;0;0;0m                      \e[E");
    printf("\e[48;2;140;158;255m                    \e[48;2;0;0;0m  \e[E");
    printf("\e[48;2;140;158;255m                    \e[48;2;0;0;0m  \e[E");
    printf("\e[0m");
    printf("\e[H");
    
    printf("\e[28E");
    printf("\e[E");
    printf("\e[48;2;140;158;255m\e[38;2;0;0;0m");
    imprimir__centralizado_string_max20("Valor Já Apostado",20);
    printf("\e[E");
    imprimir_centralizado_float_dinheiro(aposta,20);
    printf("\e[E");
    printf("\e[0m");
    printf("\e[H");

}

void desenhar_mesaapoiodamesa() {
    printf("\e[9E");
    printf("\e[44C\e[48;2;163;114;49m    \e[48;2;54;45;40m                                                          \e[48;2;163;114;49m    \e[E");
    printf("\e[44C  \e[48;2;54;45;40m                                                              \e[48;2;163;114;49m  \e[E");
    printf("\e[44C\e[48;2;54;45;40m         \e[48;2;163;114;49m                                                 \e[48;2;54;45;40m        \e[E");
    printf("\e[44C       \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                 \e[48;2;163;114;49m  \e[48;2;54;45;40m      \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C       \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                 \e[48;2;163;114;49m  \e[48;2;54;45;40m      \e[E");
    printf("\e[44C         \e[48;2;163;114;49m                                                 \e[48;2;54;45;40m        \e[E");
    printf("\e[44C\e[48;2;163;114;49m  \e[48;2;54;45;40m                                                              \e[48;2;163;114;49m  \e[E");
    printf("\e[44C    \e[48;2;54;45;40m                                                          \e[48;2;163;114;49m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_areacombinacoes() {
    printf("\e[134C\e[48;2;92;107;192m                      \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_seletorficoupobre() {
    printf("\e[38E");
    printf("\e[42C\e[48;2;34;44;49m                                                                      \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[39E\e[42C");
    printf("\e[48;2;245;53;51m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Você não tem mais dinheiro para jogar :(",70);
    printf("\e[E\e[42C");
    imprimir__centralizado_string_max100("Aperte F para desistir",70);
    printf("\e[0m");
    printf("\e[H");

}

void desenhar_tutorial(char RGBfundo[]){
    printf("\e[43E\e[48;2;%sm",RGBfundo);
    imprimir__centralizado_string_max200("Navegar: [WASD] | Confirmar: [F] | Voltar: [X]",155);
    printf("\e[H\e[0m");
}

void desenhar_popupavisolimpar() {
    printf("\e[18E");
    printf("\e[48;2;0;77;64m                                      \e[E");
    printf("                                    \e[E");
    printf("                                  \e[E");
    printf("                                \e[E");
    printf("                                \e[E");
    printf("                              \e[E");
    printf("                              \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_popupaviso(char texto1[],char texto2[],char texto3[]) {
    printf("\e[18E");
    printf("\e[48;2;49;0;0m                                      \e[E");
    printf("  \e[48;2;89;0;0m                            \e[48;2;71;0;0m  \e[48;2;49;0;0m    \e[E");
    printf("  \e[48;2;89;0;0m                          \e[48;2;71;0;0m  \e[48;2;49;0;0m    \e[E");
    printf("  \e[48;2;89;0;0m                          \e[48;2;71;0;0m  \e[48;2;49;0;0m  \e[E");
    printf("  \e[48;2;89;0;0m                        \e[48;2;71;0;0m  \e[48;2;49;0;0m    \e[E");
    printf("  \e[48;2;89;0;0m                        \e[48;2;71;0;0m  \e[48;2;49;0;0m  \e[E");
    printf("                              \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[48;2;89;0;0m\e[38;2;255;255;255m\e[20E\e[4C");
    imprimir__centralizado_string_max100(texto1,21);
    printf("\e[E\e[4C");
    imprimir__centralizado_string_max100(texto2,21);
    printf("\e[E\e[4C");
    imprimir__centralizado_string_max100(texto3,19);
    printf("\e[1E\e[4C");
    imprimir__centralizado_string_max100("[Pressione F]",19);
    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);
    printf("\e[H\e[0m");
    desenhar_popupavisolimpar();

}

void desenhar_guia() {
    printf("\e[27E");
    printf("\e[108C\e[38;2;72;125;178m████████████\e[E");
    printf("\e[106C██\e[38;2;180;202;212m██\e[38;2;200;224;236m██\e[38;2;72;125;178m██\e[38;2;180;202;212m██\e[38;2;200;224;236m██\e[38;2;72;125;178m████\e[E");
    printf("\e[104C████\e[38;2;200;224;236m████\e[38;2;72;125;178m██\e[38;2;200;224;236m████\e[38;2;72;125;178m██████\e[E");
    printf("\e[104C████\e[38;2;200;224;236m██\e[38;2;180;202;212m██\e[38;2;147;172;183m██\e[38;2;200;224;236m██\e[38;2;180;202;212m██\e[38;2;147;172;183m██\e[38;2;72;125;178m████\e[E");
    printf("\e[104C██████\e[38;2;147;172;183m████\e[38;2;72;125;178m██\e[38;2;147;172;183m████\e[38;2;72;125;178m████\e[E");
    printf("\e[106C████\e[38;2;147;172;183m██\e[38;2;98;124;136m██\e[38;2;72;125;178m██\e[38;2;147;172;183m██\e[38;2;98;124;136m██\e[38;2;72;125;178m██\e[E");
    printf("\e[108C████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_guiadesligado() {
    printf("\e[27E");
    printf("\e[108C\e[38;2;34;44;49m████████████\e[E");
    printf("\e[106C██\e[38;2;85;96;100m██\e[38;2;103;117;122m██\e[38;2;34;44;49m██\e[38;2;85;96;100m██\e[38;2;103;117;122m██\e[38;2;34;44;49m████\e[E");
    printf("\e[104C████\e[38;2;103;117;122m████\e[38;2;34;44;49m██\e[38;2;103;117;122m████\e[38;2;34;44;49m██████\e[E");
    printf("\e[104C████\e[38;2;103;117;122m██\e[38;2;85;96;100m██\e[38;2;61;69;70m██\e[38;2;103;117;122m██\e[38;2;85;96;100m██\e[38;2;61;69;70m██\e[38;2;34;44;49m████\e[E");
    printf("\e[104C██████\e[38;2;61;69;70m████\e[38;2;34;44;49m██\e[38;2;61;69;70m████\e[38;2;34;44;49m████\e[E");
    printf("\e[106C████\e[38;2;61;69;70m██\e[38;2;42;46;47m██\e[38;2;34;44;49m██\e[38;2;61;69;70m██\e[38;2;42;46;47m██\e[38;2;34;44;49m██\e[E");
    printf("\e[108C████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}
void desenhar_guialimpar() {
    printf("\e[27E");
    printf("\e[108C\e[48;2;0;77;64m            \e[E");
    printf("\e[106C                \e[E");
    printf("\e[104C                    \e[E");
    printf("\e[104C                    \e[E");
    printf("\e[104C                    \e[E");
    printf("\e[106C                \e[E");
    printf("\e[108C            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadores() {
    printf("\e[27E");
    printf("\e[34C\e[38;2;72;125;178m████████████\e[E");
    printf("\e[32C██\e[38;2;3;15;21m████\e[38;2;72;125;178m████\e[38;2;7;22;37m████\e[38;2;72;125;178m██\e[E");
    printf("\e[32C██\e[38;2;3;15;21m████\e[38;2;15;41;79m████\e[38;2;7;22;37m████\e[38;2;72;125;178m██\e[E");
    printf("\e[30C██\e[38;2;3;15;21m██████\e[38;2;15;41;79m████\e[38;2;7;22;37m██████\e[38;2;72;125;178m██\e[E");
    printf("\e[30C██\e[38;2;3;15;21m████\e[38;2;15;41;79m████████\e[38;2;7;22;37m████\e[38;2;72;125;178m██\e[E");
    printf("\e[32C████\e[38;2;15;41;79m████████\e[38;2;72;125;178m████\e[E");
    printf("\e[34C████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadoresdesligado() {
    printf("\e[27E");
    printf("\e[34C\e[38;2;34;44;49m████████████\e[E");
    printf("\e[32C██\e[38;2;28;28;28m████\e[38;2;34;44;49m████\e[38;2;40;40;40m████\e[38;2;34;44;49m██\e[E");
    printf("\e[32C██\e[38;2;28;28;28m████\e[38;2;81;82;83m████\e[38;2;40;40;40m████\e[38;2;34;44;49m██\e[E");
    printf("\e[30C██\e[38;2;28;28;28m██████\e[38;2;81;82;83m████\e[38;2;40;40;40m██████\e[38;2;34;44;49m██\e[E");
    printf("\e[30C██\e[38;2;28;28;28m████\e[38;2;81;82;83m████████\e[38;2;40;40;40m████\e[38;2;34;44;49m██\e[E");
    printf("\e[32C████\e[38;2;81;82;83m████████\e[38;2;34;44;49m████\e[E");
    printf("\e[34C████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadoreslimpar() {
    printf("\e[27E");
    printf("\e[34C\e[48;2;0;77;64m            \e[E");
    printf("\e[32C                \e[E");
    printf("\e[32C                \e[E");
    printf("\e[30C                    \e[E");
    printf("\e[30C                    \e[E");
    printf("\e[32C                \e[E");
    printf("\e[34C            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_seletor(tp_cursor *cursor, float maiorAposta,float jogadorAposta) {
    char corfundo[5][18]={"48;2;96;125;139","48;2;96;125;139","48;2;96;125;139","48;2;96;125;139","48;2;96;125;139"};
    strcpy(corfundo[cursor->navegador],"48;2;33;150;243");
    char corletra[5][18]={"38;2;74;74;74","38;2;74;74;74","38;2;74;74;74","38;2;74;74;74","38;2;74;74;74"};
    strcpy(corletra[cursor->navegador],"38;2;255;209;255");
    if(cursor->navegador==0) desenhar_jogadores();
    else desenhar_jogadoresdesligado();
    if(cursor->navegador==4) desenhar_guia();
    else desenhar_guiadesligado();

    printf("\e[s");
    printf("\e[39E");
    printf("\e[42C\e[48;2;255;255;255m    \e[%sm            \e[48;2;255;255;255m      \e[2C    \e[%sm              \e[48;2;255;255;255m    \e[2C      \e[%sm            \e[48;2;255;255;255m    \e[E",corfundo[1],corfundo[2],corfundo[3]);
    if (maiorAposta != jogadorAposta) printf("\e[42C  \e[%sm     \e[%smAUMENTAR     \e[48;2;255;255;255m  \e[2C  \e[%sm     \e[%smDESISTIR     \e[48;2;255;255;255m  \e[2C  \e[%sm      \e[%smPAGAR       \e[48;2;255;255;255m  \e[E",corfundo[1],corletra[1],corfundo[2],corletra[2],corfundo[3],corletra[3]);
    else     printf("\e[42C  \e[%sm     \e[%smAUMENTAR     \e[48;2;255;255;255m  \e[2C  \e[%sm     \e[%smDESISTIR     \e[48;2;255;255;255m  \e[2C  \e[%sm    \e[%smCONTINUAR     \e[48;2;255;255;255m  \e[E",corfundo[1],corletra[1],corfundo[2],corletra[2],corfundo[3],corletra[3]);
    printf("\e[42C\e[%sm                      \e[2C\e[%sm                      \e[2C\e[%sm                      \e[E",corfundo[1],corfundo[2],corfundo[3]);
    printf("\e[0m");
    printf("\e[H");
}

#endif