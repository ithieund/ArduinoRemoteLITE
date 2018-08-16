/*
* Controls home devices with Arduino Remote LITE in Relay Control Mode via Bluetooth 
* Author: Top Hot Apps
* Website: https://hotapps.top
* Email: support@hotapps.top
* This sketch runs with Arduino Remote LITE. Download: https://play.google.com/store/apps/details?id=it.hieund.arduino_remote_lite
*/

// Ports
const char PORT_RELAY1 = 2;
const char PORT_RELAY2 = 3;
const char PORT_RELAY3 = 4;
const char PORT_RELAY4 = 5;
const char PORT_RELAY5 = 6;
const char PORT_RELAY6 = 7;
const char PORT_RELAY7 = 8;
const char PORT_RELAY8 = 9;

// Commands
const String CMD_RL1_ON = "1:1";
const String CMD_RL1_OFF = "1:0";
const String CMD_RL2_ON = "2:1";
const String CMD_RL2_OFF = "2:0";
const String CMD_RL3_ON = "3:1";
const String CMD_RL3_OFF = "3:0";
const String CMD_RL4_ON = "4:1";
const String CMD_RL4_OFF = "4:0";
const String CMD_RL5_ON = "5:1";
const String CMD_RL5_OFF = "5:0";
const String CMD_RL6_ON = "6:1";
const String CMD_RL6_OFF = "6:0";
const String CMD_RL7_ON = "7:1";
const String CMD_RL7_OFF = "7:0";
const String CMD_RL8_ON = "8:1";
const String CMD_RL8_OFF = "8:0";

// Constants
const char RELAY_ON = 0;   // Relay on
const char RELAY_OFF = 1;  // Relay off

String cmd = "";

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
}

// Repeats continuously after boot
void loop() {
  if (Serial.available()) {
    cmd = Serial.readString();
    cmd.trim();
    Serial.println("Command: " + cmd);

    // Control Relay 1
    if (cmd == CMD_RL1_ON) {
      digitalWrite(PORT_RELAY1, RELAY_ON);
    }

    if (cmd == CMD_RL1_OFF) {
      digitalWrite(PORT_RELAY1, RELAY_OFF);
    }

    // Control Relay 2
    if (cmd == CMD_RL2_ON) {
      digitalWrite(PORT_RELAY2, RELAY_ON);
    }

    if (cmd == CMD_RL2_OFF) {
      digitalWrite(PORT_RELAY2, RELAY_OFF);
    }

    // Control Relay 3
    if (cmd == CMD_RL3_ON) {
      digitalWrite(PORT_RELAY3, RELAY_ON);
    }

    if (cmd == CMD_RL3_OFF) {
      digitalWrite(PORT_RELAY3, RELAY_OFF);
    }

    // Control Relay 4
    if (cmd == CMD_RL4_ON) {
      digitalWrite(PORT_RELAY4, RELAY_ON);
    }

    if (cmd == CMD_RL4_OFF) {
      digitalWrite(PORT_RELAY4, RELAY_OFF);
    }

    // Control Relay 5
    if (cmd == CMD_RL5_ON) {
      digitalWrite(PORT_RELAY5, RELAY_ON);
    }

    if (cmd == CMD_RL5_OFF) {
      digitalWrite(PORT_RELAY5, RELAY_OFF);
    }

    // Control Relay 6
    if (cmd == CMD_RL6_ON) {
      digitalWrite(PORT_RELAY6, RELAY_ON);
    }

    if (cmd == CMD_RL6_OFF) {
      digitalWrite(PORT_RELAY6, RELAY_OFF);
    }

    // Control Relay 7
    if (cmd == CMD_RL7_ON) {
      digitalWrite(PORT_RELAY7, RELAY_ON);
    }

    if (cmd == CMD_RL7_OFF) {
      digitalWrite(PORT_RELAY7, RELAY_OFF);
    }

    // Control Relay 8
    if (cmd == CMD_RL8_ON) {
      digitalWrite(PORT_RELAY8, RELAY_ON);
    }

    if (cmd == CMD_RL8_OFF) {
      digitalWrite(PORT_RELAY8, RELAY_OFF);
    }
  }
}
