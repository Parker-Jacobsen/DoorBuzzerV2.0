//This program plays a basic tune on reaction of microphone
/************************************************/
#include <Servo.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
/************************************************/
const int sensorPin = A0; // select the input pin for the potentiometer

int sensorValue = 0; // variable to store the value coming from the sensor
int max=0;

void setup () 
{
  Serial.begin (9600);
  Serial.println("APPLICATION START");
  mp3_set_serial (Serial);  //set Serial for DFPlayer-mini mp3 module 
  delay(1);  //wait 1ms for mp3 module to set volume
  mp3_set_volume (15);
  mp3_play (1);
}
 
void loop () 
{
  Serial.println("Loop Start");

  sensorValue = analogRead (sensorPin);
  if (sensorValue>max)
  {
        max=sensorValue;
  }
  if(sensorValue>23)
  {
      mp3_play (1);
      delay(10);
      Serial.println("SOUND PLAYED");
      delay(2000);
  }
  Serial.print("Current Value:\t");
  Serial.print(sensorValue, DEC);
  Serial.print("\tMax:\t");
  Serial.println(max);
  delay(1000);
}


