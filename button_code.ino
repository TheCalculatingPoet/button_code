// constants won't change. They're used here to
// set pin numbers:
const int buttonPin_A = 2;     // the first button
const int buttonPin_B = 3;  // the secondary button
const int buttonPin_C = 4; //the third button
const int ledPin =  13;  // the number of the LED pin
const int ledA = 7;  //the green
const int ledB = 8; //the yellow 
const int ledC = 9; //the red LED
const int buzzer = 6; //the buzzer
const int activate = 5;

int key = 2;
// variables will change:
int pushA = 0;         // variable for reading the pushbutton status
int pushB = 0;
int pushC = 0;
int KeyState = 0;
int presses = 0;
int start = 0;

void setup() {
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  key = random(2,5);
  presses = 0;
  // initialize the inputs and outputs:
  pinMode(ledPin, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(buttonPin_A, INPUT);
  pinMode(buttonPin_B, INPUT);
  pinMode(buttonPin_C, INPUT);
  pinMode(key, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(activate, INPUT);
  
}

void loop() {
  KeyState = digitalRead(key);
  start = digitalRead (activate);
  //if the correct button has been pressed 3 times, then the leds will flash
 if (start == HIGH) {
  presses = 0;
  delay(2000);
 }
 
  if (presses == 3) {
    digitalWrite (ledA, LOW);
    digitalWrite (ledB,LOW);
    digitalWrite (ledC, LOW);
  }
  else if (KeyState == HIGH) {
    //if the key button is pushed all the lights will be turned off, a new key will be selected, 
    //and the # of presses will increase by 
noTone(buzzer);
     digitalWrite (ledA, HIGH);
    delay(100);
      digitalWrite (ledB, HIGH);
      digitalWrite (ledA, LOW);
    delay(100);
      digitalWrite (ledC,HIGH);
      digitalWrite (ledB,LOW);
    delay(100);
      digitalWrite (ledC, LOW);
      digitalWrite (ledB,HIGH);
    delay(100);
      digitalWrite (ledB, LOW);
      digitalWrite (ledA, HIGH);
    delay(100);
     digitalWrite (ledA, LOW);
    randomSeed(analogRead(0));
    key = random(2,5);
    presses = presses + 1; 
   
    delay(200);
    }
  //if the key is the first button the green led will turn on
  else if (key == 2) {
  digitalWrite (ledA, HIGH);
  tone(buzzer, 33, 500);
  noTone(buzzer);
  } 
  //if the key button is the second button the yellow led will turn on
  else if (key == 3) {
  digitalWrite (ledB, HIGH);
  tone(buzzer, 33, 500);
  noTone(buzzer);
  }
  //if the key is the third button the red led will turn on
  else if (key == 4) {
  digitalWrite (ledC, HIGH);
  tone(buzzer, 33, 500);
  noTone(buzzer);
  }
 
}
