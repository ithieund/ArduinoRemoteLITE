/*
* RGB Led Control Demo
* Author: Top Hot Apps
* Website: https://hotapps.top
* Email: support@hotapps.top
* This sketch runs with Arduino Remote LITE. Download: https://play.google.com/store/apps/details?id=it.hieund.arduino_remote_lite
*/

// Constants
const char IS_COMMON_ANODE = 1; // 0 = Common Cathode, 1 = Common Anode

// Ports
const char PORT_RED = 3;    // Should be PWM port
const char PORT_GREEN = 5;  // Should be PWM port
const char PORT_BLUE = 6;   // Should be PWM port

// Variables
char* data;
char off = 0;
int red;
int green;
int blue;

// Setup when Arduino boots
void setup() {
  Serial.begin(9600);

  // Set all ports as OUTPUT
  pinMode(PORT_RED, OUTPUT);
  pinMode(PORT_GREEN, OUTPUT);
  pinMode(PORT_BLUE, OUTPUT);

  // Set default to OFF
  if(IS_COMMON_ANODE) {
    off = 1;
  }
  
  digitalWrite(PORT_RED, off);
  digitalWrite(PORT_GREEN, off);
  digitalWrite(PORT_BLUE, off);
}

// Repeat continuously after boot
void loop() {
  if (Serial.available()) {
    String receivedString = Serial.readStringUntil('\n');
    Serial.println("RGB: " + receivedString);

    // Convert string to char*
    data = new char[receivedString.length() + 1];
    strcpy(data, receivedString.c_str());

    // Parse RGB value from string
    if (sscanf(data, "%d,%d,%d", &red, &green, &blue) == 3) {
      if(IS_COMMON_ANODE) {
        red = 255 - red;
        green = 255 - green;
        blue = 255 - blue;
      }
      
      analogWrite(PORT_RED, red);
      analogWrite(PORT_GREEN, green);
      analogWrite(PORT_BLUE, blue);
    }
  }
}
