#include <stdio.h>
#include "tools.h"

void createAppointment(){
    enter(1);
    printf("Termin erstellen");
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