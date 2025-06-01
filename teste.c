
#include <windows.h>
#include <stdio.h>
#include <string.h>

#define CON_WIDTH 156
#define CON_HEIGHT 44

/* --------------------------------------------------
 * Estruturas e tipos
 * --------------------------------------------------*/
typedef struct {
    HMODULE hWinMM;
    DWORD (WINAPI *mciSendStringA)(LPCSTR, LPSTR, UINT, HWND);
    BOOL  (WINAPI *mciGetErrorStringA)(DWORD, LPSTR, UINT);
} MCI_CONTEXT;

/* --------------------------------------------------
 * Ajustes de console (cores ANSI, UTF‑8, 156×44)
 * --------------------------------------------------*/
void windowsconfig(void)
{
    /* dimensiona janela */
    char cmd[64];
    snprintf(cmd, sizeof(cmd), "mode %d,%d", CON_WIDTH, CON_HEIGHT);
    system(cmd);

    /* UTF‑8 */
    SetConsoleOutputCP(CP_UTF8);

    /* Habilita escapes ANSI */
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (GetConsoleMode(hOut, &mode))
        SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

/* --------------------------------------------------
 * Inicialização / finalização do WinMM
 * --------------------------------------------------*/
int mci_init(MCI_CONTEXT *ctx)
{
    memset(ctx, 0, sizeof(*ctx));

    ctx->hWinMM = LoadLibraryA("winmm.dll");
    if (!ctx->hWinMM)
        return 0;

    ctx->mciSendStringA = (void*)GetProcAddress(ctx->hWinMM, "mciSendStringA");
    ctx->mciGetErrorStringA = (void*)GetProcAddress(ctx->hWinMM, "mciGetErrorStringA");

    if (!ctx->mciSendStringA || !ctx->mciGetErrorStringA) {
        FreeLibrary(ctx->hWinMM);
        memset(ctx, 0, sizeof(*ctx));
        return 0;
    }
    return 1;
}

void mci_finalize(MCI_CONTEXT *ctx)
{
    if (ctx->hWinMM)
        FreeLibrary(ctx->hWinMM);
    memset(ctx, 0, sizeof(*ctx));
}

/* --------------------------------------------------
 * Utilidades de erro
 * --------------------------------------------------*/
void print_mci_error(MCI_CONTEXT *ctx, DWORD err)
{
    char msg[256] = {0};
    if (ctx->mciGetErrorStringA && ctx->mciGetErrorStringA(err, msg, sizeof msg))
        fprintf(stderr, "MCI error %lu: %s\n", err, msg);
    else
        fprintf(stderr, "MCI error %lu (unknown)\n", err);
}

/* --------------------------------------------------
 * Funções auxiliares de reprodução
 * --------------------------------------------------*/
void parar_som_mci(MCI_CONTEXT *ctx, const char *alias)
{
    char cmd[128];
    DWORD err;

    snprintf(cmd, sizeof cmd, "stop %s", alias);
    err = ctx->mciSendStringA(cmd, NULL, 0, NULL);
    if (err) print_mci_error(ctx, err);

    snprintf(cmd, sizeof cmd, "close %s", alias);
    err = ctx->mciSendStringA(cmd, NULL, 0, NULL);
    if (err) print_mci_error(ctx, err);
}

int som_terminou(MCI_CONTEXT *ctx, const char *alias)
{
    char cmd[128], buf[64] = {0};
    DWORD err;

    snprintf(cmd, sizeof cmd, "status %s mode", alias);
    err = ctx->mciSendStringA(cmd, buf, sizeof buf, NULL);
    if (err) {
        print_mci_error(ctx, err);
        return 1; /* assume parado em erro */
    }
    return strcmp(buf, "playing") != 0;
}

void ajustar_volume(MCI_CONTEXT *ctx, const char *alias, int vol /*0‑1000*/)
{
    if (vol < 0) vol = 0;
    if (vol > 1000) vol = 1000;

    char cmd[128];
    snprintf(cmd, sizeof cmd, "setaudio %s volume to %d", alias, vol);
    DWORD err = ctx->mciSendStringA(cmd, NULL, 0, NULL);
    if (err) print_mci_error(ctx, err);
}

/* --------------------------------------------------
 * Helper de caminhos (mesmo diretório do .exe)
 * --------------------------------------------------*/
static int build_wav_path(char *out, size_t cap, const char *filename)
{
    DWORD len = GetModuleFileNameA(NULL, out, (DWORD)cap);
    if (!len || len >= cap) return 0;

    char *slash = strrchr(out, '\\');
    if (!slash) return 0;
    slash[1] = '\0';

    if (strlen(out) + strlen(filename) + 1 > cap) return 0;
    strcat(out, filename);
    return 1;
}

/* --------------------------------------------------
 * Reprodução de áudio
 * --------------------------------------------------*/
void tocar_um_som(MCI_CONTEXT *ctx, const char *alias, const char *filename)
{
    char path[MAX_PATH];
    if (!build_wav_path(path, sizeof path, filename)) {
        fprintf(stderr, "Path too long for %s\n", filename);
        return;
    }

    char cmd[512];
    DWORD err;

    snprintf(cmd, sizeof cmd, "open \"%s\" alias %s", path, alias);
    err = ctx->mciSendStringA(cmd, NULL, 0, NULL);
    if (err) { print_mci_error(ctx, err); return; }

    snprintf(cmd, sizeof cmd, "play %s", alias);
    err = ctx->mciSendStringA(cmd, NULL, 0, NULL);
    if (err) print_mci_error(ctx, err);
}

void tocar_um_som_loop(MCI_CONTEXT *ctx, const char *alias, const char *filename)
{
    char path[MAX_PATH];
    if (!build_wav_path(path, sizeof path, filename)) {
        fprintf(stderr, "Path too long for %s\n", filename);
        return;
    }

    char cmd[512];
    DWORD err;

    snprintf(cmd, sizeof cmd, "open \"%s\" type waveaudio alias %s", path, alias);
    err = ctx->mciSendStringA(cmd, NULL, 0, NULL);
    if (err) { print_mci_error(ctx, err); return; }

    snprintf(cmd, sizeof cmd, "play %s from 0 repeat", alias);
    err = ctx->mciSendStringA(cmd, NULL, 0, NULL);
    if (err) print_mci_error(ctx, err);
}

int main(void)
{
    windowsconfig();

    MCI_CONTEXT ctx;
    if (!mci_init(&ctx)) {
        fputs("Falha ao carregar winmm.dll\n", stderr);
        return 1;
    }

    tocar_um_som(&ctx, "fx1", "audio1.wav");

    /* espera terminar */
    while (!som_terminou(&ctx, "fx1"))
        Sleep(100);

    mci_finalize(&ctx);
    return 0;
}