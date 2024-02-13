#ifndef SEARCH_H
#define SEARCH_H
#include "datastructure.h"

int calcDivisionRest(char *calcString);


sListEntry *searchDesc(sHashEntry *hIndex, char *stringCalc, int (*compare) (char *, char *));


sListEntry *searchLoc(sHashEntry *hIndex, char *stringCalc, int (*compare) (char *, char *));

#endif