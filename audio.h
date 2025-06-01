// audio.h --- Pequena API em C sobre miniaudio para reproduzir MP3 por alias
// Arthur • Junho 2025
//
// Como usar:
//   #define AUDIO_IMPLEMENTATION
//   #include "audio.h"
//
// Depois compile normalmente, linkando as libs de sistema que o miniaudio exige
// (ex.: -ldl -lpthread no Linux; no Windows/MSVC nada extra; no macOS
//        -framework CoreAudio -framework AudioUnit -framework AudioToolbox).
//
// Esta é uma "single‑header library": apenas um TU deve definir
// AUDIO_IMPLEMENTATION; os demais apenas #include "audio.h".
// ---------------------------------------------------------------------------
#ifndef AUDIO_H
#define AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

/** Número máximo de faixas que podem ser carregadas simultaneamente */
#ifndef AUDIO_MAX_TRACKS
#define AUDIO_MAX_TRACKS 16
#endif

/* API pública --------------------------------------------------------------*/

/** Inicializa o engine global.  Retorna 0 (MA_SUCCESS) se OK. */
int  audio_init(void);

/** Libera tudo que foi carregado e encerra o engine. */
void audio_shutdown(void);

/**
 * Carrega (ou reconfigura) uma faixa.
 *  alias   → identificador único (até 31 chars).
 *  path    → caminho do .mp3 ou .wav etc.
 *  loop    → 0 = toca 1x ; ≠0 = loop indefinido.
 * Retorna 0 se sucesso; <0 se erro.
 */
int  audio_load(const char *alias, const char *path, int loop);

/** Começa/recomeça a tocar o alias já carregado (não bloqueia). */
void audio_play(const char *alias);

/** Para a reprodução imediatamente. */
void audio_stop(const char *alias);

/** Ajusta volume (0‒100). Pode ser chamado em runtime. */
void audio_set_volume(const char *alias, int volume);

#ifdef __cplusplus
}
#endif

#endif /* AUDIO_H */

/* ====================== IMPLEMENTAÇÃO OPCIONAL =========================== */
#ifdef AUDIO_IMPLEMENTATION

#define MINIAUDIO_IMPLEMENTATION   /* insere código do miniaudio nesta TU */
#include "miniaudio.h"            /* https://github.com/mackron/miniaudio */

#include <string.h>  /* strncpy */

/* Estrutura interna ------------------------------------------------------- */
typedef struct {
    char     id[32];
    ma_sound snd;
    int      in_use;
} audio_track;

static ma_engine   g_engine;
static audio_track g_tracks[AUDIO_MAX_TRACKS];

static audio_track *audio__find(const char *alias)
{
    for (size_t i = 0; i < AUDIO_MAX_TRACKS; ++i)
        if (g_tracks[i].in_use && strcmp(g_tracks[i].id, alias) == 0)
            return &g_tracks[i];
    return NULL;
}

/* Funções públicas -------------------------------------------------------- */
int audio_init(void)
{
    memset(g_tracks, 0, sizeof g_tracks);
    return ma_engine_init(NULL, &g_engine); /* usa backend padrão do SO */
}

void audio_shutdown(void)
{
    for (size_t i = 0; i < AUDIO_MAX_TRACKS; ++i)
        if (g_tracks[i].in_use) {
            ma_sound_uninit(&g_tracks[i].snd);
            g_tracks[i].in_use = 0;
        }
    ma_engine_uninit(&g_engine);
}

int audio_load(const char *alias, const char *path, int loop)
{
    audio_track *t = audio__find(alias);

    if (!t) {
        /* procura slot livre */
        for (size_t i = 0; i < AUDIO_MAX_TRACKS; ++i)
            if (!g_tracks[i].in_use) { t = &g_tracks[i]; break; }
        if (!t) return -1;           /* sem espaço */

        strncpy(t->id, alias, sizeof t->id - 1);
        t->id[sizeof t->id - 1] = '\0';
        t->in_use = 1;

        if (ma_sound_init_from_file(&g_engine, path,
                MA_SOUND_FLAG_DECODE | MA_SOUND_FLAG_ASYNC,
                NULL, &t->snd) != MA_SUCCESS) {
            t->in_use = 0;
            return -2;               /* erro ao carregar */
        }
    }

    ma_sound_set_looping(&t->snd, loop ? MA_TRUE : MA_FALSE);
    return 0;
}

void audio_play(const char *alias)
{
    audio_track *t = audio__find(alias);
    if (t) ma_sound_start(&t->snd);
}

void audio_stop(const char *alias)
{
    audio_track *t = audio__find(alias);
    if (t) ma_sound_stop(&t->snd);
}

void audio_set_volume(const char *alias, int volume)
{
    audio_track *t = audio__find(alias);
    if (t) ma_sound_set_volume(&t->snd, volume / 100.0f);
}

#endif /* AUDIO_IMPLEMENTATION */
