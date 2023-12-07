#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

int isLeapYear(int Year);

int isDateValid(sDate Date);

int getDateFromString(char in[20], sDate *dateptr);

#endif // DATETIME_H_INCLUDED
