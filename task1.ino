#include <Servo.h>
#include <Stepper.h>

const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

int val=0, val2=0, j;

const int stepsPerRevolution = 256;

Servo myservo;
Stepper myStepper(stepsPerRevolution, 11, 9, 8, 10);


void setup() {
    myservo.attach(7);
    myservo.write(90);
    myStepper.setSpeed(60);
  
    j=80;

    Serial.begin(9600);
  }

void loop() {
    val = analogRead(Y_pin);
    val2 = analogRead(X_pin);
    Serial.println(val);
    Serial.println(val2);
    Serial.println();
    
   
   //Stepper Motor Instructions 
    if(val<500){
        myStepper.step(j);
        delay(50);
        //When Joystick pushed up, move forward in j increments
      }
    
    if(val>520){
        myStepper.step(-j);
        delay(50);
        //When Joystick pushed down, move backwards in j increments
      }
    
    if(val>501 && val<519){
         delay(50);
         //Dead Band -- When Joystick resting, do not move 
      }
        
    //Servo Motor Instructions
    if(val2>520){
        myservo.write(180);
        delay(100);
        //When Joystick pushed to the right, move axle to the right
      }
    
    if(val2<500){
        myservo.write(0);
        delay(100);
        //When Joystick pushed to the left, move axle to the left
      }
    
    if(val2>501 && val2<519){
       myservo.write(90);
       delay(100);
       //Dead Band -- When Joystick resiting, return to neutral position
      }
    

  }
