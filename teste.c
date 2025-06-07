/* main.c */
#include "audio.h"

int main(void) {
    audio_init();

    audio_load("fundo",   "wow.mp3");
    audio_load("efeito",  "swoosh.wav");

    audio_play("fundo",  true);   // loop infinito
    audio_play("efeito", false);  // toca só uma vez

    audio_set_volume("fundo", 10);

    // Exemplo de uso da nova função:
    // Desativa o loop, mas deixa o trecho atual tocar até o fim.
    // audio_disable_loop("fundo");

    printf("Pressione Enter para sair...\n");
    getchar();

    audio_shutdown();
    return 0;
}
