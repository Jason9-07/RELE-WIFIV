
// *** MAIN SETTINGS ***
// Replace this block with correct template settings.
// You can find it for every template here:
//
//   https://blynk.cloud/dashboard/templates

#define BLYNK_TEMPLATE_ID "TMPL2hBSJSmmS"
#define BLYNK_TEMPLATE_NAME "LED ESP32"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

#include "BlynkEdgent.h"

#define LED_PIN 2  // Use pin 2 for LED (change it, if your board uses another pin)

#include <WiFi.h>
#include <BlynkSimpleEsp32_SSL.h>


#define RELAY1 34
#define RELAY2 19
#define RELAY3 18

// V0 is a datastream used to transfer and store LED switch state.
// Evey time you use the LED switch in the app, this function
// will listen and update the state on device
BLYNK_WRITE(V0)
{
  // Local variable `value` stores the incoming LED switch state (1 or 0)
  // Based on this value, the physical LED on the board will be on or off:
  int value = param.asInt();

  if (value == 1) {
    digitalWrite(RELAY1, HIGH);
    Serial.println("Relay 1 encendido");
    Serial.println(value);
  }
  else {
    digitalWrite(RELAY1, LOW);
    Serial.println("Relay 1 apagado");
    Serial.println(value);
  }
}


BLYNK_WRITE(V1)
{
  // Local variable `value` stores the incoming LED switch state (1 or 0)
  // Based on this value, the physical LED on the board will be on or off:
  int value = param.asInt();

  if (value == 1) {
    digitalWrite(RELAY2, HIGH);
    Serial.println("Relay 2 encendido");
    Serial.println(value);
  }
  else {
    digitalWrite(RELAY2, LOW);
    Serial.println("Relay 2 apagado");
    Serial.println(value);
  }
}

BLYNK_WRITE(V2)
{
  // Local variable `value` stores the incoming LED switch state (1 or 0)
  // Based on this value, the physical LED on the board will be on or off:
  int value = param.asInt();

  if (value == 1) {
    digitalWrite(RELAY3,HIGH );
    Serial.println("Relay 3 encendido");
    Serial.println(value);
  }
  else {
    digitalWrite(RELAY3, LOW);
    Serial.println("Relay 3 apagado");
    Serial.println(value);
  }
}


void setup()
{
  pinMode(LED_PIN, OUTPUT);

  // Debug console. Make sure you have the same baud rate selected in your serial monitor
  Serial.begin(115200);

   pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);


  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);

  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  delay(10);
}

