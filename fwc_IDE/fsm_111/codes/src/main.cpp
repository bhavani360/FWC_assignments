#include <Arduino.h>

int X;
int Y,A,B,C,D,P,Q;

void disp_fsm_101(int D,int C,int B,int A)
{
  digitalWrite(2,A);
  digitalWrite(3,B);
  
}
void setup() {
        pinMode(13,OUTPUT);
        pinMode(7,OUTPUT);
        pinMode(6,OUTPUT);
        pinMode(4,INPUT);
        pinMode(5,INPUT);
        pinMode(8,INPUT);
        pinMode(9,OUTPUT);
	digitalWrite(7,0);
	digitalWrite(6,0);
 }
void loop() {
digitalWrite(13,HIGH);
delay(1000);
X=digitalRead(8);
A=digitalRead(4);
B=digitalRead(5);

P=(A&&!B&&X) || (!A&&B&&X);
Q=(B&&X) || (!A&&X);
Y=(!A&&B&&X);
digitalWrite(7,P);
digitalWrite(6,Q);
digitalWrite(9,Y);

disp_fsm_101(D,C,B,A);
digitalWrite(13,LOW);
delay(1000);
}
