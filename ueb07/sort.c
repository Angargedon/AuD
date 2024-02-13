#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "datastructure.h"
#include "tools.h"

int sort_DateTime(sAppointment *A1, sAppointment *A2){
    if (A1->Date.Year - A2->Date.Year == 0)
    {
        if (A1->Date.Month - A2->Date.Month == 0)
        {
            if(A1->Date.Day - A2->Date.Day == 0)
            {
                if(A1->Time.Hour - A2->Time.Hour == 0)
                {
                    if(A1->Time.Minute - A2->Time.Minute == 0)
                        return 0;
                    else
                        return A1->Time.Minute - A2->Time.Minute;
                }
                else
                    return A1->Time.Hour - A2->Time.Hour;
            }
            else
                return A1->Date.Day - A2->Date.Day;
        }
        else
            return A1->Date.Month - A2->Date.Month;
    }
    else
        return A1->Date.Year - A2->Date.Year;

}


int sort_Char(char *C1, char *C2){
    if (C1 == C2)
        return 0;
    else if(C1 == C2)
        return 1;
    else if (C1 == C2)
        return -1;
    else
        return strcmp(C1, C2);
}


void swapAppointment(sAppointment *e1, sAppointment *e2)
{
    sAppointment temp;

    temp.Date.Day = e1->Date.Day;
    temp.Date.Month = e1->Date.Month;
    temp.Date.Year = e1->Date.Year;
    temp.Date.WeekDay = e1->Date.WeekDay;

    temp.Time.Hour = e1->Time.Hour;
    temp.Time.Minute = e1->Time.Minute;
    temp.Time.Second = e1->Time.Second;

    temp.Description = e1->Description;

    temp.Lenght.Hour = e1->Lenght.Hour;
    temp.Lenght.Minute = e1->Lenght.Minute;
    temp.Lenght.Second = e1->Lenght.Second;

    temp.Location = e1->Location;

    e1->Date.Day = e2->Date.Day;
    e1->Date.Month = e2->Date.Month;
    e1->Date.Year = e2->Date.Year;
    e1->Date.WeekDay = e2->Date.WeekDay;

    e1->Time.Hour = e2->Time.Hour;
    e1->Time.Minute = e2->Time.Minute;
    e1->Time.Second = e2->Time.Second;

    e1->Description = e2->Description;

    e1->Lenght.Hour = e2->Lenght.Hour;
    e1->Lenght.Minute = e2->Lenght.Minute;
    e1->Lenght.Second = e2->Lenght.Second;

    e1->Location = e2->Location;
    
    e2->Date.Day = temp.Date.Day;
    e2->Date.Month = temp.Date.Month;
    e2->Date.Year = temp.Date.Year;
    e2->Date.WeekDay = temp.Date.WeekDay;

    e2->Time.Hour = temp.Time.Hour;
    e2->Time.Minute = temp.Time.Minute;
    e2->Time.Second = temp.Time.Second;

    e2->Description = temp.Description;

    e2->Lenght.Hour = temp.Lenght.Hour;
    e2->Lenght.Minute = temp.Lenght.Minute;
    e2->Lenght.Second = temp.Lenght.Second;

    e2->Location = temp.Location;
}

int partitionAppointment(sAppointment *A, int ui, int oi, int (*compare)(sAppointment *, sAppointment *)){
    sAppointment *comp = A + ui;
    int i = ui, j = oi;
    while (i <= j){
        while ( (i <= j) && (compare(A + i, comp) <= 0) )
            i++;
        while ( (j >= i) && (compare(A + j, comp) >= 0) )
            j--;
        if (i < j){
            swapAppointment(A + i, A + j);
            i++;
            j--;
        }
    }
    i--;
    swapAppointment(comp, A + j);
    
    return i;
}

void QSortAppointment(sAppointment *A, int ui, int oi, int (*compare)(sAppointment*, sAppointment*)) {
    int idx;

    if (ui >= oi)
        return;
    else
    {
        idx = partitionAppointment(A, ui, oi, compare);
        QSortAppointment(A, ui, idx - 1, compare);
        QSortAppointment(A, idx + 1, oi, compare);
    }
}


void QuickSort(sAppointment *Array, int Anzahl, int (*cmpfct) (sAppointment *, sAppointment *)){
    QSortAppointment(Array, 0, Anzahl -1, cmpfct);
}