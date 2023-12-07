#ifndef TOOLS_H
#define TOOLS_H

void enter(int howManyTimes);

void clearScreen();

void clearBuffer();

int askYesOrNo(char *question);

void waitForEnter(char *text);

void title(char *name, char line);

#endif