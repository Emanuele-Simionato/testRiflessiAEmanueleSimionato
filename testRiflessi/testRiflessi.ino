#include<LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);
int LED = 7;
int BUZZ = 8;
int BUTTON = 13;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(BUTTON, OUTPUT);
  // put your setup code here, to run once:
LCD.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
LCD.print("Ciao");
delay(1000);
LCD.clear();
LCD.print("Mondo");
delay(1000);
LCD.clear();
tone(BUZZ, 1000, 200);
digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(LED, LOW);
delay(1000);
}
