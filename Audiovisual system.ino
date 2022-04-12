int redLed = 10;
int blueLed = 9;
int buzzer = 8;
int smokeA0 = A4;
int yellowled=13;
int soundPin=7;
boolean val =0;
int sensorThres = 70;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(soundPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
val =digitalRead(soundPin);
  Serial.println (val);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    tone(buzzer, 1000, 100);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
  if (val==HIGH) {
    digitalWrite(yellowled, HIGH);
  }
  else {
    digitalWrite(yellowled, LOW);
  }

}