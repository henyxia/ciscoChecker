#include <stdarg.h>
#include "letters.h"
#include "LCD_driver.h"

#define IMPLEMENTED_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789? "

// Globals
int			posX=0;
int			posY=0;

// Letter definition
const char	letter_A[] PROGMEM = {
	0x13,0x22,0x24,0x31,0x35,0x41,0x45,0x50,0x56,0x60,
	0x66,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x80,0x81,
	0x82,0x83,0x84,0x85,0x86,0x90,0x96,0xA0,0xA6,0xB0,
	0xB6,0xC0,0xC6,0xD0,0xD6,0xE0,0xE6,0x00};
const char	letter_B[] PROGMEM = {
	0x20,0x21,0x22,0x23,0x24,0x30,0x35,0x40,0x46,0x50,
	0x56,0x60,0x66,0x70,0x75,0x80,0x81,0x82,0x83,0x84,
	0x90,0x95,0xA0,0xA6,0xB0,0xB6,0xC0,0xC6,0xD0,0xD5,
	0xE0,0xE1,0xE2,0xE3,0xE4,0x00};
const char	letter_C[] PROGMEM = {
	0x13,0x14,0x15,0x16,0x22,0x31,0x40,0x50,0x60,0x70,
	0x80,0x90,0xA0,0xB0,0xC1,0xD2,0xE3,0xE4,0xE5,0xE6,
	0x00};

const char	letter_D[] PROGMEM = {
	0x10,0x11,0x12,0x13,0x20,0x24,0x30,0x35,0x40,0x46,
	0x50,0x56,0x60,0x66,0x70,0x76,0x80,0x86,0x90,0x96,
	0xA0,0xA6,0xB0,0xB6,0xC0,0xC5,0xD0,0xD4,0xE0,0xE1,
	0xE2,0xE3,0x00};
const char	letter_E[] PROGMEM = {
	0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x30,0x40,0x50,
	0x60,0x70,0x80,0x81,0x82,0x83,0x84,0x90,0xA0,0xB0,
	0xC0,0xD0,0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0x00};
const char	letter_F[] PROGMEM = {
	0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x30,0x40,0x50,
	0x60,0x70,0x80,0x81,0x82,0x83,0x84,0x90,0xA0,0xB0,
	0xC0,0xD0,0xE0,0x00};
const char	letter_G[] PROGMEM = {
	0x36,0x25,0x14,0x13,0x22,0x31,0x41,0x50,0x60,0x70,
	0x80,0x90,0xA0,0xB1,0xC1,0xD2,0xE3,0xE4,0xD5,0xC6,
	0xB6,0xA6,0x96,0x86,0x85,0x84,0x00};
const char	letter_H[] PROGMEM = {
	0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,0xB0,
	0xC0,0xD0,0xE0,0x26,0x36,0x46,0x56,0x66,0x76,0x86,
	0x96,0xA6,0xB6,0xC6,0xD6,0xE6,0x81,0x82,0x83,0x84,
	0x85,0x00};
const char	letter_I[] PROGMEM = {
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x22,0x23,0x24,
	0x33,0x43,0x53,0x63,0x73,0x83,0x93,0xA3,0xB3,0xC3,
	0xD2,0xD3,0xD4,0xE0,0xE1,0xE1,0xE2,0xE3,0xE3,0xE4,
	0xE5,0xE6,0x00};
const char	letter_J[] PROGMEM = {
	0x16,0x26,0x36,0x46,0x56,0x66,0x76,0x86,0x96,0xA6,
	0xB6,0xC5,0xD4,0xE3,0xE2,0xD1,0xC0,0x00};
const char	letter_K[] PROGMEM = {
	0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,
	0xB0,0xC0,0xD0,0xE0,0x26,0x35,0x44,0x53,0x62,0x71,
	0x81,0x92,0xA3,0xB4,0xC5,0xD6,0x00};
const char	letter_L[] PROGMEM = {
	0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,
	0xB0,0xC0,0xD0,0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,
	0x00};
const char	letter_M[] PROGMEM = {
	0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,
	0xB0,0xC0,0xD0,0xE0,0x21,0x31,0x41,0x42,0x52,0x62,
	0x63,0x73,0x83,0x44,0x54,0x64,0x25,0x35,0x45,0x16,
	0x26,0x36,0x46,0x56,0x66,0x76,0x86,0x96,0xA6,0xB6,
	0xC6,0xD6,0xE6,0x00};
const char	letter_N[] PROGMEM = {
	0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,
	0xB0,0xC0,0xD0,0xE0,0x21,0x31,0x41,0x42,0x52,0x62,
	0x63,0x73,0x83,0x93,0x94,0xA4,0xB4,0xB5,0xC5,0xD5,
	0x16,0x26,0x36,0x46,0x56,0x66,0x76,0x86,0x96,0xA6,
	0xB6,0xC6,0xD6,0xE6,0x00};
const char	letter_O[] PROGMEM = {
	0x13,0x22,0x31,0x40,0x50,0x60,0x70,0x80,0x90,0xA0,
	0xB0,0xC1,0xD2,0xE3,0xD4,0xC5,0xB6,0xA6,0x96,0x86,
	0x76,0x66,0x56,0x46,0x35,0x24,0x00};
