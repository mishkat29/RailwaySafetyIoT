int sensor1 = 3;
int sensor2 = 4;
int motor = 9; 
 
#include<Servo.h>
Servo myservo;
long e = 0;
long c = 0; // variable to store the value read

void setup()
{
 Serial.begin(9600); // setup serial
 pinMode ( sensor1 , INPUT );
 pinMode ( sensor2 , INPUT );
 pinMode ( motor , OUTPUT );
 pinMode(5, OUTPUT);
 myservo.attach(motor);
}
void loop()
{
 e = digitalRead(sensor1); // read the input pin
 c = digitalRead(sensor2);
 

 Serial.println(e);
 Serial.println(c);

 int pos = 0;

 if (e>1000 && c<1000)
 {
  for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 90 degrees
  { // in steps of 1 degree
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(10);
    digitalWrite(3, HIGH);   // turn the LED/Buzz ON
    delay(100);              // wait for 100 msecond
    digitalWrite(3, LOW);   // turn the LED/Buzz OFF
    delay(100);    
    break; // breaks the loop
  }
       
 }

 Serial.println(e);
 Serial.println(c);
 delay(1000);
}
