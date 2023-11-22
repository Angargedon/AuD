#include <stdio.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"

int countAppointments = 0;
sAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment(){
    sDate *Date;

    enter(1);
    printf("Termin erstellen");
    enter(2);
/*NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCHEN NACHHER LOESCEN*/
    getDate("Datum: ", Date);
    enter(2);
    printf("Tag: %i\nMonat: %i\n Jahr: %i", Date->Day, Date->Month, Date->Year);
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
