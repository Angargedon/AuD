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
    int check = 0;

    sAppointment *Create = malloc(sizeof(sAppointment));
    if(Create != NULL){
        enter(1);
        printf("Termin erstellen");
        enter(2);
        if(getDate("Datum: ", &(Create->Date))){
            if(getTime("Uhrzeit[Std:Min]: ", &(Create->Time))){
                if(getDuration("Dauer[Std:Min:Sek]: ", &Create->Lenght)){
                    if(getText("Terminbeschreibung: ", 100, &Create->Description, 0)){
                        if(getText("Ort: ", 15, &Create->Location, 1))
                            check = 1;
                    }
                }
            }
        }
        enter(1);
    
        if(check == 1){
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
        //free(Create);
    }
    else{
    //    free(Create);
        printf("Speichern nicht moeglich. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
        enter(1);
        waitForEnter("Eingabetaste zum Fortfahren druecken..");
    }
}


void editAppointment(){
    enter(1);
    printf("Termin bearbeiten");
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste..");
}


void deleteAppointment(){
    clearScreen();
    sAppointment *Delete = NULL;
    sAppointment *Check = NULL;
    int i = 0;
    int chooseID = 0;
    char *weekday = NULL;

    printf("Termin entfernen");
    enter(2);
    Delete = getFirstElement();
    
    while(Delete != NULL){
        if(Delete->Date.WeekDay == 0) weekday = "Sonntag";
        else if(Delete->Date.WeekDay == 1) weekday = "Montag";
        else if(Delete->Date.WeekDay == 2) weekday = "Dienstag";
        else if(Delete->Date.WeekDay == 3) weekday = "Mittwoch";
        else if(Delete->Date.WeekDay == 4) weekday = "Donnerstag";
        else if(Delete->Date.WeekDay == 5) weekday = "Freitag";
        else if(Delete->Date.WeekDay == 6) weekday = "Samstag";
        i++;
        Delete->ID = i;

        printf("%i. %s, ", Delete->ID, weekday);
        printDate(&(Delete->Date));        
        printf(" | ");
        printTime(&(Delete->Time));
        printf("Uhr| %s", Delete->Description);
        if(Delete->Location)
            printf(" in %s", Delete->Location);

        Delete = Delete->Next;
        enter(1);
    }
    enter(1);

    Delete = getFirstElement();
    Check = getLastElement();

    do{
    printf("Waehlen Sie den zu loeschenden Termin aus('0' fuer Abbruch auswaehlen): ");
    scanf("%i", &chooseID);
    clearBuffer();
    }while(chooseID < 0 && chooseID > Check->ID);

    if(chooseID != 0){
        while(Delete != NULL){
            if(Delete->ID == chooseID){
                free(removeFromDList(Delete, sort_DateTime));
                saveCalendar();
                break;
            }
            else
                Delete = Delete->Next;
        }
    waitForEnter("Druecken Sie die Eingabetaste..");
    }
}


void searchAppointment(){
    enter(1);
    printf("Termin suchen");
    enter(2);
    waitForEnter("Druecken Sie die Eingabetaste..");
}



void listAppointment(sAppointment *List, int withDate){
    char *weekday = NULL;
    sTime endTime = addTime(&(List->Time), &(List->Lenght));

    if(withDate)
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
    sAppointment *List = NULL;
    int withDate;
    int counter = 0;

    List = getFirstElement();

    clearScreen();

    if(List == NULL){
        if(askYesOrNo("Keine Termine vorhanden. Termin erstellen?[j/n]: "))
            createAppointment();
    }
    else{
        sAppointment *prev = NULL;

        withDate = (prev == NULL || (List->Date.Day != prev->Date.Day || List->Date.Month != prev->Date.Month || List->Date.Year != prev->Date.Year));
        listAppointment(List, withDate);
        prev = List;
        List = List->Next;

        while(List != NULL){
            withDate = (prev == NULL || (List->Date.Day != prev->Date.Day || List->Date.Month != prev->Date.Month || List->Date.Year != prev->Date.Year));
            listAppointment(List, withDate);
            prev = List;
            List = List->Next;
            if(counter >= 15){
                waitForEnter("Druecken Sie die Eingabetaste fuer die naechste Seite..");
            }
        }

        enter(2);
        waitForEnter("Druecken sie zum Fortfahren die Eingabetaste..");
    }
}