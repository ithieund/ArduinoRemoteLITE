// Commands
const char CMD_STOP = '0';
const char CMD_FORWARD = 'w';
const char CMD_BACKWARD = 's';
const char CMD_FORWARD_LEFT = 'a';
const char CMD_FORWARD_RIGHT = 'd';
const char CMD_BACKWARD_LEFT = '[';
const char CMD_BACKWARD_RIGHT = 'o';
const char CMD_TURN_ARROUND = 'x';
const char CMD_LIGHT_ON = 'v';
const char CMD_LIGHT_OFF = 'b';
const char CMD_HEAD_LIGHT_ON = '1';
const char CMD_HEAD_LIGHT_OFF = '2';
const char CMD_BACK_LIGHT_ON = '3';
const char CMD_BACK_LIGHT_OFF = '4';
const char CMD_ALL_LIGHTS_OFF = '5';
const char CMD_HORN_ON = '^';
const char CMD_HORN_OFF = '.';

// Constants
const char RELAY_ON = 1;        // Relay on
const char RELAY_OFF = 0;       // Relay off
const byte MAX_POWER = 255;
const byte MOTOR_POWER = 200;   // From 0 to 255
const byte TURN_POWER = 35;     // From 0 to 255

// Ports
const char PORT_LIGHT = 2;      // Blue
const char PORT_HL_LIGHT = 3;   // Yellow
const char PORT_HR_LIGHT = 4;   // Orange
const char PORT_MOTOR_A_1 = 5;  // Black
const char PORT_MOTOR_A_2 = 6;  // White
const char PORT_BL_LIGHT = 7;   // Broun
const char PORT_BR_LIGHT = 8;   // Red
const char PORT_MOTOR_B_1 = 9;  // Purple
const char PORT_MOTOR_B_2 = 10; // Gray
const char PORT_HORN = 11;      // Green

