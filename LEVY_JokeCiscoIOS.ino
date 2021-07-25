// LEVY
// http://levysounddesign.blogspot.com/

// JOKE CISCO IOS
// Hardware Version 0.0
// Software Version 1.0
// Created 24JUL21
// Updated 25JUL21

// DESCRIPTION:
// Joke code
// Connect to arduino with Putty using USB serial com port Serial terminal displays a cisco router startup interface (Router>)
// No commands work, and router always returns an error.

// BOARDS / MODULES:
// Arduino Uno

// NOTE:

// SOFTWARE VERSION CHANGELOG:

// INCLUDE:

// CONSTANTS:

// VARIABLES:
char inputChar;
String inputString;

// OBJECTS:

// SETUP:
void setup() {

  Serial.begin(9600);                         //start serial communication  at <baudRate>

}

// PROGRAM MAIN LOOP:
void loop() {

  if (Serial.available() > 0) {                               //if serial connection established:

    inputChar = Serial.read();                                //read char from serial, save to serialRead variable

    if (inputChar != 13) {                                    //if inputChar is not ASCII 13 (Carriage Return):
      Serial.print(inputChar);                                //print inputChar to serial
      inputString += inputChar;                               //concatenate char to inputString

    } else if (inputString != "") {                           //else, if inputString is not empty:
      Serial.println();                                       //CR LF
      Serial.print("Translating ");                           //print 
      Serial.print('"');                                      //print
      Serial.print(inputString);                              //print inputString
      Serial.print('"');                                      //print
      Serial.println("...domain server (255.255.255.255)");   //print
      delay(3000);                                            //delay 3 seconds
      Serial.println("% Unknown command or computer name, or unable to find computer address");   //print
      Serial.print("Router>");                                //print
      inputString = "";                                       //clear inputString

    } else {
      Serial.println();                                       //CR LF
      Serial.print("Router>");                                //print
    }

  }
}

// REFERENCE:
//
