//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "OnePlus 7Pro" // Add your network credentials
#define STAPSK  "bhavani@360"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
 int X,Y,Z;
int A,B,C,D;


void assign_1(int D,int C,int B,int A)
{
   digitalWrite(2,A);//lsb
   digitalWrite(3,B);
   digitalWrite(4,C);
   digitalWrite(5,D);//msb

}



void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
  
  pinMode(2, OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
}
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  
  X = digitalRead(6);
  Y = digitalRead(7);
  Z = digitalRead(8);
  
  A = (X&&Y) || (Y&&Z); 

  assign_1(D,C,B,A);
}
}
