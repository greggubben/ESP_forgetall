/*
 * Reset the ESP8266 so it forgets everything
 */
#include <FS.h>                   //this needs to be first, or it all crashes and burns...
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager


void setup() {
  // init serial for debugging
  Serial.begin(115200);
  Serial.println("Resetting the ESP to forget everything.");
  Serial.println();

  Serial.print("Resetting WifiManager...  ");
  WiFiManager wifiManager;
  wifiManager.resetSettings();  // reset WiFi settings
  Serial.println("Done.");

  Serial.print("Formatting SPIFFS(FS)...  ");
  SPIFFS.format();              // clean FS
  Serial.println("Done.");

  Serial.print("Erasing ESP Config...     ");
  ESP.eraseConfig();
  Serial.println("Done.");

  //ESP.reset()

  Serial.println();
  Serial.println("Please load a real program now.  :-)");
}

void loop() {
  // Nothing to do here

}
