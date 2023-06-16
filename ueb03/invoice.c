#include <stdio.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"

int InvoiceCounter = 0;
sInvoice *Invoice = NULL;

void createInvoice(){
    sInvoice *NewInvoice;
    char *DateIn = NULL;
    int DateCheck = 0;

    clearScreen();
    if(NewInvoice){
        NewInvoice->ArticleCounter = 0;
        getText("Name des Kunden: ", 50, &(NewInvoice->Costumer), 0);

        do{
            getText("Rechnungsdatum: ", 50, &DateIn, 1);
            DateCheck = getDateFromString(DateIn,&(NewInvoice->Date));
        }while(!DateCheck);

        do{
            if(NewInvoice->ArticleCounter < MAXARTICLE)
                createArticle(NewInvoice);
        }while(askYesOrNo("Einen weiteren Artikel eingeben(j/n)?: "));
        clearScreen();
    }
}

static void createArticle(sInvoice *NewInvoice){
    sArticle *NewArticle = NewInvoice->Article + NewInvoice->ArticleCounter;

    getText("Artikelbezeichnung: ", 50, &(NewArticle->Description), 0);
    getNumber("Menge: ", &(NewArticle->Amount), 0, 99);
    getFloat("Nettoeinzelpreis: ", &(NewArticle->NetPricePerUnit));

    (NewInvoice->ArticleCounter)++;
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

static void listOneInvoice(sInvoice InvoiceCounter){

}
