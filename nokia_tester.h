void delay_us(int x);
void delay_ms(int x);
void ioinit(void);
void reset(void);

// New
#define CS	1 // D9
#define SCK	5 // D13
#define LCD_RES	0 // D8
#define DIO	3 // D11
#define LCD_PORT	PORTB


/* Old
#define CS	2 // D10
#define SCK	3 // D11
#define LCD_RES	1 // D9
#define DIO	4 // D12
#define LCD_PORT	PORTB
*/

//*******************************************************
//						Macros
//*******************************************************
#define sbi(var, mask)   ((var) |= (uint8_t)(1 << mask))
#define cbi(var, mask)   ((var) &= (uint8_t)~(1 << mask))

//*******************************************************
//					General Definitions
//*******************************************************
#define MYUBRR 206	//Used to set the AVR Baud Rate TO 115200 (External 16MHz Oscillator)
