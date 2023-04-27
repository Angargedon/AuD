#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "invoice.h"

int main(){
    char title[] = "Rechnungsmanaga V0.2";
    char *menus[6] = {"Neue Rechnung anlegen", "Rechnung loeschen", "Artikel suchen", "Rechnungen sortieren", "Rechnungen auflisten", "Programm beenden"};

    int choosedMenu = 0;
    do{
        choosedMenu = getMenu(title, menus, 6);
        switch(choosedMenu){

            case 1: createInvoice();break;
            case 2: deleteInvoice();break;
            case 3: searchArticle();break;
            case 4: sortInvoices();break;
            case 5: listInvoices();break;
            case 6: printf("Programm wird beendet...");enter(1); break;
        }
    }while (choosedMenu != 6);

    return 0;
}
