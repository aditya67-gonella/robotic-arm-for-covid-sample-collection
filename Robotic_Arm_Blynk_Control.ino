#define BLYNK_PRINT Serial                     //redefine  BLYNK_PRINT as Serial
#include <ESP8266WiFi.h>                       //header file for controlling wifi
#include <BlynkSimpleEsp8266.h>                //header for blynk
#include<Servo.h>


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

char auth[] = " kq9UZgeDjrQhJKMe9W4YpLSMYhrlTW2D";   // indentification of your board like phone number
char ssid[] = "Mi A3";                // your Hotspot name
char pass[] = "aditya123";                // your Hotspot password

//....................setup()....................

void setup() {
  servo1.attach(D9); 
  servo2.attach(D10);
  servo3.attach(D11);
  servo4.attach(D12);
  Serial.begin(9600);                     //setting the speed of communication between your laptop and board, 9600 baud rate
  Blynk.begin(auth, ssid, pass);          // connecting to WiFi Network
}

//.....................writing positions to respective servos.................

BLYNK_WRITE(V1)
{
   servo1.write(param.asInt());
   Serial.println(param.asInt());
}
BLYNK_WRITE(V2)
{
   servo2.write(param.asInt());
   Serial.println(param.asInt());
}
BLYNK_WRITE(V3)
{
   servo3.write(param.asInt());
   Serial.println(param.asInt());
}
BLYNK_WRITE(V4)
{
   servo4.write(param.asInt());
   Serial.println(param.asInt());
}

//....................loop()....................
void loop() {
  
 Blynk.run();                  //Blynk communicate begins to mobile
  
}
