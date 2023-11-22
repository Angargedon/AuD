#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    }while ((Input != 'j') && (Input != 'J') && (Input != 'Y') && (Input != 'y') && (Input != 'n') && (Input != 'N'));

    return ((Input == 'j') || (Input == 'J') || (Input == 'Y') || (Input == 'y'));
}

void waitForEnter(char *text){
    printf("%s", text);
    clearBuffer();
}

void printLine(char look, int lenght){
    for(int i=0; i<lenght; i++){
        printf("%c", look);
    }
}

void title(char *name, char line){
    printf("%s", name);
    enter(1);
    printLine(line, strlen(name));
}

void Dog(){
    clearScreen();
    printf("Dog");
}
