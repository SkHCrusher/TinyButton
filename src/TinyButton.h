/* 
   TinyButton - This library simplifies a click function for ATTiny projects. 
   It was specially created in a minimalistic way for e.g. the ATTiny 412.

   Functions:
   - Software debounce
   - Simple click
   - Long click

   © 2024 Tobias Stewen

   Licensed under the MIT License. See LICENSE file in the project root for full license information.

   Developed by Tobias Stewen
*/

#ifndef TinyButton_h

#define TinyButton_h
#include "Arduino.h"

extern "C" {
typedef void (*callbackFunction)(void);
}

class TinyButton {
  public:
  	TinyButton(byte pin);
  	void tick();
  	void attachClick(callbackFunction newFunction);
    void attachLongClick(callbackFunction newFunction);
  private:
    bool
      _buttonPressed,         // Was the button pressed?
      _longPressDetected,     // Has a long button click been registered?
      _state,                 // Current button status
      _lastState;             // Last button status
    byte
      _pin,                   // Hardware pin number
      _debounceDelay = 50;    // Number of msecs for debounce times.
    unsigned long 
      _lastChangeTime,        // How long has it been since the button status has changed
      _buttonPressTime;       // How long was the button pressed
    callbackFunction
      _clickFunc = NULL,      // Callback function for a normal click
      _longClickFunc = NULL;  // Callback function for a long click
};

#endif
