
/* sprite_demo.c  —  tudo em um arquivo .c + header
 *
 * Compile sem precisar adicionar outros .c:
 *     gcc sprite_demo.c -O2 -std=c11 -o sprite_demo
 * Em Windows (MinGW‑w64) isso já basta.
 * Rode:  sprite_demo sheet.png
 */

#define ANSI_SPRITE_IMPLEMENTATION   /* injeta a implementação */
#include "ansi_sprite.h"
#include <stdio.h>

int main()
{
    //Carregamento
    const char *sheetPath = "anim/quatro.png";
    SpriteSheet *sheet = sprite_sheet_load(sheetPath, 15, 15);
    if (!sheet) { fprintf(stderr, "Falha ao carregar %s\n", sheetPath); return 1; }


    //Uso
    sprite_animate(sheet, 2, 80000, "255;255;0", 50, 2);
    sprite_sheet_free(sheet);
    return 0;
}
