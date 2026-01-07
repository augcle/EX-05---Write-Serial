/**
 * @file WriteSerial.ino
 * @author August Clemmensen & Viktor Munk
 * @brief Small program for sending a message to a microcontroller and recieving whatever was send.
 *        It can convert it to binary, but this is optinal. 
 * @version 1
 * @date 2026-01-07
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <SPI.h>

// Global Variable
int incomingByte = 0; ///< Used to hold the character sent through serial


/**
 * Enables the use of serial communication through Baud 9600
 * 
 */
void setup() {
  Serial.begin(9600);
}

/**
 * The main loop the continually monitors if a message has been sent and outputs it
 * 
 */
void loop() {
  if (Serial.available() > 0) {         // If data is send then execute
  incomingByte = Serial.read();         // Holds the value of whatever is send through the serial connection
  Serial.print("I received: ");
  // Serial.println(incomingByte, DEC)  // This is used for converting the value to decimal numbers (ASCII)
  Serial.println((char)incomingByte);   // This is used for displaying the actual character entered
  }
}
