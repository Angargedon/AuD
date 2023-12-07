#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

/********************************
*Clears the input buffer for the*
*case that a user makes an      *
*unnessesary input              *
********************************/
void clearBuffer();

/********************************
*Clears the screen.. Oviously   *
********************************/
void clearScreen();

/********************************
*Tells the user to press enter  *
*and only continues if the user *
*do so                          *
********************************/
void waitForEnter();

/********************************
*The argument is a yes-or-no    *
*question you ask the user.     *
*The user has to answer with    *
*'y'/'Y'/'j'/'J' for 'yes' or   *
*'n'/'N' for 'no'. The return   *
*value is actually a truth value*
*with '0' for 'no' and '1' for  *
*'yes                           *
********************************/
int askYesOrNo(char *Quastion);

/********************************
*Prints an '\n' aka enter so you*
*don't have to. The argument    *
*is the amount of times you want*
*to print enter/'\n'            *
********************************/
void enter(int howManyTimes);

/*****************************
*Prints a line with the first*
*argument being the symbol of*
*which gets printed as a line*
*while the second argument is*
*how long the line should be *
*****************************/
void printLine(char look, int howManyTimes);

#endif // TOOLS_H_INCLUDED
