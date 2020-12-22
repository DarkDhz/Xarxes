
#include "ESP8266WiFi.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000);
  Serial.println("Setup done");

}

void loop() {
  Serial.println("Scan start");
  // detect nearly networks
  int n = WiFi.scanNetworks();
  Serial.println("Scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    // print info of all networks
    for (int i = 0; i < n; i++) {
      Serial.print(i+1);
      Serial.print(" ");
      // print the name of the network
      Serial.print(WiFi.SSID(i));
      Serial.print("(");
      // print the RSSI value of the network
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      // print * if the network has any type of encryption
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("***************");
  delay(5000);


}
