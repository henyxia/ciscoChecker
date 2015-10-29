#include <stdarg.h>
#include "letters.h"
#include "LCD_driver.h"

void printChar(char myChar)
{
	printf("Printing char %c\n", myChar);
	for(int i=0; i<mLetter[0].nb; i++)
	{
		LCDSetPixel(WHITE, (mLetter[0].table[i] & 0xF0) >> 4, mLetter[0].table[i] & 0x0F);
		printf("X%03dY%03d ", mLetter[0].table[i] & 0x0F, (mLetter[0].table[i] & 0xF0) >> 4);
	}
	printf("\n");
}

void addValuesToALetter(char* tLetter, int nb, ...)
{
	va_list chars;
	va_start(chars, nb);

	for(int i=0; i<nb; i++)
	{
		tLetter[i] = (char) va_arg(chars, int);
	}

	va_end(chars);
	return;
}

void create_letters_table(void)
{
	printf("Creating the letters\n");
	mLetter[0].nb = 37;
	mLetter[1].nb = 35;
	mLetter[2].nb = 20;
	mLetter[3].nb = 32;

	for(int i=0; i<IMPLEMENTED_LETTERS; i++)
	{
		printf("Implementing letter %d\n", i);
		mLetter[i].table = NULL;
		mLetter[i].table = malloc(sizeof(char) * (mLetter[i].nb+1));
		if(mLetter[i].table == NULL)
		{
			printf("Error while implementing letter %d\n", i);
			return;
		}
	}

	addValuesToALetter(mLetter[0].table, mLetter[0].nb, 0x13,0x22,0x24,0x31,0x35,0x41,0x45,0x50,0x56,0x60,0x66,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x90,0x96,0xA0,0xA6,0xB0,0xB6,0xC0,0xC6,0xD0,0xD6,0xE0,0xE6);

	/*mLetter[1].table = {0x20,0x21,0x22,0x23,0x24,0x30,0x35,0x40,0x46,0x50,
		0x56,0x60,0x66,0x70,0x75,0x80,0x81,0x82,0x83,0x84,0x90,0x95,0xA0,0xA6,
		0xB0,0xB6,0xC0,0xC6,0xD0,0xD5,0xE0,0xE1,0xE2,0xE3,0xE4};*/
	/*
	Letter[2].table[] = {0x13,0x14,0x15,0x16,0x22,0x31,0x40,0x50,0x60,0x70,
		0x80,0x90,0xA0,0xB0,0xC1,0xD2,0xE3,0xE4,0xE5,0xE6};
	Letter[3].table[] = {0x10,0x11,0x12,0x13,0x20,0x24,0x30,0x35,0x40,0x46,
		0x50,0x56,0x60,0x66,0x70,0x76,0x80,0x86,0x90,0x96,0xA0,0xA6,0xB0,0xB6,
		0xC0,0xC5,0xD0,0xD4,0xE0,0xE0,0xE2,0xE3};
	*/
}
