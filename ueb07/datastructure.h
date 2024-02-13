#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#define MAXINDEX 307

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
    int ID;
}sAppointment;

typedef struct sLE{
    sAppointment *Appointment;
    struct sLE *Next;
}sListEntry;

typedef struct{
    sListEntry *first;
    sListEntry *last;
}sHashEntry;

extern sHashEntry AppIndex[MAXINDEX];
extern sAppointment *First, *Last;

#endif