#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(115200); // other common is 9600 - this is comm speed
  Serial.println("Starting Reads");
  digitalWrite(LED_BUILTIN, 1);
}

int ledBrightness = 0;
int ledValue = 0;

void loop() {
  delay(250);
  int reading = analogRead(A0);
  ledValue = 255 - (int)((reading / 4095.0) * 255);

  Serial.print("Result: ");
  Serial.print(reading);
  Serial.print(" | LED: ");
  Serial.println(ledValue);
  Serial.println(" ");

  analogWrite(LED_BUILTIN, ledValue);
  ledBrightness = (ledBrightness + 1) % 256;
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}