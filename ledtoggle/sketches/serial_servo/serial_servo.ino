//#define LED 13
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  Serial.print("\r\nStart");
  myservo.attach(9);


  //pinMode(LED, OUTPUT);
  // Turn it off for now.
  //digitalWrite(LED, LOW);
}

int incomingByte = 0;

void loop() {
  // Check if there's a serial message waiting.
  if (Serial.available() > 0) {
    // If there is, read the incoming byte.
    incomingByte = Serial.read();
    if (incomingByte == 'y') {
      for (pos = 0; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 0; pos -= 2) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);              // waits 15ms for the servo to reach the position
      }
    }
  } else if (incomingByte == 'n') {
    myservo.write(0);
  }
  Serial.print(incomingByte);
}

