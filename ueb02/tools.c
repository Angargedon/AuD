#include <stdio.h>
#include <stdlib.h>

void clearBuffer(){
    char dummy;

    while(dummy != '\n') scanf("%c", &dummy);
}

void clearScreen(){
    system("CLS");
}

void waitForEnter(){
    printf("Eingabetaste druecken...");
    clearBuffer();
}

int askYesOrNo(char *Question){
    char Input;

    do{
    printf("%s", Question);
      scanf("%c", &Input);
      if (Input != '\n')   clearBuffer();
    } while ((Input != 'j') && (Input != 'J') && (Input != 'n') && (Input != 'N'));

    return ((Input == 'j') || (Input == 'J'));
}

void enter(int howManyTimes){
    for(int i=0;i<howManyTimes;i++){
        printf("\n");
    }
}

void printLine(char look, int howManyTimes){
    for(int i=0;i<howManyTimes;i++){
        printf("%c", look);
    }
}
