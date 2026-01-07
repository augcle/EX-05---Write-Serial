/*
Small program for sending a message to a microcontroller and recieving whatever was send.
It can convert it to binary, this is done in line 18. Just delete the comment slashes and comment out line 19.
Code comes from Exercise 5 in the DTU course 34338, january 2026.
*/

#include <SPI.h>
int incomingByte = 0; // Value used to hold the 

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { // If data is send
  incomingByte = Serial.read(); // Read the value of whatever is send into the variable
  Serial.print("I received: ");
  // Serial.println(incomingByte, DEC) This is used for converting the value to decimal numbers (ASCII)
  Serial.println((char)incomingByte);
  }
}