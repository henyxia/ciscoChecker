#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 	
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <avr/pgmspace.h>

typedef struct letter {
int nb;
char **table;
}Letter;
