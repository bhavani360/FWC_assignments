#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
int main (void)
{

 bool X,Y,Z,F=0;
 DDRB =  0b00000111;  //  8,9,10 pin as output
 DDRD =  0b11111000;
 PORTD = 0b00000100;   // pin 2 as output
 

while(1)
{  

X= (PINB & (1 << PINB0)) == (1 << PINB0);
Y= (PINB & (1 << PINB1)) == (1 << PINB1);
Z= (PINB & (1 << PINB2)) == (1 << PINB2);
F=((X&&Y) || (Y&&Z));
PORTD |= (F<< 2);
}
return 0;
}

