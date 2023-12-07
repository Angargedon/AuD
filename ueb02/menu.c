#include <stdio.h>
#include "datastructure.h"
#include "tools.h"

int getMenu(char title[],char *entries[],int entryCount){

    int menuPoint = 0;

    do{
        clearScreen();
        printf("%s", title);
        enter(1);
        printLine('=', 50);
        enter(2);

        for(int i=0;i<entryCount;i++){
            printf("%i. %s", i+1, entries[i]);
            enter(2);
        }

        printf("Geben Sie einen Menuepunkt zwischen 1 und %i ein: ", entryCount);
        scanf("%d", &menuPoint);
        clearBuffer();
        enter(1);

    }while((menuPoint) < 1 && (menuPoint) > entryCount);

    return menuPoint;
}
