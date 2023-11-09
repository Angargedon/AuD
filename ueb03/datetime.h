#ifndef DATETIME_H
#define DATETIME_H
#include "datastructure.h"

/********************************************
 * Checks if the 'int year' is a leap year  
********************************************/
int isLeapYear(int year);

/********************************************
 * Checks if the date from                  
 * 'getDateFromString' is valid, checking   
 * also including 'isLeapYear'              
 ********************************************/
int isDateValid(sDate date);

/********************************************
 * 'char in[]' is the date input while      
 * 'sdate *dateptr' is the pointer in which 
 * the date gets set, so 'Day', 'Month' and 
 * 'Year' get their values from the input.  
 *******************************************/
int getDateFromString(char in[],sDate *dateptr);

/********************************************
 * Same as 'isDateValid', 'isTimeValid'     
 * checks, if the time from                  
 * 'getTimeFromString' is the correct       
 * clocktime(uses german clock 0Uhr - 24Uhr)
********************************************/
int isTimeValid(sTime time);

/********************************************
 * Same as 'getDateFromString' but for time,
 * 'getTimeFromString' is seperating the    
 * hour, minute and second value from the   
 * input that is 'char[in]'.                
 * 'sTime *timeptr' is the pointer that will
 * set the hour, minute and second values to
 * the datastructure after the input got    
 * read(uses german clock 0Uhr - 23:59Uhr)  
 *******************************************/
int getTimeFromString(char in[],sTime *timeptr);

/********************************************
 * It's 'isTimeValid' but it allows the     
 * time to get more than 24 hours. Will be  
 * connected with 'getTimeFromStringLite'    
 ********************************************/
int isTimeValidLite(sTime time);

/********************************************
 * It's 'getTimeFromString' but it allows   
 * the time to get more than 24 hours. Uses 
 * 'isTimeValidLite' and get's used if the  
 * time has to be a amount/lenght instead of
 * a clock                                  
********************************************/
int getTimeFromStringLite(char in[],sTime *timeptr);
#endif