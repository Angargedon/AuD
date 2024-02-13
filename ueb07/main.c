#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "database.h"


int main(){
    int menuChoice = 0;
    loadCalendar();
    
    do{
        char *menuTitle[] = {"Termin erstellen", "Termin bearbeiten", "Termin entfernen", "Termin suchen", "Terminne auflisten", "Programm beenden"};
        menuChoice = getMenu("ULTIMATIVE TERMINERSTELLUNGSSOFTWARE V1.0", menuTitle, 6);


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
    return 0;
}