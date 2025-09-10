#include <Arduino.h>

void setup() {
  Serial.begin(115200); // other common is 9600 - this is Serial comm speed
  Serial.println("Starting Reads");
}

int ledBrightness = 0;
int ledValue = 0;

void loop() {
  delay(250);
  int reading = analogRead(A0); // Photo resistor on A0 w/ 2.2kOhm resistor to ground
  ledValue = 255 - (int)((reading / 4095.0) * 255);

  Serial.print("Result: ");
  Serial.print(reading);
  Serial.print(" | LED: ");
  Serial.println(ledValue);
  Serial.println(" ");

  analogWrite(LED_BUILTIN, ledValue);
  ledBrightness = (ledBrightness + 1) % 256;
}