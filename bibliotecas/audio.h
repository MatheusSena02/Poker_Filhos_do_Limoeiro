#ifndef AUDIO_H
#define AUDIO_H

// Força a implementação do miniaudio nesta unidade
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#define MAX_TRACKS 64

/**
 * @brief Estrutura que representa uma faixa de áudio.
 */
typedef struct {
    char     alias[32];  /**< Nome único para referenciar a faixa */
    ma_sound sound;      /**< Objeto de som do miniaudio        */
    float    volume;     /**< Volume atual (0.0 a 100.0)         */
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
        return;
    }
    // Volume padrão 100%
    t->volume = 100.0f;
    ma_sound_set_volume(&t->sound, t->volume / 100.0f);
}

/**
 * @brief Inicia a reprodução de uma faixa.
 *
 * @param alias  Alias da faixa a tocar.
 * @param loop   true = loop infinito; false = toca uma vez.
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
 * @param alias  Alias da faixa a parar.
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
 * @brief Ajusta o volume de uma faixa em tempo real.
 *
 * @param alias           Alias da faixa.
 * @param volume_percent  Volume (0.0 a 100.0).
 */
static void audio_set_volume(const char *alias, float volume_percent) {
    for (int i = 0; i < track_count; i++) {
        if (strcmp(tracks[i].alias, alias) == 0) {
            tracks[i].volume = volume_percent;
            ma_sound_set_volume(&tracks[i].sound, volume_percent / 100.0f);
            return;
        }
    }
}

/**
 * @brief Estrutura interna para tarefas de fade.
 */
typedef struct {
    char     alias[32];       /**< Alias da faixa */
    uint32_t duration_ms;     /**< Duração total em milissegundos */
    float    start_volume;    /**< Volume inicial (0.0 a 100.0) */
    float    end_volume;      /**< Volume final (0.0 a 100.0) */
} FadeTask;

// Thread de fade
static void *fade_thread(void *arg) {
    FadeTask *task = (FadeTask *)arg;
    for (int i = 0; i < track_count; i++) {
        if (strcmp(tracks[i].alias, task->alias) == 0) {
            Track *t = &tracks[i];
            int steps = task->duration_ms / 10;
            if (steps < 1) steps = 1;
            uint32_t step_ms = task->duration_ms / steps;

            // Define volume inicial e inicia se necessário
            audio_set_volume(task->alias, task->start_volume);
            if (task->start_volume < task->end_volume) {
                // Se for fade in, garante que o som toque
                ma_sound_start(&t->sound);
            }

            // Atualiza volume em passos
            for (int s = 1; s <= steps; s++) {
                ma_sleep(step_ms);
                float v = task->start_volume + (task->end_volume - task->start_volume) * ((float)s / steps);
                audio_set_volume(task->alias, v);
            }

            break;
        }
    }
    free(task);
    return NULL;
}

static int audio_is_playing(const char *alias) {
    for (int i = 0; i < track_count; i++) {
        if (strcmp(tracks[i].alias, alias) == 0) {
            // ma_sound_is_playing retorna MA_TRUE (1) ou MA_FALSE (0).
            // Retornamos diretamente o resultado.
            return ma_sound_is_playing(&tracks[i].sound);
        }
    }
    // Se o loop terminar, o alias não foi encontrado, então não está tocando.
    return 0;
}

/**
 * @brief Aplica fade in em uma faixa, variando o volume entre dois níveis.
 *
 * @param alias         Alias da faixa.
 * @param duration_ms   Duração do fade em milissegundos.
 * @param from_volume   Volume inicial (0.0 a 100.0).
 * @param to_volume     Volume final (0.0 a 100.0).
 */
static void audio_fade_in(const char *alias, uint32_t duration_ms, float from_volume, float to_volume) {
    FadeTask *task = malloc(sizeof(FadeTask));
    strncpy(task->alias, alias, sizeof(task->alias));
    task->duration_ms = duration_ms;
    task->start_volume = from_volume;
    task->end_volume   = to_volume;

    pthread_t thread;
    pthread_create(&thread, NULL, fade_thread, task);
    pthread_detach(thread);
}

/**
 * @brief Aplica fade out em uma faixa, variando o volume entre dois níveis sem parar a reprodução.
 *
 * @param alias         Alias da faixa.
 * @param duration_ms   Duração do fade em milissegundos.
 * @param from_volume   Volume inicial (0.0 a 100.0).
 * @param to_volume     Volume final (0.0 a 100.0).
 */
