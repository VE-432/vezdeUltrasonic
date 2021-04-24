#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int trigPin = 8;
int echoPin = 9;
int button = 4;
int xd;
LiquidCrystal_I2C LCD(0x27,16,2);
void setup() { 
   LCD.init();
   LCD.backlight();
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button, INPUT);
  LCD.setCursor(1, 0);
} 
 
void loop() {
  xd = digitalRead(button);
  if(xd == HIGH){
  LCD.clear();
  int duration, cm;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = duration / 58;

  Serial.print(cm);
  Serial.println(" cm");
  LCD.print(cm);
  delay(1000);
  }
}
