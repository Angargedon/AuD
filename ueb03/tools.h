#ifndef TOOLS_H
#define TOOLS_H

/**************************************
 * Enter function that replaces the
 * 'backslash n'. Great use for greater 
 * amounts of 'backslash n' and
 * structured code           
**************************************/
void enter(int howManyTimes);

/**************************************
 * Uses the "CLS" Windows shell       
 * command to clear your terminal     
 * screen                             
**************************************/
void clearScreen();

/**************************************
 * Should be used after every 'scanf' 
 * to wipe out potential input buffers    
**************************************/
void clearBuffer();

/**************************************
 * Question can be asked where the    
 * user should only anser yes 'y' or  
 * no 'n'. 'j' for german language    
 * included                           
**************************************/
int askYesOrNo(char *question);

/**************************************
 * Text appears that usually tells the
 * user to press enter and waits unti 
 * enter is pressed                   
**************************************/
void waitForEnter(char *text);

/**************************************
 * Prints a title text ('char *name')  
 * and puts an underline ('char line')
 * to it. The underline has the same  
 * lenght as the title. Can also be   
 * used as simple highlight instead   
 * of a title                         
**************************************/
void title(char *name, char line);

//Dog
void Dog();

#endif