static void audio_fade_out(const char *alias, uint32_t duration_ms, float from_volume, float to_volume) {
    FadeTask *task = malloc(sizeof(FadeTask));
    strncpy(task->alias, alias, sizeof(task->alias));
    task->duration_ms = duration_ms;
    task->start_volume = from_volume;
    task->end_volume   = to_volume;

    pthread_t thread;
    pthread_create(&thread, NULL, fade_thread, task);
    pthread_detach(thread);
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

void audio_setar_audios(int alt){
    audio_load("selecao","audios/efeitos/sele.mp3");
    audio_load("botao","audios/efeitos/button.mp3");
    audio_load("cancelar","audios/efeitos/cancel.mp3");
    audio_load("som2carta","audios/efeitos/som2carta.mp3");
    audio_load("som3carta","audios/efeitos/som3carta.mp3");
    audio_load("som4carta","audios/efeitos/som4carta.mp3");
    audio_load("som5carta","audios/efeitos/som5carta.mp3");
    audio_load("cancel","audios/efeitos/cancel.mp3");
    audio_load("dinheiro","audios/efeitos/dinheiro.mp3");
    audio_load("perda","audios/efeitos/perda.mp3");
    audio_load("finalselect","audios/efeitos/finalselect.wav");

    audio_load("introsom","audios/musica/introsom.mp3");
    if (alt==0) audio_load("temainicial","audios/musica/temainicial.mp3");
    if (alt==1) audio_load("temainicial","audios/musica/pokerfacebit.mp3");
    audio_load("selecaojogadores","audios/musica/selecaojogadores.mp3");
    audio_load("musicadejogo1pt1","audios/musica/musicadejogo1pt1.mp3");
    audio_load("musicadejogo1pt2","audios/musica/musicadejogo1pt2.mp3");
    audio_load("musicadejogo2","audios/musica/musicadejogo2.mp3");
    audio_load("musicadejogo3pt1","audios/musica/musicadejogo3pt1.mp3");
    audio_load("musicadejogo3pt2","audios/musica/musicadejogo3pt2.mp3");
    if (alt==0) audio_load("musicafinalpt1","audios/musica/musicafinalpt1.mp3");
    if (alt==0) audio_load("musicafinalpt2","audios/musica/musicafinalpt2.mp3");
    if (alt==1) audio_load("musicafinalpt1","audios/musica/pokerfaceforropt1.mp3");
    if (alt==1) audio_load("musicafinalpt2","audios/musica/pokerfaceforro.mp3");
}

void audio_setar_volume_fundo(float volume){
    audio_set_volume("introsom",volume);
    audio_set_volume("temainicial",volume);
    audio_set_volume("selecaojogadores",volume);
    audio_set_volume("musicadejogo1pt1",volume);
    audio_set_volume("musicadejogo1pt2",volume);
    audio_set_volume("musicadejogo2",volume);
    audio_set_volume("musicadejogo3pt1",volume);
    audio_set_volume("musicadejogo3pt2",volume);
    audio_set_volume("musicafinalpt1",volume);
    audio_set_volume("musicafinalpt2",volume);
}

void audio_setar_volume_efeito(float volume){
    audio_set_volume("selecao",volume);
    audio_set_volume("botao",volume);
    audio_set_volume("cancelar",volume);
    audio_set_volume("som2carta",volume);
    audio_set_volume("som3carta",volume);
    audio_set_volume("som4carta",volume);
    audio_set_volume("som5carta",volume);
    audio_set_volume("cancel",volume);
    audio_set_volume("perda",volume);
    audio_set_volume("dinheiro",volume);
    audio_set_volume("finalselect",volume);
    
}

void audio_stop_total(){
    audio_stop("introsom");
    audio_stop("temainicial");
    audio_stop("selecaojogadores");
    audio_stop("musicadejogo1pt1");
    audio_stop("musicadejogo1pt2");
    audio_stop("musicadejogo2");
    audio_stop("musicadejogo3pt1");
    audio_stop("musicadejogo3pt2");
    audio_stop("musicafinalpt1");
    audio_stop("musicafinalpt2");
}

#endif // AUDIO_H
