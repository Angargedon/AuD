#ifndef LIST_H
#define LIST_H
#include "datastructure.h"


void insertInDList(sAppointment *New, int (*compare) (sAppointment *, sAppointment *));


sAppointment *removeFromDList(sAppointment *Remove, int (*compare) (sAppointment *, sAppointment *));


sAppointment *getFirstElement();


sAppointment *getLastElement();


int appendInSList(sListEntry *newApp);


sListEntry *removeFromSList(sAppointment *remApp);


#endif