#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int getText(char* Text, int Maxlen, char** P, int AllowEmpt){
    char* In = NULL;
    char Format[15];
    int Ok;
    int Lenght;

    if(Maxlen <= 0)
        return 0;
    if(P == NULL)
        return 0;
    *P = NULL;
    In = malloc(Maxlen + 1);

    if(In){
        sprintf(Format, "%%%[^\n]", Maxlen);
        do{
            printf(Text);
            *In = '\0';
            Ok = scanf(Format, In);
            clearBuffer();
            Lenght = (int)strlen(In);

            if(Lenght > 0){
                *P = calloc(Lenght+1, sizeof(char));
                if(*P == NULL){
                    free(In);
                    return 0;
                }
                strcpy(*P, In);
            }
            else if(AllowEmpt){
                free(In);
                return 2;
            }
            else
                Ok = 0;
        }while(!Ok);

        free(In);
        return 1;
    }
    return 0;
}

int getNumber(char* Text, int* In, int BorderA, int BorderB){
    int x;

    if(In == 0)
        return 0;
    if(BorderA > BorderB)
        return 0;
    do{
        printf(Text);
        x = scanf("%i[^\n]", In);
        clearBuffer();
    }while(!x || *In < BorderA ||*In > BorderB);
    return 1;
}

void getFloat(char *Text, float *In){
    int x;

    do{
        printf(Text);
        x = scanf("%f", In);
        clearBuffer();
    }while(!x ||*In < 0);
}
