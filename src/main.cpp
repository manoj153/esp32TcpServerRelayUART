#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "manoj27";
const char* password =  "manoj1534";

WiFiServer wifiServer(80);


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    delay(500);

    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
 
  wifiServer.begin();
}


void loop() {
    // put your main code here, to run repeatedly:
    WiFiClient client = wifiServer.available();
    
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        client.write(c);
      }
 
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }

}