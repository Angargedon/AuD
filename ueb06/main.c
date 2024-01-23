#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "database.h"

sAppointment *First = NULL, *Last = NULL, *Calendar = NULL;

int main(){
    char *menuTitle[] = {"Termin erstellen", "Termin bearbeiten", "Termin entfernen", "Termin suchen", "Terminne auflisten", "Programm beenden"};
    int menuChoice = 0;
    loadCalendar();
    
    do{
        menuChoice = getMenu("ULTIMATIVE TERMINERSTELLUNGSSOFTWARE V0.3", menuTitle, 6);

        switch(menuChoice){
            case 1:
                createAppointment();
                break;
            case 2:
                editAppointment();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                searchAppointment();
                break;
            case 5:
                listCalendar();
                break;
            case 6:
                printf("Programm wird beendet");
                break;
            case 2147483647:
                Dog();
                waitForEnter("\n\n\n");
        }
    }while(menuChoice != 6);
    free(Calendar);
    return 0;
}