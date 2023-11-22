#include <stdio.h>
#include "tools.h"
#include "menu.h"
#include "calendar.h"

int main(){
    char *menuTitle[] = {"Termin erstellen", "Termin bearbeiten", "Termin entfernen", "Termin suchen", "Termine sortieren", "Terminne auflisten", "Programm beenden"};
    int menuChoice = 0;

    do{
        menuChoice = getMenu("ULTIMATIVE TERMINERSTELLUNGSSOFTWARE V0.2", menuTitle, 7);

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
                sortCalendar();
                break;
            case 6:
                listCalendar();
                break;
            case 7:
                printf("Programm wird beendet");
                break;
            case 2147483647:
                Dog();
                waitForEnter("\n\n\n");
        }
    }while(menuChoice != 7);

    return 0;
}
