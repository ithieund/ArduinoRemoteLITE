/*
* Controls home devices with Arduino Remote LITE in Button Mode 
* Author: Top Hot Apps
* Website: https://hotapps.top
* Email: support@hotapps.top
* This sketch runs with Arduino Remote LITE. Download: https://play.google.com/store/apps/details?id=it.hieund.arduino_remote_lite
*/

// Ports
const char PORT_LIGHT = 10;
const char PORT_FAN = 11;
const char PORT_LAMP = 12;
const char PORT_AIRCOND = 13;

// Commands
const char CMD_LIGHT_ON = '2';
const char CMD_LIGHT_OFF = '1';
const char CMD_FAN_ON = '4';
const char CMD_FAN_OFF = '3';
const char CMD_LAMP_ON = '6';
const char CMD_LAMP_OFF = '5';
const char CMD_AIRCOND_ON = '8';
const char CMD_AIRCOND_OFF = '7';

// Constants
const char RELAY_ON = 1;   // Relay on
const char RELAY_OFF = 0;  // Relay off

char cmd = '0';

// Setup when Arduino boots
void setup() {
  Serial.begin(9600);

  // Sets all ports as OUTPUT
  pinMode(PORT_LIGHT, OUTPUT);
  pinMode(PORT_FAN, OUTPUT);
  pinMode(PORT_LAMP, OUTPUT);
  pinMode(PORT_AIRCOND, OUTPUT);

  // Sets default state as OFF
  digitalWrite(PORT_LIGHT, RELAY_OFF);
  digitalWrite(PORT_FAN, RELAY_OFF);
  digitalWrite(PORT_LAMP, RELAY_OFF);
  digitalWrite(PORT_AIRCOND, RELAY_OFF);
}

// Repeats continuously after boot
void loop() {
  if (Serial.available()) {
    cmd = Serial.read();
    Serial.println("Command: " + cmd);

    switch (cmd) {
      case CMD_LIGHT_ON:
        digitalWrite(PORT_LIGHT, RELAY_ON);
        break;
      case CMD_LIGHT_OFF:
        digitalWrite(PORT_LIGHT, RELAY_OFF);
        break;
      case CMD_FAN_ON:
        digitalWrite(PORT_FAN, RELAY_ON);
        break;
      case CMD_FAN_OFF:
        digitalWrite(PORT_FAN, RELAY_OFF);
        break;
      case CMD_LAMP_ON:
        digitalWrite(PORT_LAMP, RELAY_ON);
        break;
      case CMD_LAMP_OFF:
        digitalWrite(PORT_LAMP, RELAY_OFF);
        break;
      case CMD_AIRCOND_ON:
        digitalWrite(PORT_AIRCOND, RELAY_ON);
        break;
      case CMD_AIRCOND_OFF:
        digitalWrite(PORT_AIRCOND, RELAY_OFF);
        break;
      default:
        break;
    }
  }
}
