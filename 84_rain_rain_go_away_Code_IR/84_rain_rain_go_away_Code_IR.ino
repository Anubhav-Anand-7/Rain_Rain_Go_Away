#include <IRremote.h>  // Library for IR remote functionality

// Define LED pin numbers
#define Led_0 12  // First LED connected to pin 12
#define Led_1 11  // Second LED connected to pin 11

// Define servo and input pin numbers

IRrecv IR(13);         // Create an IR receiver object, connected to pin 13
decode_results results; // Variable to store decoded IR signals

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  IR.enableIRIn();    // Start the IR receiver

  // Configure LED pins as output
  pinMode(Led_0, OUTPUT);
  pinMode(Led_1, OUTPUT);

  // Set initial LED states
  digitalWrite(Led_0, LOW);
  digitalWrite(Led_1, HIGH);
}

void loop() {
  // Check if an IR signal is received
  if (IR.decode(&results)) {
    uint32_t irData = results.value;  // Get the received IR signal
    Serial.println(irData, HEX);      // Print the received IR signal in hexadecimal format

    // If a specific IR code is received, toggle LED states
    if (irData == 0xBC43FF00) {
      digitalWrite(Led_0, HIGH);
      digitalWrite(Led_1, LOW);
    }

    delay(100); // Short delay to avoid repeated triggering
    IR.resume(); // Resume IR receiver for next signal
  }
}