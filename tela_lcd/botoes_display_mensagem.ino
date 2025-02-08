// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2
#define tempo     2000

#define positivo  8
#define neutro    9
#define negativo  10

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.setBacklight(HIGH); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.print("Inicializando...");
  delay(1000);

  pinMode(positivo, INPUT_PULLUP);  
  pinMode(neutro, INPUT_PULLUP);  
  pinMode(negativo, INPUT_PULLUP);  
}

void textoDisplay(const char* texto) {
  lcd.clear();
  lcd.print(texto);
  lcd.setCursor(0, 1);
  lcd.print("Agradecidos!");
  delay(tempo);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("De seu feedback");

  bool good = digitalRead(positivo);       
  bool media = digitalRead(neutro);       
  bool bad = digitalRead(negativo);       

  if (good == LOW) {                    
    textoDisplay("Positivo");
  } 
  
  if (media == LOW) {
    textoDisplay("Neutro");
  } 
  
  if (bad == LOW) {
    textoDisplay("Negativa");
  }
}
