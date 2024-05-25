// Chapter 3 - Buttons 
// Button with no resistor

// Declare the pins for the Button, the LED, and the relay
int buttonPin = 12;  // Pin connected to the button
int LED = 13;        // Pin connected to the LED
int relay = 4;       // Pin connected to the relay

int laststate = 1;   // Variable to store the last state of the button
bool toggle = false; // Variable to store the toggle state

void setup() {
  // Set buttonPin as input with an internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  // Set LED pin as output
  pinMode(LED, OUTPUT);
  // Set relay pin as output
  pinMode(relay, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop(){
  // Read the current state of the button (1 when not pressed, 0 when pressed)
  int buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);

  // Check if the button is pressed (LOW) and has changed state from the last read
  if (buttonValue == LOW && buttonValue != laststate){
    // Toggle the state
    toggle = !toggle;
    // Update the LED and relay based on the new toggle state
    togglePower(toggle);
  } else {
    // Maintain the current state of the LED and relay
    togglePower(toggle);
  }

  // Update the last state of the button
  laststate = buttonValue;
  // Small delay to debounce the button
  delay(100);
}

// Function to toggle the power of the LED and relay
void togglePower(bool supply){
  if (supply){
    // If supply is true, turn on the LED and relay
    digitalWrite(LED, HIGH);  
    digitalWrite(relay, HIGH);  
  } else {
    // If supply is false, turn off the LED and relay
    digitalWrite(LED, LOW);
    digitalWrite(relay, LOW);
  }
}
