#ifndef DATETIME_H
#define DATETIME_H
#include "datastructure.h"

int isLeapYear(int year);

int isDateValid(int Month);

int getDateFromString(char in[],sDate *dateptr);

#endif