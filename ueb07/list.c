#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "sort.h"
#include "search.h"

sAppointment *First = NULL, *Last = NULL;

void insertInDList(sAppointment *New, int (*compare) (sAppointment *, sAppointment *)){
    sAppointment *tmp = First;

    if(New){
        if(First == NULL){
            First = Last = New;
        }
        else if(compare(First, New) >= 0){
            New->Next = First;
            First = First->Prev = New;
        }
        else if(compare(Last, New) <= 0){
            New->Prev = Last;
            Last = Last->Next = New;
        }
        else{
            while(tmp->Next){
                if(compare(tmp->Next, New) > 0){
                    New->Prev = tmp;
                    New->Next = tmp->Next;
                    tmp->Next = tmp->Next->Prev = New;
                    break;
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


int appendInSList(sAppointment *newApp){
    sListEntry *newList = malloc(sizeof(sListEntry));
    int Index;

    if(newApp && newList){
        Index = calcDivisionRest(newApp->Description);

        if(AppIndex[Index].first == NULL){
            AppIndex[Index].first = AppIndex[Index].last = newList;
            newList->Appointment = newApp;
            return 1;
        }
        else{
            AppIndex[Index].last = AppIndex[Index].last->Next = newList;
            newList->Appointment = newApp;
            return 1;
        }
    }
    else{
        return 0;
    }    
}


sListEntry *removeFromSList(sAppointment *remApp){
    int Index = calcDivisionRest(remApp->Description);
    sListEntry *tmp = AppIndex[Index].first, *remList = NULL;

    if(remApp){

        if(AppIndex[Index].first == NULL)
            return NULL;
        else if(remApp == AppIndex[Index].first->Appointment){
            remList = AppIndex[Index].first;
            AppIndex[Index].first = AppIndex[Index].first->Next;
            
            if(AppIndex[Index].first== NULL)
                AppIndex[Index].last = NULL;
        }
        else{
            while(tmp){
                if(tmp->Next->Appointment == remApp){
                    remList = tmp->Next;

                    if(tmp->Next == AppIndex[Index].last){
                        AppIndex[Index].last = tmp;
                        tmp->Next = NULL;
                        break;
                    }
                    else{
                        tmp->Next = remList->Next;
                        remList->Next = NULL;
                        break;
                    }
                }
                tmp = tmp->Next;
            }
        }
        
        return remList;
    }
    else{
        return NULL;
    }
}