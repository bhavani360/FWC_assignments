
#include <Arduino.h>
int a,b,c,d,e,f,g;
int  A=0,B=1,C=0,D=1;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int a, int b, int c, int d,int e,int f,int g)
{
  digitalWrite(2, a); //MSB
  digitalWrite(3, b); 
  digitalWrite(4, c); 
  digitalWrite(5, d); 
  digitalWrite(6, e);
  digitalWrite(7, f);
  digitalWrite(8, g); //lsb

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  a=(B&&!C&&!D) || (!A&&!B&&!c&&D);
  b=(B&&!c) || (B&&C&&!D);
  c=(!B&&C&&!D);
  d=(A&&D) || (B&&!C&&!D) || (B&&C&&D);
  e=(!A&&D) || (A&&D) || (B&&!C);
  f=(C&&D) || (!B&&C) || (!A&&!B&&D);
  g=(!A&&!B&&!C) || (B&&C&&D);
disp_7447(a,b,c,d,e,f,g);  
}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
