#include <stdio.h>
#include "datastructure.h"
#include "tools.h"

int InvoiceCounter = 0;
sInvoice Invoices[MAXINVOICES];

void createInvoice(){
    printf("Rechnung erstellen");
    enter(2);
    waitForEnter();
}

void deleteInvoice(){
    printf("Rechnung loeschen");
    enter(2);
    waitForEnter();
}

void searchArticle(){
    printf("Artikel suchen");
    enter(2);
    waitForEnter();
}

void sortInvoices(){
    printf("Rechnung sortieren");
    enter(2);
    waitForEnter();
}

void listInvoices(){
    printf("Rechnungen auflisten");
    enter(2);
    waitForEnter();
}
