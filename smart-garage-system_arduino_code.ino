// smart lighting system
int IRSensor=9;
int LED1=13;
int LED2=12;
void setup()
{
  Serial.begin(9600);
  pinMode(IRSensor,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
}
void loop()
{
  int sensorStatus=digitalRead(IRSensor);
  if (sensorStatus==1)
{
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  Serial.println("Motion Detected!");
}
else
{
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  Serial.println("Motion Ended!");
}
}
// smart parking system
const int trigPin1=9;
const int echoPin1=10;
const int LEDpin1=13;
const int trigPin2=2;
const int echoPin2=3;
const int LEDpin2=12;
long duration1;
long duration2;
int distance1;
int distance2;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(LEDpin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(LEDpin2,OUTPUT);
}
void loop()
{
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin1,LOW);
  duration1=pulseIn(echoPin1,HIGH);
  distance1=duration1*0.034/2;
  if (distance1<=5)
  digitalWrite(LEDpin1,HIGH);
  else
  digitalWrite(LEDpin1,LOW);
  Serial.print("Distance1:");
  Serial.print(distance1);
  Serial.print("cm");
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin2,LOW);
  duration2=pulseIn(echoPin2,HIGH);
  distance2=duration2*0.034/2;
  if (distance2<=5)
  digitalWrite(LEDpin2,HIGH);
  else
  digitalWrite(LEDpin2,LOW);
  Serial.print("Distance2:");
  Serial.print(distance2);
  Serial.print("cm");
  delayMicroseconds(10);
}