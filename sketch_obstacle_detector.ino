int trigPin = 8;
int echoPin = 9;
int led = 13;
int buzzer= 4;
long duration1, distance1;


void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
 
 if((distance<=100)) 
  {
    digitalWrite(led, HIGH);
    tone(buzzer, 450);
    delay(1000);
    noTone(buzzer);
    delay(500);

}
}
