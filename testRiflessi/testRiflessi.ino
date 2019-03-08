#include<LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);
int LED = 7;
int BUZZ = 8;
int BUTTON = 13;
int v = 0;
int k = 0;
int p = 0;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(BUTTON, OUTPUT);
  // put your setup code here, to run once:
LCD.begin(16,2);
randomSeed(analogRead(0));
}
void start(void){
  v = digitalRead(BUTTON);
while(v == LOW)
{
  LCD.print("Premere il pulsante per iniziare");
  delay(500);
  LCD.clear();
  delay(500);
}
if(v == HIGH)
{
  LCD.clear();
  LCD.print("Test iniziato");
}
LCD.clear();
delay(1000);
LCD.print("3");
LCD.clear();
delay(1000);
LCD.print("2");
LCD.clear();
delay(1000);
LCD.print("1");
LCD.clear();
  }
void accendi(void){
  digitalWrite(LED,HIGH);
  k = digitalRead(BUTTON);
  while(k == LOW){
    digitalWrite(LED,HIGH);
  }
  if(k == HIGH){
    digitalWrite(LED,LOW);
  }
}
void suona(void){
 
}
void loop() {
  // put your main code here, to run repeatedly:
start();
delay(random(1000,5000));
accendi();
delay(random(1000,5000));
}
