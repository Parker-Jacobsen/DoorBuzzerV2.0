//This program plays a basic tune on reaction of microphone
/************************************************/
#include <Servo.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
/************************************************/
/************************************************/
Servo doorServo;//create servo object to control a servo
Servo talkServo;

//Servo angles
const int talkRelease=61; //was 28
const int talkPress=32;   //was 61
const int doorRelease=28;
const int doorPress=57;  //was 61, 58
/************************************************/
const int sensorPin = A0; // select the input pin for the potentiometer

int sensorValue = 0; // variable to store the value coming from the sensor
int max=0;

void setup () 
{
  Serial.begin (9600);
  doorServo.attach(11);//attachs the servo on pin 9 to servo object
  doorServo.write(doorRelease);//Start at 28 degrees 
  talkServo.attach(10);//attachs the servo on pin 9 to servo object
  talkServo.write(talkRelease);//Start at 28 degrees 
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
      Serial.println("TalkPress");
      talkServo.write(talkPress); //Press talk button
      delay(100);
      mp3_play (1);
      delay(10);
      Serial.println("SOUND PLAYED");
      delay(1000);
      talkServo.write(talkRelease); //Release talk button
      delay(200);
      
      Serial.println("DoorPress");
      doorServo.write(doorPress);
      delay(300);
      doorServo.write(doorRelease);
      delay(300);
  }
  
  Serial.print("Current Value:\t");
  Serial.print(sensorValue, DEC);
  Serial.print("\tMax:\t");
  Serial.println(max);
  delay(1000);
}


