#include <stdio.h>
#include <windows.h>
#include "miscelanea.h"

int main() {

    int input=-1;
    while (input == -1) input = getch();
    printf("Numero Ascii: %d\n",input);
    system("pause");
    return 0;

}
