#include <Servo.h>
#include <Stepper.h>

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

int j, x, m, m2, p, p2;

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
    x=0;
    m=0;
    m2=0;
    p=0;
    p2=0;
    
    Serial.begin(9600);
  }

void loop() {
    long duration, cm;

    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
   
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);
      
    duration = pulseIn(echoPin, HIGH);
   
    cm = duration*(0.034/2);
   
   //Stepper Motor Instructions 
    if(cm>4.0){
        myStepper.step(j);
        delay(50);
        //If nothing is close, keep moving 
      }
    
    if(cm<4){
        myStepper.step(0);
        delay(25);        
        //If object is detected, move to the right and begin avoiding
        
        myservo.write(135);
        myStepper.step(m);
        delay(p);
        //Move 45 degrees to the right 
        
        myservo.write(45);
        myStepper.step(m2);
        delay(p2);
        //Begin adjusting axle to move parallel to the object
        
        myservo.write(0);
        myStepper.step(m);
        delay(p);
        //Begin merging with original center line
        
        myservo.write(90);
        myStepper.step(m);
        //complete merge with center line
        

        while(x=1){
            myStepper.step(0);
            delay(50);
          }

        x++;

     }
          
  }
