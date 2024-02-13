#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "datastructure.h"
#include "sort.h"

int calcDivisionRest(char *calcString){
    int Sum = 0;

    while(*calcString != '\0'){
        Sum += toupper(*calcString);
        calcString++;
    }

    return (Sum % MAXINDEX);
}

sListEntry *searchDesc(sHashEntry *hIndex, char *stringCalc, int (*compare) (char *, char *)){
    int Index;
    sListEntry *searchList = NULL;

    Index = calcDivisionRest(stringCalc);
    *hIndex = hIndex[Index];
    searchList = hIndex->first;

    while(searchList != NULL){
        if(compare(searchList->Appointment->Description, stringCalc) == 0)
            break;
        else
            searchList = searchList->Next;
    }

    return searchList;
}


sListEntry *searchLoc(sHashEntry *hIndex, char *stringCalc, int (*compare) (char *, char *)){
    int Index;
    sListEntry *searchList = NULL;

    Index = calcDivisionRest(stringCalc);
    *hIndex = hIndex[Index];
    searchList = hIndex->first;

    while(searchList != NULL){
        if(compare(searchList->Appointment->Location, stringCalc) == 0)
            break;
        else
            searchList = searchList->Next;
    }

    return searchList;
}