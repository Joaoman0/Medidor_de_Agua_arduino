// C++ code
//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

LiquidCrystal_I2C lcd(0x27, 16, 2); // linha onde é o ajuste do endereço no LCD

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.init(); // linha que inicializa o LCD
  lcd.backlight();
}

void loop() {
  // medição da distancia usando o sensor de distancia ultrassonico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");
  // atualiza a tela do LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nivel de Agua:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  
  delay(1000); // espera de 1 segundo antes da proxima leitura
}
