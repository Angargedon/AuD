#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "calendar.h"
#include "sort.h"
#include "list.h"

void saveAppointment(FILE *Datei){

    if(Datei == NULL || Calendar == NULL){
        return;
    }

    fprintf(Datei, "%s" "%s", " <Appointment>", "\n");

    fprintf(Datei, "%s" "%02i.%02i.%04i" "%s" "%s", "  <Date>", Calendar->Date.Day, Calendar->Date.Month, Calendar->Date.Year, "</Date>", "\n");
    fprintf(Datei, "%s" "%02i:%02i" "%s" "%s", "  <Time>", Calendar->Time.Hour, Calendar->Time.Minute, "</Time>", "\n");
    if(isTimeValidLite(Calendar->Lenght)) fprintf(Datei, "%s" "%02i:%02i:%02i" "%s" "%s", "  <Lenght>", Calendar->Lenght.Hour, Calendar->Lenght.Minute, Calendar->Lenght.Second, "</Lenght>", "\n");
    fprintf(Datei, "%s" "%s" "%s" "%s", "  <Description>", Calendar->Description, "</Description>", "\n");
    if(Calendar->Location) fprintf(Datei, "%s" "%s" "%s" "%s", "  <Location>", Calendar->Location, "</Location>", "\n");

    fprintf(Datei, "%s %s", " </Appointment>", "\n");
}


int saveCalendar(){
    FILE *Datei = NULL;

    Datei = fopen("A:\\Dokumente\\BHT\\WiSe2324\\AuD\\ueb06\\calendar.xml", "wt");
    if(Datei){

        Calendar = getFirstElement();
        fprintf(Datei, "%s" "%s", "<Calendar>", "\n");
        while(Calendar != Last->Next){
            saveAppointment(Datei);
            Calendar = Calendar->Next;
        }
        fprintf(Datei, "%s", "</Calendar>");
        fclose(Datei);
        return 1;
    }
    else{
        return 0;
    }
}


int loadAppointment(FILE *Datei){
    char row[101];
    char *ptrRow = row;
    unsigned len;

    do{
        fscanf(Datei, "%100[^\n]", row);
        fclearBuffer(Datei);
        ptrRow = row;
        while((*ptrRow == ' ') || (*ptrRow == 9))
            ptrRow++;

        if(strncmp(ptrRow, "<Date>", 6) == 0){
            len = strlen(ptrRow + 6) - 7;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+6+len, "</Date>", 7) == 0)
                getDateFromString(ptrRow+6, &(Calendar->Date));
        }

        if(strncmp(ptrRow, "<Time>", 6) == 0){
            len = strlen(ptrRow + 6) - 7;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+6+len, "</Time>", 7) == 0)
                getTimeFromString(ptrRow+6, &(Calendar->Time));
        }

        if(strncmp(ptrRow, "<Description>", 13) == 0){
            len = strlen(ptrRow + 13) - 14;
            if(len > 1000)
                len = 0;
            Calendar->Description = calloc(len+1, sizeof(char));
            if(Calendar->Description != NULL)
                strncpy(Calendar->Description, ptrRow + 13, len);
            else
                return 0;
        }

        if(strncmp(ptrRow, "<Lenght>", 8) == 0){
            len = strlen(ptrRow + 8) - 9;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+8+len, "</Lenght>", 9) == 0)
                getTimeFromStringLite(ptrRow+8, &(Calendar->Lenght));
        }

        if(strncmp(ptrRow, "<Location>", 10) == 0){
            len = strlen(ptrRow + 10) - 11;
            if(len > 1000)
                len = 0;
            Calendar->Location = calloc(len+1, sizeof(char));
            if(Calendar->Location != NULL)
                strncpy(Calendar->Location, ptrRow + 10, len);
        }
    }while(strncmp(ptrRow, "</Appointment>", 14));

    return 1;
}


int loadCalendar(){
    char row[101];
    char *ptrRow;
    FILE *Datei = NULL;
    int check = 1;

    Datei = fopen("A:\\Dokumente\\BHT\\WiSe2324\\AuD\\ueb06\\calendar.xml", "rt");
    if(Datei){
        do{
            fscanf(Datei, "%100[^\n]", row);
            fclearBuffer(Datei);
            ptrRow = row;

            while((*ptrRow == ' ') || (*ptrRow == 9))
                ptrRow++;
            if (strncmp (ptrRow, "<Appointment>", 13) == 0) {
                Calendar = malloc(sizeof(sAppointment));
                if(Calendar){
                    loadAppointment(Datei);
                    insertInDList(Calendar, sort_DateTime);
                    Calendar = Calendar->Next;
                }
            }
            if(feof(Datei))
                break;
        }while(strncmp(ptrRow, "</Calendar>", 11) != 0);

        fclose(Datei);
        return 1;
    }
    else{
        printf("Keine Datenbank gefunden");
        return 0;
    }
}