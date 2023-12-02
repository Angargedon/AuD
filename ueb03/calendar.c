#include <stdio.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"


void createAppointment(){
    sDate Date;
    sTime Time;
    sAppointment Create;

    enter(1);
    printf("Termin erstellen");
    enter(2);
/*NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCEN*/
    getDate("Datum: ", &Date);
    enter(2);
    printf("Tag: %i\nMonat: %i\nJahr: %i\nWochentag: %i\n", Calendar[countAppointments].Date.Day, Calendar[countAppointments].Date.Month, Calendar[countAppointments].Date.Year, Calendar[countAppointments].Date.WeekDay);
    waitForEnter("\n\nEnter..\n\n");
    getTime("Uhrzeit eingeben: ", &Time);
    enter(2);
    printf("Stunde: %i\nMinute: %i\n", Calendar[countAppointments].Time.Hour, Calendar[countAppointments].Time.Minute);
    enter(2);
    getText("Terminbeschreibung: ", 100, &(Create.Description), 0);
    enter(2);
    printf(Create.Description);
/*NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCEN*/
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste...");
}

void editAppointment(){
    enter(1);
    printf("Termin bearbeiten");
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste...");
}

void deleteAppointment(){
    enter(1);
    printf("Termin entfernen");
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste...");
}

void searchAppointment(){
    enter(1);
    printf("Termin suchen");
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste...");
}

void sortCalendar(){
    enter(1);
    printf("Kalender sortieren");
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste...");
}

void listCalendar(){
    enter(1);
    printf("Kalender auflisten");
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste...");
}