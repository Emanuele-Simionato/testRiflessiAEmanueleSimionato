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
  pinMode(BUTTON, INPUT);
  // put your setup code here, to run once:
LCD.begin(16,2);
randomSeed(analogRead(0));
}
void start(void){
  LCD.print("Premi il bottone");
  LCD.setCursor(0,1);
  LCD.print("per iniziare");
  LCD.setCursor(1,0);
  LCD.clear();
  LCD.setCursor(0,1);
  LCD.clear();
  LCD.setCursor(1,0);
while(digitalRead(BUTTON) == LOW){}
  
if(digitalRead(BUTTON) == HIGH)
{
  LCD.clear();
  LCD.print("Test iniziato");
}

}
void conta(){
  LCD.print("3");
  LCD.clear();
  LCD.print("2");
  LCD.clear();
  LCD.print("1");
  LCD.clear();
}
void accendi(){
  digitalWrite(LED,HIGH);
  while(digitalRead(BUTTON)== LOW){}
  digitalWrite(LED, LOW);
}
void suona(){
  tone(BUZZ, 1000);
  while(digitalRead(BUTTON) == LOW){}
  noTone(BUZZ);
}
void loop() {
  // put your main code here, to run repeatedly:
start();
LCD.clear();
conta();
delay(random(1000,5000));
accendi();
delay(random(1000,5000));
suona();

}
