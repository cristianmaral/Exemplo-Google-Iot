#include "backoff.h"
#include "esp32_wifi.h"

#define LED_BUILTIN 2

// Arduino functions
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  setupWifi();
  Serial.println("Enviando estado para o Cloud");
  setState("Hello World");
}

void loop() {
  if (backoff()) {
    getConfig();
    sendTelemetry();
    delay(1000);
  }
}
