/*
* Controls home devices with Arduino Remote LITE in Relay Control Mode via Wifi 
* Author: Top Hot Apps
* Website: https://hotapps.top
* Email: support@hotapps.top
* This sketch runs with Arduino Remote LITE. Download: https://play.google.com/store/apps/details?id=it.hieund.arduino_remote_lite
*/

#include <WiFi.h>

// Ports
const char PORT_RELAY1 = 13;
const char PORT_RELAY2 = 12;
const char PORT_RELAY3 = 14;
const char PORT_RELAY4 = 27;
const char PORT_RELAY5 = 26;
const char PORT_RELAY6 = 25;
const char PORT_RELAY7 = 33;
const char PORT_RELAY8 = 32;  

// Constants
const char RELAY_ON = 0;  // Relay on
const char RELAY_OFF = 1; // Relay off

// Variables
WiFiServer server(80);
char ssid[] = "YOUR-WIFI-SSID";         // Change this value before uploading
char password[] = "YOUR-WIFI-PASSWORD"; // Change this value before uploading
String request = "";

// Util function to setup wifi connection
void setupWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  // Wait until the connection is establed
  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  // Show connection info
  Serial.println("");
  Serial.println("Connected to Wifi.");
  Serial.print("WebServer URL: http://");
  Serial.println(WiFi.localIP());

  // Start the web server
  server.begin();
}

// Setup when Arduino boots
void setup() {
  Serial.begin(9600);
  
  // Sets all ports as OUTPUT
  pinMode(PORT_RELAY1, OUTPUT);
  pinMode(PORT_RELAY2, OUTPUT);
  pinMode(PORT_RELAY3, OUTPUT);
  pinMode(PORT_RELAY4, OUTPUT);
  pinMode(PORT_RELAY5, OUTPUT);
  pinMode(PORT_RELAY6, OUTPUT);
  pinMode(PORT_RELAY7, OUTPUT);
  pinMode(PORT_RELAY8, OUTPUT);

  // Sets default state as OFF
  digitalWrite(PORT_RELAY1, RELAY_OFF);
  digitalWrite(PORT_RELAY2, RELAY_OFF);
  digitalWrite(PORT_RELAY3, RELAY_OFF);
  digitalWrite(PORT_RELAY4, RELAY_OFF);
  digitalWrite(PORT_RELAY5, RELAY_OFF);
  digitalWrite(PORT_RELAY6, RELAY_OFF);
  digitalWrite(PORT_RELAY7, RELAY_OFF);
  digitalWrite(PORT_RELAY8, RELAY_OFF);

  setupWiFi();
}

// Repeats continuously after boot
void loop() {
  WiFiClient client = server.available();
  if(!client) return;

  // Listen to client request
  String currentLine = "";
  
  while(client.connected()) {
    if(client.available()) {
      char c = client.read();
      request += c;
      
      if(c != '\r' && c != '\n') currentLine += c;
      
      if (c == '\n') {
        if(currentLine.length() == 0) break;
        currentLine = "";
      }
    }
  }

  // Handle client request
  if(request.length() > 0) {
    // Control Relay 1
    if(request.indexOf("1:0") >= 0) {
      digitalWrite(PORT_RELAY1, RELAY_OFF);
      Serial.println("Relay 1: Off");
    }

    if(request.indexOf("1:1") >= 0) {
      digitalWrite(PORT_RELAY1, RELAY_ON);
      Serial.println("Relay 1: On");
    }

    // Control Relay 2
    if(request.indexOf("2:0") >= 0) {
      digitalWrite(PORT_RELAY2, RELAY_OFF);
      Serial.println("Relay 2: Off");
    }

    if(request.indexOf("2:1") >= 0) {
      digitalWrite(PORT_RELAY2, RELAY_ON);
      Serial.println("Relay 1: On");
    }

    // Control Relay 3
    if(request.indexOf("3:0") >= 0) {
      digitalWrite(PORT_RELAY3, RELAY_OFF);
      Serial.println("Relay 3: Off");
    }

    if(request.indexOf("3:1") >= 0) {
      digitalWrite(PORT_RELAY3, RELAY_ON);
      Serial.println("Relay 3: On");
    }

    // Control Relay 4
    if(request.indexOf("4:0") >= 0) {
      digitalWrite(PORT_RELAY4, RELAY_OFF);
      Serial.println("Relay 4: Off");
    }

    if(request.indexOf("4:1") >= 0) {
      digitalWrite(PORT_RELAY4, RELAY_ON);
      Serial.println("Relay 4: On");
    }

    // Control Relay 5
    if(request.indexOf("5:0") >= 0) {
      digitalWrite(PORT_RELAY5, RELAY_OFF);
      Serial.println("Relay 5: Off");
    }

    if(request.indexOf("5:1") >= 0) {
      digitalWrite(PORT_RELAY5, RELAY_ON);
      Serial.println("Relay 5: On");
    }

    // Control Relay 6
    if(request.indexOf("6:0") >= 0) {
      digitalWrite(PORT_RELAY6, RELAY_OFF);
      Serial.println("Relay 6: Off");
    }

    if(request.indexOf("6:1") >= 0) {
      digitalWrite(PORT_RELAY6, RELAY_ON);
      Serial.println("Relay 6: On");
    }

    // Control Relay 7
    if(request.indexOf("7:0") >= 0) {
      digitalWrite(PORT_RELAY7, RELAY_OFF);
      Serial.println("Relay 7: Off");
    }

    if(request.indexOf("7:1") >= 0) {
      digitalWrite(PORT_RELAY7, RELAY_ON);
      Serial.println("Relay 7: On");
    }

    // Control Relay 8
    if(request.indexOf("8:0") >= 0) {
      digitalWrite(PORT_RELAY8, RELAY_OFF);
      Serial.println("Relay 8: Off");
    }

    if(request.indexOf("8:1") >= 0) {
      digitalWrite(PORT_RELAY8, RELAY_ON);
      Serial.println("Relay 8: On");
    }

    // Reset string to be ready for next request
    request = "";

    // Send response to client
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE html><html>");
    client.println("<head><link rel=\"icon\" href=\"data:,\"><title>Arduino Remote LITE - ESP32</title></head>");
    client.println("<body></body></html>");
  }

  // Close connection to client
  client.stop();
}
