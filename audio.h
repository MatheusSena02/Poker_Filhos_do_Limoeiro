/* audio.h */
#ifndef AUDIO_H
#define AUDIO_H

// Força a implementação do miniaudio aqui
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TRACKS 16

/**
 * @brief Estrutura que representa uma faixa de áudio.
 */
typedef struct {
    char    alias[32];  /**< Nome único para referenciar a faixa */
    ma_sound sound;     /**< Objeto de som do miniaudio        */
} Track;

// Engine global e array de faixas
static ma_engine engine;
static Track    tracks[MAX_TRACKS];
static int      track_count = 0;

/**
 * @brief Inicializa o engine de áudio.
 *
 * Deve ser chamado antes de qualquer outra função de áudio.
 */
static void audio_init(void) {
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        fprintf(stderr, "Falha ao inicializar o engine de áudio\n");
        exit(1);
    }
}

/**
 * @brief Carrega um arquivo (WAV ou MP3) e atribui um alias.
 *
 * @param alias     Nome único para a faixa.
 * @param filename  Caminho para o arquivo de áudio.
 */
static void audio_load(const char *alias, const char *filename) {
    if (track_count >= MAX_TRACKS) return;
    Track *t = &tracks[track_count++];
    strncpy(t->alias, alias, sizeof(t->alias));
    if (ma_sound_init_from_file(
            &engine,
            filename,
            MA_SOUND_FLAG_DECODE | MA_SOUND_FLAG_ASYNC,
            NULL, NULL,
            &t->sound
        ) != MA_SUCCESS) {
        fprintf(stderr, "Falha ao carregar som: %s\n", filename);
    }
}

/**
 * @brief Inicia a reprodução de uma faixa.
 *
 * @param alias   Alias da faixa a tocar.
 * @param loop    true = loop infinito; false = toca uma vez.
 */
static void audio_play(const char *alias, bool loop) {
    for (int i = 0; i < track_count; i++) {
        if (strcmp(tracks[i].alias, alias) == 0) {
            ma_sound_set_looping(&tracks[i].sound, loop ? MA_TRUE : MA_FALSE);
            ma_sound_start(&tracks[i].sound);
            return;
        }
    }
}

/**
 * @brief Para imediatamente a reprodução de uma faixa.
 *
 * @param alias   Alias da faixa a parar.
 */
static void audio_stop(const char *alias) {
    for (int i = 0; i < track_count; i++) {
        if (strcmp(tracks[i].alias, alias) == 0) {
            ma_sound_stop(&tracks[i].sound);
            return;
        }
    }
}

/**
 * @brief Desativa o loop de uma faixa, deixando-a tocar até o fim.
 *
 * @param alias   Alias da faixa a modificar.
 */
static void audio_disable_loop(const char *alias) {
    for (int i = 0; i < track_count; i++) {
        if (strcmp(tracks[i].alias, alias) == 0) {
            ma_sound_set_looping(&tracks[i].sound, MA_FALSE);
            return;
        }
    }
}

/**
 * @brief Ajusta o volume de uma faixa em tempo real.
 *
 * @param alias            Alias da faixa.
 * @param volume_percent   Volume (0.0 a 100.0).
 */
static void audio_set_volume(const char *alias, float volume_percent) {
    float v = volume_percent / 100.0f;
    for (int i = 0; i < track_count; i++) {
        if (strcmp(tracks[i].alias, alias) == 0) {
            ma_sound_set_volume(&tracks[i].sound, v);
            return;
        }
    }
}

/**
 * @brief Descarrega todas as faixas e finaliza o engine de áudio.
 */
static void audio_shutdown(void) {
    for (int i = 0; i < track_count; i++) {
        ma_sound_uninit(&tracks[i].sound);
    }
    ma_engine_uninit(&engine);
    track_count = 0;
}

#endif // AUDIO_H
