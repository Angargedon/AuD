#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "calendar.h"
#include "sort.h"
#include "list.h"
#include "search.h"

void saveAppointment(FILE *Datei, sAppointment *saveApp){

    if(Datei == NULL || saveApp == NULL){
        return;
    }

    fprintf(Datei, "%s" "%s", " <Appointment>", "\n");

    fprintf(Datei, "%s" "%02i.%02i.%04i" "%s" "%s", "  <Date>", saveApp->Date.Day, saveApp->Date.Month, saveApp->Date.Year, "</Date>", "\n");
    fprintf(Datei, "%s" "%02i:%02i" "%s" "%s", "  <Time>", saveApp->Time.Hour, saveApp->Time.Minute, "</Time>", "\n");
    if(isTimeValidLite(saveApp->Lenght)) fprintf(Datei, "%s" "%02i:%02i:%02i" "%s" "%s", "  <Lenght>", saveApp->Lenght.Hour, saveApp->Lenght.Minute, saveApp->Lenght.Second, "</Lenght>", "\n");
    fprintf(Datei, "%s" "%s" "%s" "%s", "  <Description>", saveApp->Description, "</Description>", "\n");
    if(saveApp->Location) fprintf(Datei, "%s" "%s" "%s" "%s", "  <Location>", saveApp->Location, "</Location>", "\n");

    fprintf(Datei, "%s %s", " </Appointment>", "\n");
}


int saveCalendar(){
    FILE *Datei = NULL;
    sAppointment *Save = NULL;

    Datei = fopen("A:\\Dokumente\\BHT\\WiSe2324\\AuD\\ueb07\\calendar.xml", "wt");
    if(Datei){

        Save = getFirstElement();


        fprintf(Datei, "%s" "%s", "<Calendar>", "\n");
        while(Save != NULL){
            saveAppointment(Datei, Save);
            Save = Save->Next;
        }
        fprintf(Datei, "%s", "</Calendar>");
        fclose(Datei);
        return 1;
    }
    else{
        return 0;
    }
}


int loadAppointment(FILE *Datei, sAppointment *loadApp){
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
                getDateFromString(ptrRow+6, &(loadApp->Date));
        }

        if(strncmp(ptrRow, "<Time>", 6) == 0){
            len = strlen(ptrRow + 6) - 7;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+6+len, "</Time>", 7) == 0)
                getTimeFromString(ptrRow+6, &(loadApp->Time));
        }

        if(strncmp(ptrRow, "<Description>", 13) == 0){
            len = strlen(ptrRow + 13) - 14;
            if(len > 1000)
                len = 0;
            loadApp->Description = calloc(len+1, sizeof(char));
            if(loadApp->Description != NULL)
                strncpy(loadApp->Description, ptrRow + 13, len);
            else
                return 0;
        }

        if(strncmp(ptrRow, "<Lenght>", 8) == 0){
            len = strlen(ptrRow + 8) - 9;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+8+len, "</Lenght>", 9) == 0)
                getTimeFromStringLite(ptrRow+8, &(loadApp->Lenght));
        }

        if(strncmp(ptrRow, "<Location>", 10) == 0){
            len = strlen(ptrRow + 10) - 11;
            if(len > 1000)
                len = 0;
            loadApp->Location = calloc(len+1, sizeof(char));
            if(loadApp->Location != NULL)
                strncpy(loadApp->Location, ptrRow + 10, len);
        }
    }while(strncmp(ptrRow, "</Appointment>", 14));

    return 1;
}


int loadCalendar(){
    char row[101];
    char *ptrRow;
    FILE *Datei = NULL;
    sAppointment *Load = NULL;

    Datei = fopen("A:\\Dokumente\\BHT\\WiSe2324\\AuD\\ueb07\\calendar.xml", "rt");
    if(Datei){
        do{
            fscanf(Datei, "%100[^\n]", row);
            fclearBuffer(Datei);
            ptrRow = row;

            while((*ptrRow == ' ') || (*ptrRow == 9))
                ptrRow++;
            if (strncmp (ptrRow, "<Appointment>", 13) == 0) {
                Load = malloc(sizeof(sAppointment));
                if(Load){
                    loadAppointment(Datei, Load);
                    insertInDList(Load, sort_DateTime);
                    appendInSList(Load);
                    Load = Load->Next;
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