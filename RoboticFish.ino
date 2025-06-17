#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

#define BLYNK_PRINT Serial

// Replace with your network credentials and Blynk token
char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

Servo finServo;

int basePos = 90;
int amplitude = 30;
int frequency = 1;  // oscillations per second
int turnOffset = 0;

unsigned long lastMoveTime = 0;
int direction = 1;
int currentPos = 90;

// Virtual pin handlers for sliders
BLYNK_WRITE(V0) {  // Amplitude slider
  amplitude = param.asInt();
  amplitude = constrain(amplitude, 0, 90);
}

BLYNK_WRITE(V1) {  // Frequency slider
  frequency = param.asInt();
  frequency = constrain(frequency, 1, 10);
}

BLYNK_WRITE(V2) {  // Turn offset slider
  turnOffset = param.asInt();
  turnOffset = constrain(turnOffset, -30, 30);
}

void setup() {
  Serial.begin(115200);
  finServo.attach(D4);  // Attach servo to pin D4 (GPIO2)
  Blynk.begin(auth, ssid, pass);
  finServo.write(basePos);
}

void loop() {
  Blynk.run();

  unsigned long currentTime = millis();
  int interval = 1000 / (frequency * 2);  // Half period for oscillation

  if (currentTime - lastMoveTime >= interval) {
    lastMoveTime = currentTime;
    currentPos = basePos + turnOffset + direction * amplitude;
    finServo.write(currentPos);
    direction = -direction;
  }
}
