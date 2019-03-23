#include<LiquidCrystal.h>//richiamo libreria LCD
LiquidCrystal LCD(12,11,5,4,3,2);//pin schermo LCD
int G = 7;//pin colore verde
int B = 13;//pin colore blu
int R = 6;//pin colore roso
int BUZZ = 10;//pin buzzer
int BUTTON = 8;//pin pulsante
int tempoL = 0;//variabile tempo risposta del led
int tempoB = 0;//variabile tempo risposta del buzzer
void setup() {
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(BUTTON, INPUT);
  // put your setup code here, to run once:
LCD.begin(16,2);//inizializzo lo schermo LCD
randomSeed(analogRead(0));
}
void start(){//metodo che attende l'imput dall'utente perchè inizi il programma
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
void media(){//metodo che calcola il tempo medio di risposta e determina se il test è stato superato dall'utente
  int media = (tempoL+tempoB)/2;
  LCD.print("Tempo medio:");
  delay(1000);
  LCD.clear();
  LCD.print(media);
  delay(1000);
  LCD.clear();
  if(media == 0 || media < 130){
    LCD.print("Non barare!");
    digitalWrite(R, HIGH);
    delay(1000);
    LCD.clear();
    digitalWrite(R, LOW);
  }
  if(media < 350 && media != 0 && tempoL != 0 && tempoB != 0){
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
void conta(){//conto alla rovescia prima dell'inizio del programma
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
void accendi(){//funzione che accende il led e calcola il tempo di risposta dell'utente
  int a = millis();
  digitalWrite(B,HIGH);
  while(digitalRead(BUTTON)== LOW){}
  int b = millis();
  digitalWrite(B, LOW);
  tempoL = b - a;
  if(tempoL == 0){
    LCD.print("Non barare");
    digitalWrite(R, HIGH);
    delay(1000);
    digitalWrite(R, LOW);
    LCD.clear();
  }
}
void suona(){//funzione che attiva il buzzer e calcola il tempo di risposta dell'utente
  tone(BUZZ, 1000);
  int t = millis();
  while(digitalRead(BUTTON) == LOW){}
  int o = millis();
  noTone(BUZZ);
  tempoB = o-t;
  if(tempoB == 0){
    LCD.print("Non barare");
    digitalWrite(R, HIGH);
    delay(1000);
    digitalWrite(R, LOW);
    LCD.clear();
  }
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
