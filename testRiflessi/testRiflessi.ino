#include<LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);
int G = 7;
int B = 13;
int R = 6;
int BUZZ = 10;
int BUTTON = 8;
int tempoL = 0;
int tempoB = 0;
void setup() {
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(BUTTON, INPUT);
  // put your setup code here, to run once:
LCD.begin(16,2);
randomSeed(analogRead(0));
}
void start(){
  LCD.print("Premi il bottone");
  LCD.setCursor(0,1);
  LCD.print("per iniziare");
while(digitalRead(BUTTON) == LOW){}
  LCD.setCursor(1,0);
  LCD.clear();
  LCD.setCursor(0,1);
  LCD.clear();
  LCD.setCursor(1,0);
}
void media(){
  int media = (tempoL+tempoB)/2;
  LCD.print("Tempo medio:");
  delay(1000);
  LCD.clear();
  LCD.print(media);
  delay(1000);
  LCD.clear();
  if(media < 350){
    LCD.print("Test superato");
    digitalWrite(G, HIGH);
    delay(1000);
    LCD.clear();
    digitalWrite(G, LOW);
  }
  else{
    LCD.print("Test fallito");
    digitalWrite(R, HIGH);
    delay(1000);
    LCD.clear();
    digitalWrite(R, LOW);
  }
}
void conta(){
  LCD.print("3");
  delay(1000);
  LCD.clear();
  LCD.print("2");
  delay(1000);
  LCD.clear();
  LCD.print("1");
  delay(1000);
  LCD.clear();
}
void accendi(){
  int a = millis();
  digitalWrite(B,HIGH);
  while(digitalRead(BUTTON)== LOW){}
  int b = millis();
  digitalWrite(B, LOW);
  tempoL = b - a;
}
void suona(){
  tone(BUZZ, 1000);
  int t = millis();
  while(digitalRead(BUTTON) == LOW){}
  int o = millis();
  tempoB = o-t;
  noTone(BUZZ);
}
void loop() {
  // put your main code here, to run repeatedly:
start();
LCD.clear();
conta();
LCD.print("Test in corso");
delay(1000);
LCD.clear();
delay(random(1000,5000));
accendi();
LCD.print("Il tuo tempo:");
delay(1000);
LCD.clear();
LCD.print(tempoL);
delay(2500);
LCD.clear();
LCD.print("Test in corso");
delay(1000);
LCD.clear();
delay(random(1000,5000));
suona();
LCD.print("Il tuo tempo:");
delay(1000);
LCD.clear();
LCD.print(tempoB);
delay(2500);
LCD.clear();
media();
setup();
}
