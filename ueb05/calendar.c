#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "menu.h"
#include "datetime.h"
#include "database.h"
#include "sort.h"

void createAppointment(){
    int check = 1;
    sAppointment *Create;

    while(check == 1){
        enter(1);
        printf("Termin erstellen");
        enter(2);
        check = getDate("Datum: ", &(Create->Date));
        check = getTime("Uhrzeit(Std:Min): ", &(Create->Time));
        check = getDuration("Dauer(Std:Min:Sek): ", &(Create->Lenght));
        check = getText("Terminbeschreibung: ", 100, &(Calendar[countAppointments].Description), 0);
        check = getText("Ort: ", 15, &(Calendar[countAppointments].Location), 1);
        enter(1);
        check = 2;
    }
    if(check == 2){
        if(saveCalendar()){
        countAppointments++;
        waitForEnter("Termin wurde erstellt\n\nDruecken Sie die Eingabetaste...");
        }
        else{
            printf("Speichern fehlgeschlagen. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud");
            enter(1);
            waitForEnter("Eingabetaste zum Fortfahren druecken..");
        }
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


void sortCalendar(){
    int choosedPoint = 0;
    char *sortOptions[] = {"Datum und Uhrzeit", "Beschreibung", "Ort", "Dauer", "Zurueck zum Hauptmenu"};

    do{
        choosedPoint = getMenu("Kalendar sortieren nach:", sortOptions, 5);

        switch(choosedPoint){
            case 1:
                QuickSort(Calendar, countAppointments, sort_DateTime);
                waitForEnter("Sortieren erfolgreich. Druecken Sie die Eingabetase...");
                break;
            case 2:
                QuickSort(Calendar, countAppointments, sort_Description);
                waitForEnter("Sortieren erfolgreich. Druecken Sie die Eingabetase...");
                break;
            case 3:
                QuickSort(Calendar, countAppointments, sort_Location);
                waitForEnter("Sortieren erfolgreich. Druecken Sie die Eingabetase...");
                break;
            case 4:
                QuickSort(Calendar, countAppointments, sort_Duration);
                waitForEnter("Sortieren erfolgreich. Druecken Sie die Eingabetase...");
                break;
            case 5:
                break;
        }
    }while(choosedPoint < 1 || choosedPoint > 5 );
}


void listAppointment(int i, int withDate){
    char *weekday;
    sTime endTime = addTime(&(Calendar[i].Time), &(Calendar[i].Lenght));

    if (withDate)
    {
        if(Calendar[i].Date.WeekDay == 0) weekday = "Sonntag";
        else if(Calendar[i].Date.WeekDay == 1) weekday = "Montag";
        else if(Calendar[i].Date.WeekDay == 2) weekday = "Dienstag";
        else if(Calendar[i].Date.WeekDay == 3) weekday = "Mittwoch";
        else if(Calendar[i].Date.WeekDay == 4) weekday = "Donnerstag";
        else if(Calendar[i].Date.WeekDay == 5) weekday = "Freitag";
        else if(Calendar[i].Date.WeekDay == 6) weekday = "Samstag";
        
        printLine('=', 100);
        
        enter(1);
        printf("%s, ", weekday);
        printDate(&(Calendar[i].Date));
        printf(":");
        enter(2);
    }

    printTime(&(Calendar[i].Time));
    printf("Uhr - ");
    printTime(&endTime);
    printf("Uhr | ");

    if(Calendar[i].Location == NULL) printLine(' ', 20);
    else{
        printf(Calendar[i].Location);
        printLine(' ', (20 - strlen(Calendar[i].Location)));
    }

    printf("| %s", Calendar[i].Description);
    enter(1);

}


void listCalendar(){
    int i;
    sDate prevDate = {0, 0, 0, 0};
    int withDate;
    #define LISTLENGHT 15

    if(countAppointments == 0){
        if(askYesOrNo("Keine Termine vorhanden. Neuen Termin erstellen?[j/n]: "))
            createAppointment();
    }
    else{
        enter(1);
        title("Kalender auflisten", '-');
        enter(2);
        for(i = 0; i < countAppointments; i++){
                int count = 0;

            withDate = ((Calendar[i].Date.Year != prevDate.Year) || (Calendar[i].Date.Month != prevDate.Month) || (Calendar[i].Date.Day != prevDate.Day));
            if (withDate)
                prevDate = Calendar[i].Date;
            listAppointment(i, withDate);
            count ++;

            if(count == LISTLENGHT){
                waitForEnter("Druecken Sie die Eingabetase...");
                count = 0;
            }
        }
        enter(1);
        waitForEnter("Druecken Sie die Eingabetaste...");
    }
}