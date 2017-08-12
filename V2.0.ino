//Libraries
//#include <TimerThree.h>

//Perfect Posture
//Bonfire17'

//distance constants
const int u1low = 4;
const int u1high = 7;
const int u2low = 4;
const int u2high = 7;
const int u3low = 6;
const int u3high = 10;


//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//if (buttonState == HIGH) {
//    // turn LED on:
//    digitalWrite(ledPin, HIGH);
//  } else {
//    // turn LED off:
//    digitalWrite(ledPin, LOW);
//  }

//Sonar 1 
  const int trigPin1 = 3;
  const int echoPin1 = 2;


//Sonar 2
  const int trigPin2 = 7;
  const int echoPin2 = 6;


//Sonar 3
  const int trigPin3 = 9;
  const int echoPin3 = 8;


long duration1, duration2, duration3 = 0;
int distance1, distance2, distance3 = 0;

//Button
const int button1 = 4;
int button1State = 0;


void setup() {
//Ultrasonic 1
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

//Ultrasonic 2
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input

//Ultrasonic 3
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input

  
//Buzzer
  pinMode(13, OUTPUT); //BUZZER
  digitalWrite(13, LOW); //Default OFF
//LED
  pinMode(12, OUTPUT); //LED 1 OUT
  pinMode(11, OUTPUT); //LED 2 OUT
  pinMode(10, OUTPUT); //LED 3 OUT
  
//Serial
  Serial.begin(9600);
  Serial.println("Start");
}

void buzzer() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

void loop() {
 posture();
}


void posture() {
    ultraDistance1();
    ultraDistance2();
    ultraDistance3();
    digitalWrite(12, LOW); //LED 1
    digitalWrite(11, LOW); //LED 2
    digitalWrite(10, LOW); //LED 3
    
    if (distance1 > u1high){
      buzzer();
      digitalWrite(12, HIGH); //LED 1
      digitalWrite(11, HIGH); //LED 2
      digitalWrite(10, HIGH); //LED 3
    }
    else if (u1low <= distance1 <= u1high){
        if (distance2 > u2high) {
           buzzer();
           digitalWrite(12, HIGH); //LED 1
           digitalWrite(11, HIGH); //LED 2
        }
        else if (u2low <= distance2 <= u2high) {
            if (distance3 > u3high) {
              buzzer();
              digitalWrite(10, HIGH); //LED 3
            }
        }
    }
  }

void ultraDistance1() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds

  duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance

  distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor

  Serial.print("Distance1: ");
  Serial.println(distance1);
  delay(100);
  }

void ultraDistance2() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds

  duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance

  distance2= duration1*0.034/2;
// Prints the distance on the Serial Monitor

  Serial.print("Distance2: ");
  Serial.println(distance2);
  }

void ultraDistance3() {
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds

  duration3 = pulseIn(echoPin3, HIGH);
// Calculating the distance

  distance3= duration3*0.034/2;
// Prints the distance on the Serial Monitor

  Serial.print("Distance3: ");
  Serial.println(distance3);
  }
