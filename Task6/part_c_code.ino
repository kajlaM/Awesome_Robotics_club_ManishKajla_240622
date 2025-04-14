#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Pin assignments
const int buttonPin = 2;
const int potPin = A0;

// Servo motors
Servo servoA;
Servo servoB;

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables
int angle = 0;          // Potentiometer value for angle
int servoSelect = 0;    // 0 for Servo A, 1 for Servo B
bool lastButtonState = LOW;
bool currentButtonState = LOW;

void setup() {
  // Initialize servo pins
  servoA.attach(9);
  servoB.attach(10);
  
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("Servo A Active");
  
  // Set up button pin
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read button state to toggle servo selection
  currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    servoSelect = !servoSelect; // Toggle between Servo A and Servo B
    lastButtonState = HIGH;
    
    // Update LCD with active servo
    lcd.clear();
    if (servoSelect == 0) {
      lcd.print("Servo A Active");
    } else {
      lcd.print("Servo B Active");
    }
  }
  
  if (currentButtonState == LOW) {
    lastButtonState = LOW;
  }
  
  // Read potentiometer value and map to servo angle
  angle = map(analogRead(potPin), 0, 1023, 0, 180);
  
  // Set the angle of the selected servo
  if (servoSelect == 0) {
    servoA.write(angle);
  } else {
    servoB.write(angle);
  }

  // Display current angle on LCD
  lcd.setCursor(0, 1);
  lcd.print("Angle: ");
  lcd.print(angle);
  delay(100); // Small delay to avoid jitter
}
