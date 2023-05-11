#include <LiquidCrystal.h>
// Linha 1: inclui a biblioteca do lcd para facilitar
// Linha 2: define os pins que está o lcd
LiquidCrystal lcd(12, 11, 10, 6, 5, 3, 2);

// Define pins dos leds
int LedVERDE=7;
int LedAMARELO=8;
int LedVERMELHO=9;

// Define pin do sensor de luminosidade e seu valor inicial
float SensorLDR=A0;
int valorSensorLDR=0;

// Define pin do buzzer
int buzzer=4;

// Define pins dos sensores de umidade e temperatura 
int sensorUmidade = A1;
int sensorTemperatura = A2;

void setup()
{
  
  Serial.begin(9600);

  pinMode(LedVERDE,OUTPUT);
  pinMode(LedVERMELHO,OUTPUT);
  pinMode(LedAMARELO,OUTPUT);
  pinMode(SensorLDR,INPUT);
  pinMode(buzzer,OUTPUT);
  
  lcd.begin(16,2); 
}

void loop(){
  // Variaveis que vai ler o valor passado do sensor de fotoluz, temperatura e umidade
  int valorSensorLDR=analogRead(SensorLDR);
  int leitorTemperatura = analogRead(sensorTemperatura); 
  float umidade = analogRead(sensorUmidade);

   // Transforma a temperatura lida em graus celcius
   float temperatura = (leitorTemperatura * (5000 / 1024) - 500) / 10;

   // Mostra os valores no Serial
  	Serial.println(valorSensorLDR);
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("ºC");
  
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.println("%");
  	delay(1000);
  
  // Condições para a luz do ambiente
  if(valorSensorLDR<100)
  {
    digitalWrite(LedVERDE,HIGH);
  }
  
  if(valorSensorLDR>=100&&valorSensorLDR<=250){
    digitalWrite(LedAMARELO,HIGH);
    
    limpaLCD();
  	lcd.setCursor(0,0);
  	lcd.print("Ambiente meia");
    lcd.setCursor(0,1);
    lcd.print("luz!");
  }
  
 if(valorSensorLDR>250){
    digitalWrite(LedVERMELHO,HIGH);
    tone(buzzer,1000);
   
    limpaLCD();
  	lcd.setCursor(0,0);
  	lcd.print("Ambiente muito");
    lcd.setCursor(0,1);
    lcd.print("claro!");
 } 
 else {
   noTone(buzzer);
   digitalWrite(LedVERMELHO,LOW);
 }
  
  // Condições de temperatura
  if(temperatura >= 10 && temperatura <= 15){
    digitalWrite(LedVERDE,HIGH);
    
    limpaLCD();
    lcd.setCursor(0,0);
    lcd.print("Temperatura ok");
    lcd.setCursor(0,1);
    lcd.print("Temp.: ");
    lcd.print(temperatura);
    lcd.print("C");
  }
  
  if(temperatura < 10){
    digitalWrite(LedAMARELO, HIGH);
    tone(buzzer,1000);
    
    limpaLCD();
    lcd.setCursor(0,0);
    lcd.print("Temperatura baixa!");
    lcd.setCursor(0,1);
    lcd.print("Temp.: ");
    lcd.print(temperatura);
    lcd.print("C");
  } 
  else if(temperatura >= 10 && temperatura <= 15){
   noTone(buzzer);
 }
  
  if(temperatura > 15){
    digitalWrite(LedAMARELO, HIGH);
    tone(buzzer,1000);
    
    limpaLCD();
    lcd.setCursor(0,0);
    lcd.print("Temperatura alta!");
    lcd.setCursor(0,1);
    lcd.print("Temp.: ");
    lcd.print(temperatura);
    lcd.print("C");
  } else if(temperatura >= 10 && temperatura <= 15){
   noTone(buzzer);
   digitalWrite(LedAMARELO, LOW);
 }
  
  // Condições de umidade
  if(umidade >= 50 && umidade <= 70){
    digitalWrite(LedVERDE,HIGH);
    
    limpaLCD();
    lcd.setCursor(0,0);
    lcd.print("Umidade ok");
    lcd.setCursor(0,1);
    lcd.print("Umid.: ");
    lcd.print(umidade);
    lcd.print("%");
  }
  
  if(umidade < 50){
    digitalWrite(LedVERMELHO, HIGH);
    tone(buzzer,1000);
    
    limpaLCD();
    lcd.setCursor(0,0);
    lcd.print("Umidade baixa!");
    lcd.setCursor(0,1);
    lcd.print("Umid.: ");
    lcd.print(umidade);
    lcd.print("%");
  }
  else if(umidade >= 50 && umidade <= 70){
    noTone(buzzer);
    digitalWrite(LedVERMELHO, LOW);
  }
  
    if(umidade > 70){
    digitalWrite(LedVERMELHO, HIGH);
    tone(buzzer,1000);
    
    limpaLCD();
    lcd.setCursor(0,0);
    lcd.print("Umidade alta!");
    lcd.setCursor(0,1);
    lcd.print("Umid.: ");
    lcd.print(umidade);
    lcd.print("%");
  }
  else if(umidade >= 50 && umidade <= 70){
    noTone(buzzer);
    digitalWrite(LedVERMELHO, LOW);
  }
  
}

// Função que limpa o LCD 
void limpaLCD(){
  delay(5000);
  lcd.clear();
}
    
    