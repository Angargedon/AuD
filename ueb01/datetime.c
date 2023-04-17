#include <stdio.h>
#include "datastructure.h"

int isLeapYear(int Year){
    return (((Year % 4 == 0) &&  (Year % 100 != 0)) || (( Year % 100 == 0 && Year % 400 == 0)));
}


int isDateValid(sDate Date){
    int isDay;

    switch(Date.Month){
        case 1: isDay = 31; break;
        case 2: if(isLeapYear(Date.Year) == 1) isDay = 29; else isDay = 28; break;
        case 3: isDay = 31; break;
        case 4: isDay = 30; break;
        case 5: isDay = 31; break;
        case 6: isDay = 30; break;
        case 7: isDay = 31; break;
        case 8: isDay = 31; break;
        case 9: isDay = 30; break;
        case 10: isDay = 31; break;
        case 11: isDay = 30; break;
        case 12: isDay = 31;break;
        default: isDay = 0;
    }
    if(((Date.Day < 1) || (Date.Day > isDay)) == 0) return 1;
    else return 0;
}

int getDateFromString(char in[20], sDate *dateptr){
    int counter = 0;
    int j = 0;
    char point = '.';
    char read[20];

    for(int i = 0;i<20;i++){
        if(in[i] == point || in[i] == NULL){
            if(counter == 0) dateptr->Day = atoi(read);
            else if(counter == 1) dateptr->Month = atoi(read);
            else if(counter == 2) dateptr->Year = atoi(read);

            counter++;
            j = 0;
        }
        else{
            read[j] = in[i];
            read[j+1] = '\n';
            j++;
        }
    }
    return isDateValid(*dateptr);
}
