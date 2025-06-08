#ifndef FUNCOES_ASYNC_H
#define FUNCOES_ASYNC_H

void som_comecar_intro(void *infoVolumeMusica){
    int VolumeFundo = *((int*) infoVolumeMusica);
    audio_play("introsom",0);
    Sleep(3000);
    audio_fade_out("temainicial",2000,VolumeFundo,0);
    
    audio_play("selecaojogadores",1);
    audio_set_volume("selecaojogadores",0);
    audio_fade_in("selecaojogadores",2000,0,VolumeFundo);
}

void som_comecar_musicadejogo_1(void *infoVolumeMusica){
    int VolumeFundo = *((int*) infoVolumeMusica);

    audio_stop("temainicial");
    audio_fade_out("selecaojogadores",2000,VolumeFundo,0);
    Sleep(1000);
    audio_play("musicadejogo1p1",0);
    Sleep(14050);
    audio_play("musicadejogo1p2",1);
}

#endif