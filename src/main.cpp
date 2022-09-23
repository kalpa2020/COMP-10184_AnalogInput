// I, Kalpa Wickramathunga (000378875), certify that this is my original work.

#include <Arduino.h>

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop() {
  int iVal;
  float oVal;
  String judgement;

  // read digitized value from the D1 Mini's A/D converter
  iVal = analogRead(A0);
  
  // calculate output value
  oVal = (iVal * 50) / 1024;

  if (oVal < 10) {
    judgement = "Cold!";
  } else if (oVal > 10 && oVal < 15) {
    judgement = "Cool";
  } else if (oVal > 15 && oVal < 25) {
    judgement = "Perfect";
  } else if (oVal > 25 && oVal < 30) {
    judgement = "Warm";
  } else if (oVal > 30 && oVal < 35) {
    judgement = "Hot";
  } else if (oVal > 35) {
    judgement = "Too Hot!";
  }

  // print value to the USB port
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temperature input of " + String(oVal) + " deg. C, which is " + judgement);

  // wait 2 seconds (2000 ms)
  delay(2000);
}