//www.plusivo.com
//
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   pinMode(8, OUTPUT);
   Serial.begin(9600);
   delay(1000);
}

void beep()
{
  if(a<=20)
   {
    digitalWrite(8, HIGH);
    delay(50);
    digitalWrite(8, LOW);
   }
   else 
   {
    digitalWrite(8, LOW);
   }
   Serial.print(a);
   if(a<=10)
   {
    digitalWrite(8, HIGH);
    delay(150);
    digitalWrite(8, LOW);
   }
   else 
   {
    digitalWrite(8, LOW);
   }
   
   if(a<=5)
   {
   digitalWrite(8, HIGH);
   }
}

void loop() {
   a=sr04.Distance();
   beep();
   Serial.println("cm");
   delay(50);
}
