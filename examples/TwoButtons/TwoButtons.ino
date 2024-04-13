/*
 * 
 * Example with two buttons. 
 * One on hardware pin 1 and the other on pin 2.
 * Both buttons have a different action when clicked
 * 
 */

// Integrate the library into your program
#include <TinyButton.h>

// Define the pins of your buttons
#define FIRST_BUTTON_PIN 1
#define SECOND_BUTTON_PIN 2

// Create and name your buttons
TinyButton myFirstButton(FIRST_BUTTON_PIN);
TinyButton mySecondButton(SECOND_BUTTON_PIN);

void setup() {
  // Add the respective function to each button that is to be executed on click
  myFirstButton.attachClick(myFirstClickFunction);
  mySecondButton.attachClick(mySecondClickFunction);
}

void loop() {
  // The tick() functions must be called in the loop for both buttons
  myFirstButton.tick();
  mySecondButton.tick();
}

// Click function for the first button
void myFirstClickFunction() {
  // Insert your code here that you want to execute with a click
}

// Click function for the second button
void mySecondClickFunction() {
  // Insert your code here that you want to execute with a click
}