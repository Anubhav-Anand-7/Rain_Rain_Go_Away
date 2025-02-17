#include <Servo.h>      // Library for controlling the servo motor

// Define servo and input pin numbers
const byte servoPin = 9;  // Servo motor control pin
const byte led1 = A0;       // First input pin
const byte led2 = A1;       // Second input pin
const byte led3 = A2;       // Third input pin
const byte led4 = A3;       // Fourth input pin

int pre_angle,curr_angle;

Servo myservo;         // Create a servo object

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  myservo.attach(servoPin);  // Attach the servo motor to the defined pin

  // Configure input pins as input
  pinMode(led1, INPUT);
  pinMode(led2, INPUT);
  pinMode(led3, INPUT);
  pinMode(led4, INPUT);

  pre_angle=0;
  curr_angle=0;
  myservo.write(curr_angle); // Initialize servo position to 0 degrees

}

void loop() {
  // Read the state of the 4 input pins
  int inputs[4] = {analogRead(led1), analogRead(led2), analogRead(led3), analogRead(led4)};
  
  // Define corresponding servo angles
  int angles[4] = {0, 60, 120, 180};

  curr_angle=0;
  for(int i=3;i>=0;i--){
    if(inputs[i]>501){
      curr_angle=angles[i];
      break;
    }
  }

  if(curr_angle!=pre_angle){
    myservo.write(curr_angle);
    pre_angle=curr_angle;
  }

  delay(100); // Short delay to avoid repeated triggering
}
