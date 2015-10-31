#ifndef __LETTERS_H__
#define __LETTERS_H__

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 	
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <avr/pgmspace.h>

#define IMPLEMENTED_LETTERS	63

void	printChar(char);
void	printS(char*);
void	resetScreen();

#endif
