# TinyButton Library [![Build Arduino Sketch](https://github.com/SkHCrusher/TinyButton/actions/workflows/arduino_build.yml/badge.svg)](https://github.com/SkHCrusher/TinyButton/actions/workflows/arduino_build.yml) [![Arduino Lint](https://github.com/SkHCrusher/TinyButton/actions/workflows/arduino_lint.yml/badge.svg)](https://github.com/SkHCrusher/TinyButton/actions/workflows/arduino_lint.yml)

The TinyButton Arduino library offers minimal functions for simple button interactions.

I created it because all other libraries on an ATtiny412 together with the tinyNeoPixel library led to errors.

## Features

### Software debounce

Prevent unwanted multiple triggers caused by button bouncing with the **software debounce function**. This technology stabilizes the input signal of your button by ignoring short-term fluctuations caused by mechanical bouncing of the contacts.

### Simple click

Enables simple button presses to be recognized with the **Click function**. This feature makes it easy to set up a responsive and reliable click mechanism for your applications. 

### Long click

Expand the interactivity of your projects with the **long click function**. This function makes it possible to recognize longer keystrokes and trigger special actions based on them. Ideal for menu navigation, advanced user input or special modes that require a longer confirmation.

## Functions

- tick()
- attachClick()
- attachLongClick()

## Examples

You can find the examples in the "examples" folder.

### Simple Button

```cpp
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
```

## **Thanks to**

The inspiration for this library comes from: https://github.com/mathertel/OneButton 

Unfortunately, his Tiny version does not work with my ATtiny412 NeoPixel project either. Nevertheless, I would like to express my thanks here.

## **License** 

This library is published under the MIT license. This ensures maximum freedom in the use and further development of the code. You may modify, distribute and use the software for private and commercial purposes as long as the copyright notice and license information are retained. For more details, please take a look at the **LICENSE file** in the root directory of our repository.
