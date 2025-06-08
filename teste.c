#include <stdio.h>
#include <windows.h>
#include "async.h"

/// Exemplo de função sem parâmetro: imprime mensagem repetidamente.
void spam_printer(void) {
    while (1) {
        printf("[spam_printer] rodando...\n");
        Sleep(500);
    }
}

/// Exemplo de função com parâmetro inteiro: imprime valor repetidamente.
/// @param data Ponteiro para inteiro a ser impresso.
void int_printer(void *data) {
    int value = *((int*)data);
    while (1) {
        printf("[int_printer] valor = %d\n", value);
        Sleep(1000);
    }
}

int main(void) {
    // Inicia thread sem argumento
    async_thread_t t0 = async_run0(spam_printer);

    // Inicia thread com parâmetro inteiro
    int number = 1234;
    async_thread_t t1 = async_run(int_printer, &number);

    // Thread principal bloqueada lendo input:
    printf("Digite algo para encerrar...\n");
    char buf[64];
    scanf("%63s", buf);

    // Aguarda término das threads (na prática, são loops infinitos).
    async_join(t0);
    async_join(t1);
    return 0;
}
