#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXARTICLE 20
#define MAXINVOICES 10

typedef struct{
    int Day;
    int Month;
    int Year;
} sDate;

typedef enum {NoTax = 0, HalfTax = 7, FullTax = 19} KindOFTaxes;

typedef struct{
    char *Description;
    float Amount;
    float NetPricePerUnit;
    KindOFTaxes Tax;
}sArticle;

typedef struct{
    char *Costumer;
    sDate Date;
    int ArticleCounter;
    sArticle Article[MAXARTICLE];
    float SumNetPrice;
    float SumTax;
    float SumGrossPrice;
}sInvoice;

extern int InvoiceCounter;
extern sInvoice *Invoice;

#endif // DATASTRUCTURE_H_INCLUDED
