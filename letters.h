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

#define IMPLEMENTED_LETTERS	1

enum letterName
{
	LETTER_A = 0,
	LETTER_B,
	LETTER_C
};

typedef struct
{
	int nb;
	char* table;
}letter;

void	create_letters_table(void);
void	printChar(char);
letter	mLetter[26];

#endif