char cmd = '_';

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  digitalWrite(PORT_LIGHT, RELAY_OFF);
  digitalWrite(PORT_HORN, RELAY_OFF);
  digitalWrite(PORT_HL_LIGHT, RELAY_OFF);
  digitalWrite(PORT_HR_LIGHT, RELAY_OFF);
  digitalWrite(PORT_BL_LIGHT, RELAY_OFF);
  digitalWrite(PORT_BR_LIGHT, RELAY_OFF);
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();
    Serial.println("Command: " + cmd);
    
    switch (cmd) {
      case CMD_STOP:
        digitalWrite(PORT_MOTOR_A_1, LOW);
        digitalWrite(PORT_MOTOR_A_2, LOW);
        digitalWrite(PORT_MOTOR_B_1, LOW);
        digitalWrite(PORT_MOTOR_B_2, LOW);
        digitalWrite(PORT_HL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_HR_LIGHT, RELAY_OFF);
        digitalWrite(PORT_BL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_BR_LIGHT, RELAY_OFF);
        break;
      case CMD_FORWARD:
        analogWrite(PORT_MOTOR_A_1, MOTOR_POWER);
        analogWrite(PORT_MOTOR_A_2, LOW);
        analogWrite(PORT_MOTOR_B_1, MOTOR_POWER);
        analogWrite(PORT_MOTOR_B_2, LOW);
        break;
      case CMD_BACKWARD:
        analogWrite(PORT_MOTOR_A_1, LOW);
        analogWrite(PORT_MOTOR_A_2, MOTOR_POWER);
        analogWrite(PORT_MOTOR_B_1, LOW);
        analogWrite(PORT_MOTOR_B_2, MOTOR_POWER);
        break;
      case CMD_FORWARD_LEFT:
        analogWrite(PORT_MOTOR_A_1, TURN_POWER);
        analogWrite(PORT_MOTOR_A_2, LOW);
        analogWrite(PORT_MOTOR_B_1, MAX_POWER);
        analogWrite(PORT_MOTOR_B_2, LOW);
        
        digitalWrite(PORT_HL_LIGHT, RELAY_ON);
        digitalWrite(PORT_HR_LIGHT, RELAY_OFF);
        digitalWrite(PORT_BL_LIGHT, RELAY_ON);
        digitalWrite(PORT_BR_LIGHT, RELAY_OFF);
        break;
      case CMD_FORWARD_RIGHT:
        analogWrite(PORT_MOTOR_A_1, MAX_POWER);
        analogWrite(PORT_MOTOR_A_2, LOW);
        analogWrite(PORT_MOTOR_B_1, TURN_POWER);
        analogWrite(PORT_MOTOR_B_2, LOW);

        digitalWrite(PORT_HL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_HR_LIGHT, RELAY_ON);
        digitalWrite(PORT_BL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_BR_LIGHT, RELAY_ON);
        break;
      case CMD_BACKWARD_LEFT:
        analogWrite(PORT_MOTOR_A_1, LOW);
        analogWrite(PORT_MOTOR_A_2, TURN_POWER);
        analogWrite(PORT_MOTOR_B_1, LOW);
        analogWrite(PORT_MOTOR_B_2, MAX_POWER);

        digitalWrite(PORT_HL_LIGHT, RELAY_ON);
        digitalWrite(PORT_HR_LIGHT, RELAY_OFF);
        digitalWrite(PORT_BL_LIGHT, RELAY_ON);
        digitalWrite(PORT_BR_LIGHT, RELAY_OFF);
        break;
      case CMD_BACKWARD_RIGHT:
        analogWrite(PORT_MOTOR_A_1, LOW);
        analogWrite(PORT_MOTOR_A_2, MAX_POWER);
        analogWrite(PORT_MOTOR_B_1, LOW);
        analogWrite(PORT_MOTOR_B_2, TURN_POWER);

        digitalWrite(PORT_HL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_HR_LIGHT, RELAY_ON);
        digitalWrite(PORT_BL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_BR_LIGHT, RELAY_ON);
        break;
      case CMD_TURN_ARROUND:
        analogWrite(PORT_MOTOR_A_1, MOTOR_POWER);
        analogWrite(PORT_MOTOR_A_2, LOW);
        analogWrite(PORT_MOTOR_B_1, TURN_POWER + 10);
        analogWrite(PORT_MOTOR_B_2, LOW);

        digitalWrite(PORT_HL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_HR_LIGHT, RELAY_ON);
        digitalWrite(PORT_BL_LIGHT, RELAY_OFF);
        digitalWrite(PORT_BR_LIGHT, RELAY_ON);
        break;
      case CMD_LIGHT_ON:
        digitalWrite(PORT_LIGHT, RELAY_ON);
        break;
      case CMD_LIGHT_OFF:
        digitalWrite(PORT_LIGHT, RELAY_OFF);
        break;
      case CMD_HEAD_LIGHT_ON:
         digitalWrite(PORT_HL_LIGHT, RELAY_ON);
         digitalWrite(PORT_HR_LIGHT, RELAY_ON);
        break;
      case CMD_HEAD_LIGHT_OFF:
         digitalWrite(PORT_HL_LIGHT, RELAY_OFF);
         digitalWrite(PORT_HR_LIGHT, RELAY_OFF);
        break;
      case CMD_BACK_LIGHT_ON:
         digitalWrite(PORT_BL_LIGHT, RELAY_ON);
         digitalWrite(PORT_BR_LIGHT, RELAY_ON);
        break;
      case CMD_BACK_LIGHT_OFF:
         digitalWrite(PORT_BL_LIGHT, RELAY_OFF);
         digitalWrite(PORT_BR_LIGHT, RELAY_OFF);
        break;
      case CMD_ALL_LIGHTS_OFF:
         digitalWrite(PORT_HL_LIGHT, RELAY_OFF);
         digitalWrite(PORT_HR_LIGHT, RELAY_OFF);
         digitalWrite(PORT_BL_LIGHT, RELAY_OFF);
         digitalWrite(PORT_BR_LIGHT, RELAY_OFF);
        break;
      case CMD_HORN_ON:
        digitalWrite(PORT_HORN, RELAY_ON);
        break;
      case CMD_HORN_OFF:
        digitalWrite(PORT_HORN, RELAY_OFF);
        break;
      default:
        break;
    }
  }
}
