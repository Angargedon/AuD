#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXAPPOINTMENTS 100

typedef enum {NotADay, Mo, Di, Mi, Do, Fr, Sa, So} eDayofTheWeek;

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

typedef struct{
    sDate Date;
    sTime Time;
    char *Description;
    char *Location;
    sTime *Lenght;
}sAppointment;

extern int countAppointments;
extern sAppointment Calendar[];

#endif // DATASTRUCTURE_H_INCLUDED
