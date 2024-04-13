/*
 * 
 * Example with a button on hardware pin 1 
 * with a function for a normal and a long click.
 * 
 */

// Integrate the library into your program
#include <TinyButton.h>

// Define the pin of your button
#define BUTTON_PIN 1

// Create and name your button
TinyButton myButton(BUTTON_PIN);

void setup() {
  // This is the function for the normal click
  myButton.attachClick(myClickFunction);

  // This is the function for the long click
  myButton.attachLongClick(myLongClickFunction);
}

void loop() {
  // The tick() function only needs to be executed once per button, 
  // independently of the functions
  myButton.tick();
}

// Function that is triggered by a normal click
void myClickFunction() {
  // Insert your code here that you want to execute with a click
}

// Function that is triggered by a long click
void myLongClickFunction() {
  // Insert your code here that you want to execute with a click
}