const char	letter_P[] PROGMEM = {0x00};
const char	letter_Q[] PROGMEM = {0x00};
const char	letter_R[] PROGMEM = {0x00};
const char	letter_S[] PROGMEM = {0x00};
const char	letter_T[] PROGMEM = {0x00};
const char	letter_U[] PROGMEM = {0x00};
const char	letter_V[] PROGMEM = {0x00};
const char	letter_W[] PROGMEM = {0x00};
const char	letter_X[] PROGMEM = {0x00};
const char	letter_Y[] PROGMEM = {0x00};
const char	letter_Z[] PROGMEM = {0x00};
const char	letter_a[] PROGMEM = {0x00};
const char	letter_b[] PROGMEM = {0x00};
const char	letter_c[] PROGMEM = {0x00};
const char	letter_d[] PROGMEM = {0x00};
const char	letter_e[] PROGMEM = {0x00};
const char	letter_f[] PROGMEM = {0x00};
const char	letter_g[] PROGMEM = {0x00};
const char	letter_h[] PROGMEM = {0x00};
const char	letter_i[] PROGMEM = {0x00};
const char	letter_j[] PROGMEM = {0x00};
const char	letter_k[] PROGMEM = {0x00};
const char	letter_l[] PROGMEM = {0x00};
const char	letter_m[] PROGMEM = {0x00};
const char	letter_n[] PROGMEM = {0x00};
const char	letter_o[] PROGMEM = {0x00};
const char	letter_p[] PROGMEM = {0x00};
const char	letter_q[] PROGMEM = {0x00};
const char	letter_r[] PROGMEM = {0x00};
const char	letter_s[] PROGMEM = {0x00};
const char	letter_t[] PROGMEM = {0x00};
const char	letter_u[] PROGMEM = {0x00};
const char	letter_v[] PROGMEM = {0x00};
const char	letter_w[] PROGMEM = {0x00};
const char	letter_x[] PROGMEM = {0x00};
const char	letter_y[] PROGMEM = {0x00};
const char	letter_z[] PROGMEM = {0x00};
const char	letter_0[] PROGMEM = {0x00};
const char	letter_1[] PROGMEM = {0x00};
const char	letter_2[] PROGMEM = {0x00};
const char	letter_3[] PROGMEM = {0x00};
const char	letter_4[] PROGMEM = {0x00};
const char	letter_5[] PROGMEM = {0x00};
const char	letter_6[] PROGMEM = {0x00};
const char	letter_7[] PROGMEM = {0x00};
const char	letter_8[] PROGMEM = {0x00};
const char	letter_9[] PROGMEM = {0x00};
const char	letter_int[] PROGMEM = {0x00};
const char	letter_space[] PROGMEM = {0x00};
const char	letter_rn[] PROGMEM = {0x00};

const char*	const mLetter[] PROGMEM = {
	letter_A, letter_B, letter_C, letter_D,
	letter_E, letter_F, letter_G, letter_H,
	letter_I, letter_J, letter_K, letter_L,

	letter_M, letter_N, letter_O, letter_P,
	letter_Q, letter_R, letter_S, letter_T,
	letter_U, letter_V, letter_W, letter_X,

	letter_Y, letter_Z, letter_a, letter_b,
	letter_c, letter_d, letter_e, letter_f,
	letter_g, letter_h, letter_i, letter_j,

	letter_k, letter_l, letter_m, letter_n,
	letter_o, letter_p, letter_q, letter_r,
	letter_s, letter_t, letter_u, letter_v,

	letter_w, letter_x, letter_y, letter_z,
	letter_0, letter_1, letter_2, letter_3,
	letter_4, letter_5, letter_6, letter_7,

	letter_8, letter_9, letter_int, letter_space,
	letter_rn
};


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
	char buffer[65];
	strcpy(buffer, IMPLEMENTED_CHARS);
	//FIXME
	// Can be improved
	if(myChar>='A' && myChar<='Z')
		return myChar - 'A';
	if(myChar==' ')
	{
		posX+=8;
		if(posX>120)
		{
			posY+=16;
			posX=0;
		}
	}
	if(myChar=='\n')
	{
		posY+=16;
		posX=0;
	}
	for(int i=0; i<IMPLEMENTED_LETTERS; i++)
		if(buffer[i] == myChar)
			return i;

	// Displaying ? as unknown
	//FIXME
	//Only 'A' is available
	return 0;
}

void printChar(char myChar)
{
	char buffer[50];

	// Searching the char
	int sChar = getIndex(myChar);
	strcpy_P(buffer, (char*)pgm_read_word(&(mLetter[sChar])));
	int len = nstrlen(buffer);

	printf("Printing char %c, index %d of len %d\n", myChar, sChar, len);

	// Displaying
	for(int i=0; i<len; i++)
	{
		//printf("I %02d X %02d Y%02d X %02x\n", i, (buffer[i] & 0xF0) >> 4, (buffer[i] & 0x0F), buffer[i]);
		LCDSetPixel(WHITE, 1 + posY + ((buffer[i] & 0xF0) >> 4), 1 + posX + (buffer[i] & 0x0F));
	}

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
