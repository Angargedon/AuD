#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"

int isLeapYear(int year){
    return (((year % 4 == 0) &&  (year % 100 != 0)) || ((year % 100 == 0 && year % 400 == 0)));
}

int isDateValid(sDate Date){
    int isDay;

    switch(Date.Month){
        case 1: isDay = 31; break;                                                                      //'isDay' is the value for the amount
        case 2: if(isLeapYear(Date.Year) == 1) isDay = 29; else isDay = 28; break;                      //of days the input month has.
        case 3: isDay = 31; break;                                                                      //While switch checks, which month is
        case 4: isDay = 30; break;                                                                      //chosen in the input it sets the 'isDay'
        case 5: isDay = 31; break;                                                                      //value for this month. An int truth
        case 6: isDay = 30; break;                                                                      //value gets returned in which the
        case 7: isDay = 31; break;                                                                      //if-statement checks if the value
        case 8: isDay = 31; break;                                                                      //of the input month has to be at least
        case 9: isDay = 30; break;                                                                      //1 and max. the value of 'isDay'.
        case 10: isDay = 31; break;                                                                     //If this is not the case, the function
        case 11: isDay = 30; break;                                                                     //returns 0, telling that the date is
        case 12: isDay = 31;break;                                                                      //invalid.
        default: isDay = 0;
    }
    if(((Date.Day < 1) || (Date.Day > isDay) || (Date.Year < 1)) == 0) return 1;
    else return 0;
}

int getDateFromString(char *in, sDate *dateptr){                         //While 'counter' is for counting the delimiter in the date
    int counter = 0;                                                        //('.' or '\n'), 'j' on the other hand is another helper like i is.
    int j = 0;                                                              //The for-statement goes as long as the input arrays length is (20).
    char point = '.';                                                       //In this, there is an if-else-statement in which the else-statement
    char read[20];                                                          //has 'read[j]' and 'in[i]'. If there is a '.' or '\n'/'NULL' then
                                                                            //in the next turn of the for-statement the if-command gets
    for(int i = 0;counter<3;i++){                                           //turned on and decides by the counter, if the number is the day,
        if(in[i] == point || in[i] == NULL){                                //the month or the year.
            if(counter == 0) dateptr->Day = atoi(read);                     //For example the input is 1.3.2000, first the 1 gets read by
            else if(counter == 1) dateptr->Month = atoi(read);              //'read[j] = in[i]' in the else-statement. After that the second
            else if(counter == 2) dateptr->Year = atoi(read);               //for-loop comes in action, where the if-statement comes in action
                                                                            //because the 'in[i]' has '.' as value. The value of 'counter' is 0,
            counter++;                                                      //telling that the value of 'read' gets assigned for the 'Day' value
            j = 0;                                                          //of the sDate-structure. 'j' gets the value 0, so that 'read[j]'
        }                                                                   //gets a reset. The value of 'counter' gets added by 1, so that in
        else{                                                               //the next time in that if-statement the value which get read now,
            read[j] = in[i];                                                //can be assigned to the month. And then if the next '.' is reached
            read[j+1] = '\0';                                               //the if-statement gets repeated but the value assigned to month,
            j++;                                                            //'counter' again added by 1 so in the next loop where the
        }                                                                   //if-statement comes in action, the new value of 'read' can get
    }                                                                       //assigned to 'Year'.
    return isDateValid(*dateptr);
}

void getDate(char *Text, sDate *Date){
    char *in = NULL;

    do{
        printf("%s", Text);
        scanf("%s", in);
        clearBuffer();
    }while(getDateFromString(&in, Date) != 1);
}

int isTimeValid(sTime Time){
    int isHourValid = (Time.Hour >= 0) && (Time.Hour <= 23);
    int isMinuteValid = (Time.Minute >= 0) && (Time.Minute <= 60);

    return (isHourValid && isMinuteValid);
}

int getTimeFromString(char in[10], sTime *timeptr){
    int counter = 0;
    int j = 0;
    char seperate = ':';
    char read[10];

    for(int i = 0;counter<2;i++){
        if(counter == seperate || counter == NULL){
            if(counter == 0) timeptr->Hour = atoi(read);
            else if(counter == 1) timeptr->Minute = atoi(read);

            counter ++;
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
    char seperate = ':';
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
