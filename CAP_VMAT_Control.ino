/*
 * ====================================================================
 * Project: Real-Time CAP-VMAT Synchronization System
 * Team: Plasma Sync
 * Team ID: HSC|TN|01586
 * 
 * Description: 
 * This Arduino code reads a 600 PPR rotary encoder to simulate the 
 * rotation of a VMAT gantry. It triggers a 5V opto-isolated relay to 
 * activate a high-voltage Cold Atmospheric Plasma (CAP) supply 
 * ONLY when the simulated gantry angle is between 0 and 90 degrees.
 * ====================================================================
 */

// Pin Definitions
const int encoderCLK = 2;  // Rotary encoder Clock pin
const int encoderDT = 3;   // Rotary encoder Data pin
const int relayPin = 7;    // Relay control pin
const int ledPin = 13;     // Status LED pin

// Variables
int encoderPosition = 0;
int lastEncoderCLK = 0;

void setup() {
  // Initialize pins
  pinMode(encoderCLK, INPUT);
  pinMode(encoderDT, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // Safety default: Plasma OFF
  digitalWrite(relayPin, HIGH); 
  digitalWrite(ledPin, LOW);
  
  // Start serial communication for debugging
  Serial.begin(9600);
  Serial.println("CAP-VMAT System Initialized...");
}

void loop() {
  // Read the rotary encoder state
  int currentCLK = digitalRead(encoderCLK);
  
  // If the encoder has moved
  if (currentCLK != lastEncoderCLK) {
    // Determine direction of rotation
    if (digitalRead(encoderDT) != currentCLK) {
      encoderPosition++;
    } else {
      encoderPosition--;
    }
    
    // Print simulated gantry angle
    Serial.print("Gantry Angle: ");
    Serial.print(encoderPosition);
    Serial.println(" degrees");
    
    lastEncoderCLK = currentCLK;
  }

  // Control Logic: Trigger plasma only between 0 and 90 degrees
  if (encoderPosition >= 0 && encoderPosition <= 90) {
    digitalWrite(relayPin, LOW);  // Relay ON (Plasma Fires)
    digitalWrite(ledPin, HIGH);   // Turn ON status LED
  } else {
    digitalWrite(relayPin, HIGH); // Relay OFF (Plasma Stops)
    digitalWrite(ledPin, LOW);    // Turn OFF status LED
  }
  
  delay(10); // Small delay for stability
}
