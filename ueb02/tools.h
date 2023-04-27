#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

void clearBuffer();
void clearScreen();
void waitForEnter();
int askYesOrNo(char *Quastion);
void enter(int howManyTimes);
void printLine(char look, int howManyTimes);

#endif // TOOLS_H_INCLUDED
