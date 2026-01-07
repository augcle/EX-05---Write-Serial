/**
 * @file Ex5_SerialEcho.ino
 * @author
 * @date 2026-01-07
 * @brief Simple Serial echo program that reads one byte and prints it back.
 *
 * @details
 * This sketch reads incoming data from the Serial Monitor and prints back what was received.
 * It can either:
 * - Print the received byte as a decimal number (ASCII code), OR
 * - Print the received byte as a character.
 *
 * The sketch is based on Exercise 5 in DTU course 34338 (January 2026).
 *
 * @note
 * If your Serial Monitor is configured to send line endings, you may also receive
 * '\\n' (ASCII 10) and/or '\\r' (ASCII 13) after your input.
 */

#include <SPI.h>           ///< SPI library included (not used in this sketch)

/**
 * @brief Stores the latest received byte from Serial.
 *
 * @details
 * Serial.read() returns the next byte (0..255) as an int, or -1 if nothing is available.
 * Here we only call Serial.read() when Serial.available() > 0, so it will be a valid byte.
 */
int incomingByte = 0;

/**
 * @brief Arduino setup function.
 *
 * @details
 * Initializes Serial communication at 9600 baud.
 */
void setup() {
  Serial.begin(9600);
}

/**
 * @brief Arduino main loop.
 *
 * @details
 * - Checks if at least one byte is available in the Serial buffer.
 * - Reads one byte using Serial.read() into @ref incomingByte.
 * - Prints a label ("I received: ").
 * - Prints the received value.
 *
 * Output options:
 * 1) Decimal (ASCII code):
 *    `Serial.println(incomingByte, DEC);`
 *    Example: sending 'G' prints 71.
 *
 * 2) Character:
 *    `Serial.println((char)incomingByte);`
 *    Example: sending 'G' prints G.
 */
void loop() {
  if (Serial.available() > 0) {       // If data is sent
    incomingByte = Serial.read();     // Read one incoming byte
    Serial.print("I received: ");

    // Option A: print as decimal number (ASCII code)
    // Serial.println(incomingByte, DEC);

    // Option B: print as character
    Serial.println((char)incomingByte);
  }
}
