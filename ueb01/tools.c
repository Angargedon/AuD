#include <stdio.h>
#include <stdlib.h>

void enter(int howManyTimes){
    for(int i=0;i<howManyTimes;i++) printf("\n");
}

void clearScreen(){
    system("CLS");
}

void clearBuffer(){
    char dummy;

    while(dummy != '\n') scanf("%c", &dummy);
}

int askYesOrNo(char *question){
    char Input;

    do{
    printf("%s", question);
      scanf("%c", &Input);
      if (Input != '\n')   clearBuffer();
    } while ((Input != 'j') && (Input != 'J') && (Input != 'n') && (Input != 'N'));

    return ((Input == 'j') || (Input == 'J'));
}