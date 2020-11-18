#include <Servo.h>
#include <Stepper.h>

const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

int val=0, val2=0, j, k, x;

const int stepsPerRevolution = 256;

Servo myservo;
Stepper myStepper(stepsPerRevolution, 11, 9, 8, 10);


void setup() {
    myservo.attach(7);
    myservo.write(90);
    myStepper.setSpeed(60);

    pinMode(pingPin, OUTPUT);   
    pinMode(echoPin, INPUT);
    
    j=80;
    k=50;
    x=0;
    
    Serial.begin(9600);
  }

void loop() {
    long duration, cm;
    
    val = analogRead(Y_pin);
    val2 = analogRead(X_pin);
    Serial.println(val);
    Serial.println(val2);
    Serial.println();

    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
   
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);
      
    duration = pulseIn(echoPin, HIGH);
   
    cm = duration*(0.034/2);
   
   //Stepper Motor Instructions 
    if(cm>1.6){
        myStepper.step(j);
        delay(50);
        //If nothing is close, keep moving 
      }
    
    if(cm<1.5){
        myStepper.step(0);
        x++;
        delay(50);
        //If object is detected, stop moving and prepare to turn axle
      }
          
    //Servo Motor Instructions
    if(x=1){
        myservo.write(180);
        delay(100);
        myStepper.step(k);
        delay(80);
        //When first object is detected, move to the right
      }
    
    if(x=2){
        myservo.write(0);
        delay(100);
        myStepper.step(k);
        delay(80);
        //When second object is detected, move to the left
      }

    if(x=3){
        while(1){
            myStepper.step(0);
        }
        //When last object is detected, assume reached finish line and stop
      }
    

  }
