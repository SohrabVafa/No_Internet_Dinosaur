/**
 * @file No_Internet_Dinosaur.ino
 *
 * @brief Robot that plays the google chrome dinosaur game which appears when there is no internet connection.
 *
 * @author Sohrab Vafa
 * Contact: github.com/SohrabVafa
 *
 */
// Include the Servo library
#include <Servo.h>

//Constants
const int pResistorD = A0;  // Down photoresistor at Arduino analog pin A0.
                            // It should be placed at the ground level and with 2cm aprox. from the dinosaur.
const int pResistorT = A1;  // Top photoresistor at Arduino analog pin A1.
                            // It should be placed at the middle level and exactly over the Down photoresistor.
const int servoPin = 3;     // Servo at Arduino PWM pin 3.
const int threshold = 800;  // In my PC the white pixels are detected with 840, and the cactus with 600-750.
const int upButton = 120;   // servo at 120 degrees presses the up button.
const int downButton = 55;  // servo at 55 degrees presses the down button.
const int noButton = 90;    // servo at 90 degrees  presses no button.

//Variables
int down;         // Stores values from Down photoresistor (0-1023).
int top;          // Stores values from Top photoresistor (0-1023).
Servo MyServo;    // Create a servo object.
                  // The servo should be placed over the up and down buttons.

void setup() {
  pinMode(pResistorD, INPUT);// Set pResistorD - A0 pin as an input.
  pinMode(pResistorT, INPUT);// Set pResistorT - A1 pin as an input.
  MyServo.attach(servoPin); // Attach the servo to the used pin number.
}

void loop() {
  // Read the values.
  down = analogRead(pResistorD);
  top = analogRead(pResistorT);

  if (down < threshold) {
    
    MyServo.write(upButton);
    delay(150);
    // Put Servo in standby
    MyServo.write(noButton);
    delay(100);

    // Read the pResistorD again in order to see if is safe to come down.
    down = analogRead(pResistorD);
    
    if (down > threshold) {
      delay(140);
      MyServo.write(downButton);
      delay(150);
      // Put Servo in standby
      MyServo.write(noButton);
      delay(80);
    }

  } else if (top < threshold) {

    MyServo.write(downButton);
    delay(300);
    // Put Servo in standby
    MyServo.write(noButton);
    delay(100);
    
  }

}
