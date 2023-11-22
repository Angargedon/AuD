#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

enum eDayOfWeek{NotADay, Mo, Di, Mi, Do, Fr, Sa, So};

#define MAXAPPOINTMENTS 100

typedef struct{
    int Day;
    int Month;
    int Year;
    int eDayOfWeek;
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
    sTime Lenght;
}sAppointment;

int countAppointments;
sAppointment Calendar[MAXAPPOINTMENTS];

#endif