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

#include "TinyButton.h"

// Initialization of the button
TinyButton::TinyButton(byte pin) {
	pinMode(pin, INPUT);
	_pin = pin;
}

void TinyButton::tick() {
  bool currentState = digitalRead(_pin);
  unsigned long currentMillis = millis();

  // Check whether the button status has changed
  if (currentState != _lastState) {
    _lastChangeTime = currentMillis;
  }

  // Check whether the debounce time has expired
  if ((currentMillis - _lastChangeTime) > _debounceDelay) {
    
    // If the button is pressed and was not pressed before
    if (currentState == LOW && !_buttonPressed) {
      _buttonPressed = true;
      _buttonPressTime = currentMillis;  // Zeitpunkt des Drückens speichern
      _longPressDetected = false;
    } 
    
    // When the button is released
    else if (currentState == HIGH && _buttonPressed) {
      _buttonPressed = false;

      // Was a long button click recognized?
      if ((currentMillis - _buttonPressTime) >= 4000) {
        _longPressDetected = true;
        if (_longClickFunc) _longClickFunc();
      } 
      
      // Was a normal button click recognized?
      else if (!_longPressDetected) {
        if (_clickFunc) _clickFunc();
      }
    }
  }

  // Saving the current button status
  _lastState = currentState;
} 

// Register callback function for a normal button click
void TinyButton::attachClick(callbackFunction newFunction) {
  _clickFunc = newFunction;
}

// Register callback function for a long button click
void TinyButton::attachLongClick(callbackFunction newFunction) {
  _longClickFunc = newFunction;
}
