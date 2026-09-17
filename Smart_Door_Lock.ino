#include <Keypad.h>
#include <Servo.h>

// --- Servo Configuration ---
Servo myServo;
const int servoPin = 10;
bool isLocked = true; // Tracks the current state of the lock

// --- Keypad Configuration ---
const byte ROWS = 4; 
const byte COLS = 4; 

// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW1, ROW2, ROW3 and ROW4 to these Arduino pins.
byte rowPins[ROWS] = {9, 8, 7, 6}; 
// Connect keypad COL1, COL2, COL3 and COL4 to these Arduino pins.
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// --- Password Configuration ---
const String correctPassword = "1237"; // Set your 4-digit password here
String enteredPassword = "";

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  
  // Initialize to the locked position on startup
  lockDoor();
  
  Serial.println("System Ready.");
  Serial.println("Enter 4-digit password and press '#' to toggle lock.");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // If the submit key '#' is pressed, check the password
    if (key == '#') {
      Serial.println(); // Move to next line in Serial Monitor
      
      if (enteredPassword == correctPassword) {
        Serial.println("Password Correct!");
        
        // Toggle the lock state
        if (isLocked) {
          unlockDoor();
        } else {
          lockDoor();
        }
      } else {
        Serial.println("Incorrect Password. Try again.");
      }
      
      // Reset the input buffer for the next attempt
      enteredPassword = ""; 
      
    } 
    // If the clear key '*' is pressed, reset the current input
    else if (key == '*') {
      enteredPassword = "";
      Serial.println();
      Serial.println("Input cleared.");
    } 
    // Otherwise, append the pressed key to the password string
    else {
      enteredPassword += key;
      Serial.print("*"); // Print asterisk to hide password in serial monitor
    }
  }
}

// Function to lock the servo
void lockDoor() {
  myServo.write(90); // Move servo to 90 degrees (Adjust based on your physical lock)
  isLocked = true;
  Serial.println("Status: LOCKED");
}

// Function to unlock the servo
void unlockDoor() {
  myServo.write(0);  // Move servo to 0 degrees (Adjust based on your physical lock)
  isLocked = false;
  Serial.println("Status: UNLOCKED");
}
