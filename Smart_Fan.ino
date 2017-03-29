#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 9; 
// Create a servo object 
Servo Servo1; 
int pos=0;

#define trigPin1 3
#define echoPin1 4
#define trigPin2 5
#define echoPin2 6
#define trigPin3 7
#define echoPin3 8

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
Servo1.attach(servoPin);

Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
LeftSensor = distance;
SonarSensor(trigPin2, echoPin2);
RightSensor = distance;
SonarSensor(trigPin3, echoPin3);
FrontSensor = distance;

Serial.print(LeftSensor);
Serial.print("   ");
Serial.print(FrontSensor);
Serial.print("   ");
Serial.println(RightSensor);

if(RightSensor<=20&&FrontSensor>=15&&LeftSensor>=20)
{
   Servo1.write(150);
       Serial.print(" Entered right  "); 
   delay(10);

}

else if(FrontSensor<=15&&RightSensor>=20&&LeftSensor>=20)
{
  Servo1.write(90);
      Serial.print(" Entered front  "); 
  delay(10); 
}
else if(LeftSensor<=20&&RightSensor>=20&&FrontSensor>=15)
{
  Servo1.write(30);
      Serial.print(" Entered left  "); 
  delay(10);
}

else if(RightSensor<=20&&LeftSensor<=20)
{
   for (pos = 30; pos <= 150; pos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 150; pos >= 30; pos -= 2) { // goes from 180 degrees to 0 degrees
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);
  Serial.println(" Entered loop one  ");  
}
}


else if(RightSensor<=20&&FrontSensor<=15&&LeftSensor>=20)
{
   for (pos = 90; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                        // waits 15ms for the servo to reach the position
  }
  for (pos = 150; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);  
   Serial.println(" Entered loop two  ");   
}
}

else if(LeftSensor<=20&&FrontSensor<=15&&RightSensor>=20)
{
   for (pos = 30; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);  
   Serial.println(" Entered loop three  ");   
}
}


}


void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}

