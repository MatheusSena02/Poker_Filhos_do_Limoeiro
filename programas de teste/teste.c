#include <stdio.h>
#include <windows.h>
#include "async.h"
#include "audio.h"

int main(void) {
    audio_init();
    audio_setar_audios();
    audio_set_volume("musicadejogo1pt1",20);
    audio_set_volume("musicadejogo1pt2",20);
    audio_play("musicadejogo1pt1",0);
    Sleep(14200);
    audio_play("musicadejogo1pt2",1);
    audio_stop("musicadejogo1pt1");
    system("pause");
}
