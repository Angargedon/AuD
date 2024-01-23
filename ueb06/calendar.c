#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "menu.h"
#include "datetime.h"
#include "database.h"
#include "sort.h"
#include "list.h"

void createAppointment(){
    int check = 1;

    sAppointment *Create = malloc(sizeof(sAppointment));
    if(Create != NULL){
        while(check == 1){
            enter(1);
            printf("Termin erstellen");
            enter(2);
            check = getDate("Datum: ", &(Create->Date));
            check = getTime("Uhrzeit(Std:Min): ", &(Create->Time));
            check = getDuration("Dauer(Std:Min:Sek): ", &(Create->Lenght));
            check = getText("Terminbeschreibung: ", 100, &(Create->Description), 0);
            check = getText("Ort: ", 15, &(Create->Location), 1);
            enter(1);
            check = 2;
        }
    
        if(check == 2){
            insertInDList(Create, sort_DateTime);
            check = saveCalendar();
            if(check == 1){
                waitForEnter("Termin wurde erstellt\n\nDruecken Sie die Eingabetaste...");
            }
            else{
                printf("Speichern fehlgeschlagen. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
                enter(1);
                waitForEnter("Eingabetaste zum Fortfahren druecken");
            }
        }
        else{
            printf("Speichern fehlgeschlagen. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
            enter(1);
            waitForEnter("Eingabetaste zum Fortfahren druecken..");
        }
        free(Create);
    }
    else{
        printf("Speichern nicht moeglich. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
            enter(1);
            waitForEnter("Eingabetaste zum Fortfahren druecken..");
    }
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



void listAppointment(sAppointment *List, int withDate){
    char *weekday;
    sTime endTime = addTime(&(List->Time), &(List->Lenght));

    if (withDate)
    {
        if(List->Date.WeekDay == 0) weekday = "Sonntag";
        else if(List->Date.WeekDay == 1) weekday = "Montag";
        else if(List->Date.WeekDay == 2) weekday = "Dienstag";
        else if(List->Date.WeekDay == 3) weekday = "Mittwoch";
        else if(List->Date.WeekDay == 4) weekday = "Donnerstag";
        else if(List->Date.WeekDay == 5) weekday = "Freitag";
        else if(List->Date.WeekDay == 6) weekday = "Samstag";
        
        printLine('=', 100);
        
        enter(1);
        printf("%s, ", weekday);
        printDate(&(List->Date));
        printf(":");
        enter(2);
    }

    printTime(&(List->Time));
    printf("Uhr - ");
    printTime(&endTime);
    printf("Uhr | ");

    if(List->Location == NULL) printLine(' ', 20);
    else{
        printf(List->Location);
        printLine(' ', (20 - strlen(List->Location)));
    }

    printf("| %s", List->Description);
    enter(1);

}


void listCalendar(){
    sDate prevDate = {0, 0, 0, 0};
    int withDate;
    sAppointment *List = NULL;
    #define LISTLENGHT 15

    List = getFirstElement();
    if(List == NULL){
        if(askYesOrNo("Keine Termine vorhanden. Neuen Termin erstellen?[j/n]: "))
            createAppointment();
    }
    else{
        enter(1);
        title("Kalender auflisten", '-');
        enter(2);
        while(List){
                int count = 0;

            withDate = ((List->Date.Year != prevDate.Year) || (List->Date.Month != prevDate.Month) || (List->Date.Day != prevDate.Day));
            if (withDate)
                prevDate = List->Date;
            listAppointment(List, withDate);
            count ++;
            List = List->Next;

            if(count == LISTLENGHT){
                waitForEnter("Druecken Sie die Eingabetase...");
                count = 0;
            }
        }
        enter(1);
        waitForEnter("Druecken Sie die Eingabetaste...");
    }
}