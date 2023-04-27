#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXARTICLE 20
#define MAXINVOICES 10

typedef struct{
    int Day;
    int Month;
    int Year;
} sDate;

typedef struct{
    char *Description;
    float Amount;
    float NetPricePerUnit;
    enum KindOFTaxes{NoTax, HalfTax, FullTax};
}sArticle;

typedef struct{
    char *Costumer;
    sDate Date;
    int ArticleCounter;
    sArticle Article[MAXARTICLE];
}sInvoice;

#endif // DATASTRUCTURE_H_INCLUDED
