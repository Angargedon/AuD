#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "calendar.h"

void saveAppointment(FILE *Datei, int selectAppointment){

    fprintf(Datei, "%s" "%s", " <Appointment>", "\n");

    fprintf(Datei, "%s" "%02i.%02i.%04i" "%s" "%s", "  <Date>", Calendar[selectAppointment].Date.Day, Calendar[selectAppointment].Date.Month, Calendar[selectAppointment].Date.Year, "</Date>", "\n");
    fprintf(Datei, "%s" "%02i:%02i" "%s" "%s", "  <Time>", Calendar[selectAppointment].Time.Hour, Calendar[selectAppointment].Time.Minute, "</Time>", "\n");
    if(Calendar[selectAppointment].Lenght->Hour) fprintf(Datei, "%s" "%02i:%02i:%02i" "%s" "%s", "  <Lenght>", Calendar[selectAppointment].Lenght->Hour, Calendar[selectAppointment].Lenght->Minute, Calendar[selectAppointment].Lenght->Second, "</Lenght>", "\n");
    fprintf(Datei, "%s" "%s" "%s" "%s", "  <Description>", Calendar[selectAppointment].Description, "</Description>", "\n");
    if(Calendar[selectAppointment].Location) fprintf(Datei, "%s" "%s" "%s" "%s", "  <Location>", Calendar[selectAppointment].Location, "</Location>", "\n");

    fprintf(Datei, "%s %s", " </Appointment>", "\n");
}



int saveCalendar(){
    FILE *Datei = NULL;

    Datei = fopen("A:\\Dokumente\\BHT\\WiSe2324\\AuD\\ueb04\\calendar.xml", "wt");
    if(Datei){
        int i;

        fprintf(Datei, "%s" "%s", "<Calendar>", "\n");
        for(i = 0; i<= countAppointments; i++){
            saveAppointment(Datei, i);
        }
        fprintf(Datei, "%s", "</Calendar>");
        fclose(Datei);
        return 1;
    }
    else{
        return 0;
    }
}


int loadCalendar(){
    char row[101];
    char *ptrRow;
    FILE *Datei = NULL;

    Datei = fopen("A:\\Dokumente\\BHT\\AuD\\ueb04\\calendar.xml", "rt");
    if(Datei){
        do{
            fscanf(Datei, "%100[^\n]", row);
            fclearBuffer(Datei);
            ptrRow = row;

            while((row != " ") || (row != 9))
                ptrRow++;

            if(strncmp(ptrRow, "<Appointment>", 13) == 0){
                if(countAppointments < MAXAPPOINTMENTS){
                    loadAppointment(Datei, countAppointments);
                    countAppointments++;
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


int loadAppointment(FILE *Datei, int selectAppointment){
    char row[101];
    char *ptrRow = row;

    do{
        fscanf(Datei, "%100[^\n]", row);
        fclearBuffer(Datei);
        ptrRow = row;
        while((*ptrRow == ' ') || (*ptrRow == 9))
            ptrRow++;
    }while(strncmp(ptrRow, "</Appointment>", 14));
}