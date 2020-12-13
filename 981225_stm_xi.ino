#include "stm8s_exti.h"
#include "stm8s_conf.h"

const byte ledPin = PD3;
const byte interruptPin = PD4;
volatile byte state = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_FALL);
  }

void loop() {
  
  digitalWrite(ledPin, !digitalRead(ledPin));
  delay(2000);
}

void blink() {
  
}
