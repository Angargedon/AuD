#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "datetime.h"
#include "calendar.h"

void saveAppointment(FILE *Datei, int selectAppointment){

    fprintf(Datei, "%s" "%s", "<Appointment>", "\n");
    fprintf(Datei, "%s" "%02i.%02i.%04i" "%s" "%s", "<Date>", Calendar[selectAppointment].Date.Day, Calendar[selectAppointment].Date.Month, Calendar[selectAppointment].Date.Year, "<\\Date>", "\n");
    fprintf(Datei, "%s" "%02i:%02i" "%s" "%s", "<Time>", Calendar[selectAppointment].Time.Hour, Calendar[selectAppointment].Time.Minute, "<\\Time>", "\n");
    if(Calendar[selectAppointment].Lenght)
        fprintf(Datei, "%s" "%02i:%02i:%02i" "%s" "%s", "<Duration>", Calendar[selectAppointment].Lenght->Hour, Calendar[selectAppointment].Lenght->Minute, Calendar[selectAppointment].Lenght->Second, "<\\Duration>", "\n");
    fprintf(Datei, "%s" "%s" "%s" "%s", "<Description>", Calendar[selectAppointment].Description, "<\\Description>", "\n");
    if(Calendar[selectAppointment].Location)
        fprintf(Datei, "%s" "%s" "%s" "%s", "<Location>", Calendar[selectAppointment].Location, "<\\Location>", "\n");
}



int saveCalendar(){
    FILE *Datei = NULL;

    Datei = fopen("A:\\Dokumente\\BHT\\WiSe2324\\AuD\\ueb04\\calendar.xml", "wt");
    if(Datei){
        int i = 0;

        fprintf(Datei, "%s" "%s", "<Datei>", "\n");
        for(i; i<countAppointments; i++){
            saveAppointment(Datei, i);
        }
        fclose(Datei);
        return 1;
    }
    else{
        waitForEnter("\nFehler beim Speichern: Die Datenbank konnte nicht gefunden werden. Bitte Eingabetaste druecken\n");
        return 0;
    }
}


int loadCalendar(){}


int loadAppointment(){}