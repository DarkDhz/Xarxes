
#include "ESP8266WiFi.h"

String ssid, pwd;

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

    wifiNetworkSelection();
    connectToWifi();
    
  }
  Serial.println("***************");
  delay(5000);

}

void connectToWifi(void){
  int contador = 0;
  char c_ssid[ssid.length()];
  char c_pwd[pwd.length()];

  // convert string to char
  ssid.toCharArray(c_ssid, ssid.length());
  pwd.toCharArray(c_pwd, pwd.length());
  // check if the device is not connected to any network
  if (WiFi.status() != WL_CONNECTED) {
    // try to connect to the network
    WiFi.begin(c_ssid, c_pwd);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting...");
      contador++;
      if (contador == 10) {
        break;
      }
    }
    // print local IP of the network
    Serial.println(WiFi.localIP());
  }
}


void wifiNetworkSelection(void){
  // get the information we need to connect to a network
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("SSID? >");
    while(!Serial.available());
    ssid = Serial.readString();
    Serial.print("SSID selected >");
    Serial.println(ssid);
    delay(1000);
    Serial.println("Password? >");
    while(!Serial.available());
    pwd = Serial.readString();
    Serial.print("PWD > ");
    Serial.println(pwd);;
  }
}
