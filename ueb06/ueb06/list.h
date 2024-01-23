#ifndef LIST_H
#define LIST_H


void insertInDList(sAppointment *New, int (*compare) (sAppointment *, sAppointment *));


sAppointment *removeFromDList(sAppointment *Remove, int (*compare) (sAppointment *, sAppointment *));


sAppointment *getFirstElement();


sAppointment *getLastElement();


#endif