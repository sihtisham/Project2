# include<Servo.h>
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

//defining pins section

int pos;
// digital pin connected to switch output
const int X_pin = A1; // analog pin connected to X output
const int Y_pin = A0; // analog pin connected to Y output


int val;  
int count;
void setup()
{
  Serial.begin(9600);
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
 
void loop()
{
 
 count=analogRead(Y_pin);
 pos=analogRead(X_pin);
 if (((count>400) and (count < 500)) and (pos >400 and pos <400)) {
 digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 }

else if(count>=500)
 {
 while (count >= 550)
{ 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
int speed_= map(count, 550, 1023, 0,250 );     // scale it to use it with the servo (value between 0 and 180)
 //Serial.print(speed_);
 //Serial.print("\t");
                // sets the servo position according to the scaled value
 analogWrite(enA, speed_);
  analogWrite(enB, speed_);
  count=analogRead(Y_pin);
 }}
 else if (count <=400)
 {while (count <= 400)
{ 
int speed_= map(count, 400, 0, 0, 250);

digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);// scale it to use it with the servo (value between 0 and 180)
 //Serial.print(speed_);
 //Serial.print("\t");
 analogWrite(enA, speed_);
  analogWrite(enB, speed_);
  count=analogRead(Y_pin);
 }
 }


  else if(pos>=550)
 {
 while (pos >= 550)
{ 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
int speed_= map(pos, 550, 1023, 0,250 );     // scale it to use it with the servo (value between 0 and 180)
 Serial.print(speed_);
 Serial.print("\t");
                // sets the servo position according to the scaled value
 analogWrite(enA, speed_);
 analogWrite(enB, speed_);
 pos=analogRead(X_pin);
 }
 }
 
  else if (pos <=400)
 {
 while (pos <= 400)
{ 
 //else { 
//count =analogRead(Y_pin);
int speed_= map(pos, 400, 0, 0, 250);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);// scale it to use it with the servo (value between 0 and 180)
 Serial.print(speed_);
 Serial.print("\t");
 analogWrite(enA, speed_);
  analogWrite(enB, speed_);
  pos=analogRead(X_pin);
 }
 }


//val = analogRead(X_pin);  
// reads the value of the potentiometer (value between 0 and 1023)
  //val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  //Myservo.write(val);                  // sets the servo position according to the scaled value
  //delay(15);    
}
