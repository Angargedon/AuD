#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#define MAXAPPOINTMENTS 100

typedef enum {So, Mo, Di, Mi, Do, Fr, Sa} eDayofTheWeek;

typedef struct{
    int Day;
    int Month;
    int Year;
    eDayofTheWeek WeekDay;
} sDate;

typedef struct{
    int Hour;
    int Minute;
    int Second;
}sTime;

typedef struct sALE{
    sDate Date;
    sTime Time;
    char *Description;
    char *Location;
    sTime Lenght;
    struct sALE *Next;
    struct sALE *Prev;
}sAppointment;

extern sAppointment *First, *Last, *Calendar;

#endif