#ifndef SORT_H

int sort_DateTime(sAppointment *A1, sAppointment *A2);

int sort_Description(sAppointment *A1, sAppointment *A2);

int sort_Location(sAppointment *A1, sAppointment *A2);

int sort_Duration(sAppointment *A1, sAppointment *A2);

void swapAppointment(sAppointment *a, sAppointment *b);

int partitionAppointment(sAppointment *A, int ui, int oi, int (*compare)(sAppointment *, sAppointment *));

void QSortAppointment(sAppointment *A, int ui, int oi, int (*compare)(sAppointment *, sAppointment *));

void QuickSort(sAppointment *A, int Anzahl, int (*compare) (sAppointment *, sAppointment *));
#endif