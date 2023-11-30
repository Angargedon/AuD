#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "datastructure.h"
#include "tools.h"

sAppointment Calendar[MAXAPPOINTMENTS];

int dayOfWeek(int d, int m, int y){
    static int jMonth[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y = y - (m < 3);
    return (y + (y/4) - (y/100) + (y/400) + jMonth[m-1] + d) % 7; 
}


int isLeapYear(int year){
    return (((year % 4 == 0) &&  (year % 100 != 0)) || ((year % 100 == 0 && year % 400 == 0)));
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
    if(((Date.Day < 1) || (Date.Day > isDay) || (Date.Year < 1)) == 0){
        Date.WeekDay = dayOfWeek(Date.Day, Date.Month, Date.Year);
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
    }
    return isDateValid(*dateptr);
}


void getDate(char *prompt, sDate *dateptr){
    char in[20];
    dateptr = calloc(1, sizeof(sDate));

    if(dateptr != NULL){
        do{
            printf(prompt);
            scanf("%s", in);
            clearBuffer();
        }while(getDateFromString(in, dateptr) != 1);
        Calendar[countAppointments].Date = *dateptr;
    }
    else{
        printf("Kein Speicher vorhanden. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'. Sie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
        enter(2);
        waitForEnter("Zum Fortfahren druecken Sie die Eingabetaste...");
    }
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
    }
    return isTimeValid(*timeptr);
}


int isTimeValidLite(sTime Time){
    int isHourValid = (Time.Hour >= 0);
    int isMinuteValid = (Time.Minute >= 0) && (Time.Minute <= 60);
    int isSecondValid = (Time.Second >= 0) && (Time.Second <= 60);

    return (isHourValid && isMinuteValid && isSecondValid);
}


int getTimeFromStringLite(char in[20], sTime *timeptr){
    int counter = 0;
    int j = 0;
    char seperate = ":";
    char read[20];

    for(int i = 0;counter<3;i++){
        if(counter == seperate || counter == NULL){
            if(counter == 0) timeptr->Hour = atoi(read);
            else if(counter == 1) timeptr->Minute = atoi(read);
            else if(counter == 2) timeptr->Second = atoi(read);

            counter ++;
            j = 0;
        }
        else{
            read[j] = in[i];
            read[j+1] = '\0';
            j++;
        }
    }
    return isTimeValidLite(*timeptr);
}

void getTime(char *prompt, sTime *timeptr){
    char in[20];
    timeptr = calloc(1, sizeof(sTime));

    if(timeptr != NULL){
        do{
            printf(prompt);
            scanf("%s", in);
            clearBuffer();
        }while(getTimeFromString(in, timeptr) != 1);
        Calendar[countAppointments].Time = *timeptr;
    }
    else{
        printf("Kein Speicher vorhanden. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'. Sie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
        enter(2);
        waitForEnter("Zum Fortfahren druecken Sie die Eingabetaste...");
    }
}