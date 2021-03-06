#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 	
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <avr/pgmspace.h>

#include "serial.h"
#include "LCD_driver.h"
#include "nokia_tester.h"
#include "letters.h"

#define RESPONSE_SIZE	40

void		ioinit(void);
static int	uart_putchar(char c, FILE *stream);
uint8_t		uart_getchar(void);
void		getResponse(char*, int, int);
static FILE	mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

int main(int argc,char * argv[])
{
	// Vars
	char	response[RESPONSE_SIZE];

	// Init
	ioinit();
	LCDInit();
	LCDClear(BLACK);

	/*
	//Test letters
	printS("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	printS("abcdefghijklmnopqrstuvwxyz\n");
	printS("?.!\n");
	*/
	
	// Boot screen
	printS("ciscoChecker\n\n");
	printS("Written by\n");
	printS("Jean Wasilewski\n");
	printS("and\n");
	printS("Flavien Royer\n\n");
	printS("v0.6");

	// Reset
	delay_ms(3000);
	LCDClear(BLACK);
	resetScreen();

	// Main loop
	printS("Started !\n");
	printS("Pinging ...\n");
	printf("\n");
    
	while( !(UCSR0A & (1<<RXC0)) );
	getResponse(response, RESPONSE_SIZE, 20);
	printS("> ");
	printS(response);
	

	while(1)
	{
		getResponse(response, RESPONSE_SIZE, 5);
		printS(response);

		if((PIND & (1<<3)) == 0)
		{
			printS("BUTTON A\n");
		}
		/*
		if((PIND & (1<<4)) == 0)
		{
			printS("BUTTON B\n");
		}
		if((PIND & (1<<5)) == 0)
		{
			printS("BUTTON C\n");
		}*/
	}

    return 0;
}

void ioinit(void)
{
	DDRB = ((1<<CS)|(1<<DIO)|(1<<SCK)|(1<<LCD_RES));	//Set the control pins as outputs

	// USART Baud rate: 115200 (With 16 MHz Clock)
    UBRR0H = (MYUBRR >> 8) & 0x7F;	//Make sure highest bit(URSEL) is 0 indicating we are writing to UBRRH
	UBRR0L = MYUBRR;
//    UCSR0A = (1<<U2X0);					//Double the UART Speed
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);		//Enable Rx and Tx in UART
    UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);		//8-Bit Characters
    stdout = &mystdout; //Required for printf init
	//stdin = &mystdin;
	cli();
	
	// Arduino D3-5 are button pins
	// This is PD3-5
	DDRD = 0x00;
	PORTD = 0xFF;
	
	// Init timer 2
	//Set Prescaler to 9. (Timer Frequency set to 16Mhz)
	//Used for delay routines
	TCCR2B = (1<<CS20); 	//Divde clock by 1 for 16 Mhz Timer 2 Frequency	
}

static int uart_putchar(char c, FILE *stream)
{
  if (c == '\n')
    uart_putchar('\r', stream);
  
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}

void getResponse(char* out, int maxSize, int timeout)
{
	int i=0;
	while(1)
	{
		if(i==maxSize)
		{
			out[i]=0;
			return;
		}
		while(!(UCSR0A & (1<<RXC0)));
		out[i]=UDR0;
		if(out[i]=='\r')
		{
			out[i+1]=0;
			return;
		}
		i++;
	}
}

uint8_t uart_getchar(void)
{
    while( !(UCSR0A & (1<<RXC0)) );
	return(UDR0);
}

//General short delays
void delay_ms(int x)
{
    for (; x > 0 ; x--)
        delay_us(1000);
}

//General short delays
void delay_us(int x)
{    
    TIFR2 = (1<<TOV2); //Clear any interrupt flags on Timer2
    TCNT2= 240; //Setting counter to 239 will make it 16 ticks until TOV is set. .0625uS per click means 1 uS until TOV is set
    while(x>0){
		while( (TIFR2 & (1<<TOV2)) == 0);
		TIFR2 = (1<<TOV2); //Clear any interrupt flags on Timer2
		TCNT2=240;
		x--;
	}
}
