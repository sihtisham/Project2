#include <Servo.h>
#include <Stepper.h>

const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

int val=0, val2=0, s, f, j, k;
int servo=0, stepper=0;

const int stepsPerRevolution = 256;

Servo myservo;
Stepper myStepper(stepsPerRevolution, 11, 9, 8, 10);


void setup() {
  myservo.attach(7);
  myservo.write(90);
  servo=90;
  myStepper.setSpeed(60);

  s=1;
  f=1;
  j=1;
  k=1;
  
  Serial.begin(9600);
}

void loop() {
val = analogRead(Y_pin);
val2 = analogRead(X_pin);
Serial.println(val2);


if(val<500){
  j=j+1;
  myStepper.step(j);
  delay(50);
}
if(val<200){
  j=j+50;
  myStepper.step(j);
  delay(50);
}

if(val>520){
  k=k+1;
  myStepper.step(-k);
  delay(50);
  }
if(val>900){
  k=k+50;
  myStepper.step(-k);
  delay(50);
  }

if(val>501 && val<519){
   j=1;
   k=1;
   delay(50);
}

if(val2>520){
  s=s+1;
   myservo.write(90+s);
  delay(100);
}
if(val2>900){
  s=s+20;
 // Serial.println(90+s);
  delay(100);
}

if(val2<500){
  f=f+1;
   Serial.println(f);
   myservo.write(90-f);
  delay(100);
}
if(val2<200){
  f=f+20;
 // Serial.println(90+s);
  delay(100);
}


if(val2>501 && val2<519){
   myservo.write(90);
   s=1;
   f=1;
   delay(100);
}


}
