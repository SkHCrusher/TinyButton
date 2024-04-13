/*
 * 
 * Example with one button on hardware pin 1 and single click function
 * 
 */

// Integrate the library into your program
#include <TinyButton.h>

// Define the pin of your button
#define BUTTON_PIN 1

// Create and name your button
TinyButton myButton(BUTTON_PIN);

void setup() {
  // Assign the function that is to be executed on a click here
  myButton.attachClick(myClickFunction);
}

void loop() {
  // This function is required in the loop for the logic of the button
  myButton.tick();
}

// Own function to be executed with a click
void myClickFunction() {
  // Insert your code here that you want to execute with a click
}