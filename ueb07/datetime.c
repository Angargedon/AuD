#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include "datastructure.h"
#include "tools.h"
 

int dayOfWeek(sDate *date){
    static int jMonth[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int d = date->Day;
    int m = date->Month;
    int y = date->Year;

    if(m < 3) y--;

    return(y + (y/4) - (y/100) + (y/400) + jMonth[m - 1] + d) % 7;
}


int isLeapYear(int year){
    return (((year % 4 == 0) &&  (year % 100 != 0)) || ((year % 100 == 0 && year % 400 == 0)));
}


int isDateValid(sDate *Date){
    int isDay;

    switch(Date->Month){
        case 1: isDay = 31; break;
        case 2: if(isLeapYear(Date->Year) == 1) isDay = 29; else isDay = 28; break;
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
    if(((Date->Day < 1) || (Date->Day > isDay) || (Date->Year < 1)) == 0){
        return 1;
    }
    else return 0;
}



int getDateFromString(char *in, sDate *dateptr){                            
    int counter = 0;                                                        
    int j = 0;                                                              
    char point = '.';                                                       
    char read[20];                                                        
                                                                            
    for(int i = 0;counter<3;i++){                                           
        if(in[i] == point || in[i] == NULL){               
            if(counter == 0) dateptr->Day = atoi(read);
            else if(counter == 1) dateptr->Month = atoi(read);
            else if(counter == 2) dateptr->Year = atoi(read);

            counter++;
            j = 0;
        }
        else{
            read[j] = in[i];
            read[j+1] = '\0';
            j++;
        }

        if(in[i] == NULL){
            if(isDateValid(dateptr)){
                dateptr->WeekDay = dayOfWeek(dateptr);
                return 1;
            }
            else return 0;
        }
    }
}



int getDate(char *prompt, sDate *date){
    char in[20];

    
    do{
        printf(prompt);
        scanf("%s", in);
        clearBuffer();
    }while(getDateFromString(in, date) != 1);

    return 1;
}



int isTimeValid(sTime Time){
    int isHourValid = (Time.Hour >= 0) && (Time.Hour <= 23);
    int isMinuteValid = (Time.Minute >= 0) && (Time.Minute <= 59);

    return (isHourValid && isMinuteValid);
}


int getTimeFromString(char *in, sTime *timeptr){                            
    int counter = 0;                                                        
    int j = 0;                                                              
    char point = ':';                                                       
    char read[20];                                                        
                                                                            
    for(int i = 0;counter<2;i++){                                           
        if(in[i] == point || in[i] == NULL){               
            if(counter == 0) timeptr->Hour = atoi(read);
            else if(counter == 1) timeptr->Minute = atoi(read);

            counter++;
            j = 0;
        }
        else{
            read[j] = in[i];
            read[j+1] = '\0';
            j++;
        }
        if(in[i] == NULL) return isTimeValid(*timeptr);
    }
}


int isTimeValidLite(sTime Time){
    int isHourValid = (Time.Hour >= 0);
    int isMinuteValid = (Time.Minute >= 0) && (Time.Minute <= 60);
    int isSecondValid = (Time.Second >= 0) && (Time.Second <= 60);

    return (isHourValid && isMinuteValid && isSecondValid);
}


int getTimeFromStringLite(char *in, sTime *timeptr){                            
    int counter = 0;                                                        
    int j = 0;                                                              
    char point = ':';                                                       
    char read[20];                                                        
                                                                            
    for(int i = 0;counter<3;i++){                                           
        if(in[i] == point || in[i] == NULL){               
            if(counter == 0) timeptr->Hour = atoi(read);
            else if(counter == 1) timeptr->Minute = atoi(read);
            else if(counter == 2) timeptr->Second = atoi(read);

            counter++;
            j = 0;
        }
        else{
            read[j] = in[i];
            read[j+1] = '\0';
            j++;
        }
        if(in[i] == NULL) return isTimeValidLite(*timeptr);
    }
}


int getTime(char *prompt, sTime *time){
    char in[20];


    do{
        printf(prompt);
        scanf("%s", in);
        clearBuffer();
    }while(getTimeFromString(in, time) != 1);

    return 1;
}



int getDuration(char *prompt, sTime *time){
    char in[20];
    int Len;

    do{
        printf(prompt);
        scanf("%[^\n]", in);
        clearBuffer();
        Len = strlen(in);
    }while(!(getTimeFromStringLite(in, time)) && (Len != 0));

    return 1;
}


void printDate(sDate *dateptr){
    printf("%02i.%02i.%04i", dateptr->Day, dateptr->Month, dateptr->Year);
}


void printTime(sTime *timeptr){
    printf("%02i:%02i", timeptr->Hour, timeptr->Minute);
}


sTime addTime(sTime *startTime, sTime *duration){
    sTime endTime;

    endTime.Hour = startTime->Hour + duration->Hour;
    endTime.Minute = startTime->Minute + duration->Minute;

    if (endTime.Minute >= 60){
        endTime.Hour += endTime.Minute / 60;
        endTime.Minute %= 60;
    }

    endTime.Hour %= 24;

    return endTime;
}