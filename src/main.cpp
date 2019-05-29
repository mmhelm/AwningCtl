/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "OneButton.h"
#include "Arduino.h"

#define DELAY_BUTTON_PRESSED 7500
#define DELAY_POWER_STATE 1000
#define DELAY_LOOP 10

#define PIN_POWER 12
#define PIN_UP 11
#define PIN_DOWN 10

#define BUTTON_UP 9
#define BUTTON_DOWN 8

typedef enum {
  UP,
  DOWN
}
Direction;

typedef enum {
  ON,
  OFF
}
Power;

OneButton buttonUp(BUTTON_UP, false);
OneButton buttonDown(BUTTON_DOWN, false);

void power(Power power) {
  switch (power) {
  case ON:
    digitalWrite(PIN_POWER, HIGH);
    break;
  case OFF:
    digitalWrite(PIN_POWER, LOW);
    break;
  default:
    break;
  }
}

void awning(Direction direction) {
  switch (direction) {
  case UP:
    digitalWrite(PIN_UP, HIGH);
    delay(DELAY_BUTTON_PRESSED);
    digitalWrite(PIN_UP, LOW);
    break;
  case DOWN:
    digitalWrite(PIN_DOWN, HIGH);
    delay(DELAY_BUTTON_PRESSED);
    digitalWrite(PIN_DOWN, LOW);
    break;  
  default:
    break;
  }
}

void moveUp() {
  power(ON);
  delay(DELAY_POWER_STATE);
  awning(UP);
  delay(DELAY_POWER_STATE);
  power(OFF);
}

void moveDown() {
  power(ON);
  delay(DELAY_POWER_STATE);
  awning(DOWN);
  delay(DELAY_POWER_STATE);
  power(OFF);
}

void setup()
{
  pinMode(PIN_POWER, OUTPUT);
  pinMode(PIN_UP, OUTPUT);
  pinMode(PIN_DOWN, OUTPUT);

  buttonUp.attachClick(moveUp);
  buttonDown.attachClick(moveDown);
}

void loop() {
  buttonUp.tick();
  buttonDown.tick();

  delay(DELAY_LOOP);
}