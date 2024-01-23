#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"


void insertInDList(sAppointment *New, int (*compare) (sAppointment *, sAppointment *)){
    sAppointment *tmp = First;

    if(New){
        if(First == NULL){
            First = Last = New;
        }
        else if(compare(First, New) <= 0){
            New->Next = First;
            First = First->Prev = New;
        }
        else if(compare(Last, New) >= 0){
            New->Prev = Last;
            Last = Last->Next = New;
        }
        else{
            while(tmp->Next){
                if(compare(tmp->Next, New) > 0){
                    New->Prev = tmp;
                    New->Next = tmp->Next;
                    tmp->Next = tmp->Next->Prev = New;
                }
                tmp = tmp->Next;
            }
        }
    }
}


sAppointment *removeFromDList(sAppointment *Remove, int (*compare) (sAppointment *, sAppointment *)){
    sAppointment *tmp = First, *rmv = NULL;

    if(Remove){
        if(First == NULL)
            return NULL;
        else if(compare(First, Remove) == 0){
            rmv = First;
            First = First->Next;
            if(First == NULL)
                Last = NULL;
            else
                First->Prev = NULL;
        }
        else if(compare(Last, Remove) == 0){
            rmv = Last;
            Last = Last->Prev;
            Last->Next = NULL;
        }
        else{
            while(tmp->Next){
                if(compare(tmp->Next, Remove) == 0){
                    rmv = tmp->Next;
                    tmp->Next = rmv->Next;
                    tmp->Next->Prev = tmp;
                    break;
                }
                tmp = tmp->Next;
            }
        }
    }
    return rmv;
}


sAppointment *getFirstElement(){
    return First;
}


sAppointment *getLastElement(){
    return Last;
}