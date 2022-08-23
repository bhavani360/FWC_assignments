#include <Arduino.h>

int X,Y,Z;
int A,B,C,D;


void assign_1(int D,int C,int B,int A)
{
   digitalWrite(2,A);//lsb
   digitalWrite(3,B);
   digitalWrite(4,C);
   digitalWrite(5,D);//msb

}

void setup() {
  pinMode(2, OUTPUT);
 // pinMode(3, OUTPUT);
 // pinMode(4, OUTPUT);
 //pinMode(5, OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
}


void loop() 
{

  X = digitalRead(6);
  Y = digitalRead(7);
  Z = digitalRead(8);
  
  A = (X&&Y) || (Y&&Z); 

  assign_1(D,C,B,A);
}

