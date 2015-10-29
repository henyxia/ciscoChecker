#include <stdarg.h>
#include "letters.h"
#include "LCD_driver.h"

int posX=0;
int posY=0;

int nstrlen(char* str)
{
	//FIXME
	// Add a non infinite loop checker
	int ret = 0;
	while(str[ret] != '\0')
		ret++;

	return ret;
}

void printS(char* str)
{
	int len = nstrlen(str);
	for(int i=0; i<len; i++)
		printChar(str[i]);
}

int getIndex(char myChar)
{
	//FIXME
	// Can be improved
	for(int i=0; i<IMPLEMENTED_LETTERS; i++)
		if(alpha[i] == myChar)
			return i;

	// Displaying ? as unknown
	//FIXME
	//Only 'A' is available
	return 0;
}

void printChar(char myChar)
{
	// Searching the char
	int sChar = getIndex(myChar);

	// Displaying
	for(int i=0; i<mLetter[sChar].nb; i++)
		LCDSetPixel(WHITE, posY + ((mLetter[sChar].table[i] & 0xF0) >> 4), posX + (mLetter[sChar].table[i] & 0x0F));

	// Moving cursor
	posX+=8;
	if(posX>120)
	{
		posY+=16;
		posX=0;
	}
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
	alpha[0] = 'A';
	mLetter[0].nb = 37;
	alpha[1] = 'B';
	mLetter[1].nb = 35;
	alpha[2] = 'C';
	mLetter[2].nb = 20;
	alpha[3] = 'D';
	mLetter[3].nb = 32;
	alpha[4] = 'E';
	mLetter[4].nb = 29;
	alpha[5] = 'F';
	mLetter[5].nb = 23;
	alpha[6] = 'G';
	mLetter[6].nb = 26;
	alpha[7] = 'H';
	mLetter[7].nb = 31;
	alpha[8] = 'I';
	mLetter[8].nb = 32;
	alpha[9] = 'J';
	mLetter[9].nb = 17;
	alpha[10] = 'K';
	mLetter[10].nb = 26;
	alpha[11] = 'L';
	mLetter[11].nb = 20;
	alpha[12] = 'M';
	mLetter[12].nb = 37;
	alpha[13] = 'N';
	mLetter[13].nb = 35;
	alpha[14] = 'O';
	mLetter[14].nb = 20;
	alpha[15] = 'P';
	mLetter[15].nb = 32;
	alpha[16] = 'Q';
	mLetter[16].nb = 37;
	alpha[17] = 'R';
	mLetter[17].nb = 35;
	alpha[18] = 'S';
	mLetter[18].nb = 20;
	alpha[19] = 'T';
	mLetter[19].nb = 32;
	alpha[20] = 'U';
	mLetter[20].nb = 37;
	alpha[21] = 'V';
	mLetter[21].nb = 35;
	alpha[22] = 'W';
	mLetter[22].nb = 20;
	alpha[23] = 'X';
	mLetter[23].nb = 32;
	alpha[24] = 'Y';
	mLetter[24].nb = 37;
	alpha[25] = 'Z';
	mLetter[25].nb = 35;
	alpha[26] = 'a';
	mLetter[26].nb = 20;
	alpha[27] = 'b';
	mLetter[27].nb = 32;
	alpha[28] = 'c';
	mLetter[28].nb = 37;
	alpha[29] = 'd';
	mLetter[29].nb = 35;
	alpha[30] = 'e';
	mLetter[30].nb = 20;
	alpha[31] = 'f';
	mLetter[31].nb = 32;
	alpha[32] = 'g';
	mLetter[32].nb = 37;
	alpha[33] = 'h';
	mLetter[33].nb = 35;
	alpha[34] = 'i';
	mLetter[34].nb = 20;
	alpha[35] = 'j';
	mLetter[35].nb = 32;
	alpha[36] = 'k';
	mLetter[36].nb = 37;
	alpha[37] = 'l';
	mLetter[37].nb = 35;
	alpha[38] = 'm';
	mLetter[38].nb = 20;
	alpha[39] = 'n';
	mLetter[39].nb = 32;
	alpha[40] = 'o';
	mLetter[40].nb = 37;
	alpha[41] = 'p';
	mLetter[41].nb = 35;
	alpha[42] = 'q';
	mLetter[42].nb = 20;
	alpha[43] = 'r';
	mLetter[43].nb = 32;
	alpha[44] = 's';
	mLetter[44].nb = 37;
	alpha[45] = 't';
	mLetter[45].nb = 35;
	alpha[46] = 'u';
	mLetter[46].nb = 20;
	alpha[47] = 'v';
	mLetter[47].nb = 32;
	alpha[48] = 'w';
	mLetter[48].nb = 37;
	alpha[49] = 'x';
	mLetter[49].nb = 35;
	alpha[50] = 'y';
	mLetter[50].nb = 20;
	alpha[51] = 'z';
	mLetter[51].nb = 32;
	alpha[52] = '0';
	mLetter[52].nb = 37;
	alpha[53] = '1';
	mLetter[53].nb = 35;
	alpha[54] = '2';
	mLetter[54].nb = 20;
	alpha[55] = '3';
	mLetter[55].nb = 32;
	alpha[56] = '4';
	mLetter[56].nb = 37;
	alpha[57] = '5';
	mLetter[57].nb = 35;
	alpha[58] = '6';
	mLetter[58].nb = 20;
	alpha[59] = '7';
	mLetter[59].nb = 32;
	alpha[60] = '8';
	mLetter[60].nb = 37;
	alpha[61] = '9';
	mLetter[61].nb = 35;
	alpha[62] = '?';
	mLetter[62].nb = 0;

	for(int i=0; i<IMPLEMENTED_LETTERS; i++)
	{
		mLetter[i].table = NULL;
		mLetter[i].table = malloc(sizeof(char) * (mLetter[i].nb+1));
		if(mLetter[i].table == NULL)
		//FIXME
		// Need to return bool here
			return;
	}

	// 'A'
	addValuesToALetter(mLetter[0].table, mLetter[0].nb, 0x13,0x22,0x24,0x31,0x35,0x41,0x45,0x50,0x56,0x60,0x66,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x90,0x96,0xA0,0xA6,0xB0,0xB6,0xC0,0xC6,0xD0,0xD6,0xE0,0xE6);
	// 'B'
	addValuesToALetter(mLetter[1].table, mLetter[1].nb, 0x20,0x21,0x22,0x23,0x24,0x30,0x35,0x40,0x46,0x50,0x56,0x60,0x66,0x70,0x75,0x80,0x81,0x82,0x83,0x84,0x90,0x95,0xA0,0xA6,0xB0,0xB6,0xC0,0xC6,0xD0,0xD5,0xE0,0xE1,0xE2,0xE3,0xE4);
	// 'C'
	addValuesToALetter(mLetter[2].table, mLetter[2].nb, 0x13,0x14,0x15,0x16,0x22,0x31,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,0xB0,0xC1,0xD2,0xE3,0xE4,0xE5,0xE6);
	// 'D'
	addValuesToALetter(mLetter[3].table, mLetter[3].nb, 0x10,0x11,0x12,0x13,0x20,0x24,0x30,0x35,0x40,0x46,0x50,0x56,0x60,0x66,0x70,0x76,0x80,0x86,0x90,0x96,0xA0,0xA6,0xB0,0xB6,0xC0,0xC5,0xD0,0xD4,0xE0,0xE1,0xE2,0xE3);
	// 'E'
	addValuesToALetter(mLetter[4].table, mLetter[4].nb, 0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x30,0x40,0x50,0x60,0x70,0x80,0x81,0x82,0x83,0x84,0x90,0xA0,0xB0,0xC0,0xD0,0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6);
	// 'F'
	addValuesToALetter(mLetter[5].table, mLetter[5].nb, 0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x30,0x40,0x50,0x60,0x70,0x80,0x81,0x82,0x83,0x84,0x90,0xA0,0xB0,0xC0,0xD0,0xE0);
	// 'G'
	addValuesToALetter(mLetter[6].table, mLetter[6].nb, 0x36,0x25,0x14,0x13,0x22,0x31,0x41,0x50,0x60,0x70,0x80,0x90,0xA0,0xB1,0xC1,0xD2,0xE3,0xE4,0xD5,0xC6,0xB6,0xA6,0x96,0x86,0x85,0x84);
	// 'H'
	addValuesToALetter(mLetter[7].table, mLetter[7].nb, 0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,0xB0,0xC0,0xD0,0xE0,0x26,0x36,0x46,0x56,0x66,0x76,0x86,0x96,0xA6,0xB6,0xC6,0xD6,0xE6,0x81,0x82,0x83,0x84,0x85);
	// 'I'
	addValuesToALetter(mLetter[8].table, mLetter[8].nb, 0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x22,0x23,0x24,0x33,0x43,0x53,0x63,0x73,0x83,0x93,0xA3,0xB3,0xC3,0xD2,0xD3,0xD4,0xE0,0xE1,0xE1,0xE2,0xE3,0xE3,0xE4,0xE5,0xE6);
	// 'J'
	addValuesToALetter(mLetter[9].table, mLetter[9].nb, 0x16,0x26,0x36,0x46,0x56,0x66,0x76,0x86,0x96,0xA6,0xB6,0xC5,0xD4,0xE3,0xE2,0xD1,0xC0);
	// 'K'
	addValuesToALetter(mLetter[10].table, mLetter[10].nb, 0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,0xB0,0xC0,0xD0,0xE0,0x26,0x35,0x44,0x53,0x62,0x71,0x81,0x92,0xA3,0xB4,0xC5,0xD6);
	// 'L'
	addValuesToALetter(mLetter[11].table, mLetter[11].nb, 0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,0xB0,0xC0,0xD0,0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6);
}
