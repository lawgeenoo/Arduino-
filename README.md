# Arduino-
Messing around with an Arduino Uno clone. Small projects made at home. Since the video was too large for Github, you can view it at the link listed below:

https://www.youtube.com/watch?v=6CSMxv1Jfg0


An ultrasonic sensor(HC-SR04) hooked to an UNO clone, fitted to a toy car. I have used the HC-SR04 library to simplify things. Used a simple buzzer for beeping. The device is rigged to make different beeping patters at roughly 20, 10 cm, respectively continuous beep at 5 cm or less away from the obstacle. 

The code is:

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
