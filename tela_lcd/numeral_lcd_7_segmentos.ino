// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2
#define tempo     2000

#define botao_01   2
#define botao_02   3
#define botao_03   4
#define botao_04   5

#define numero_01   8
#define numero_02   9
#define numero_03   10
#define numero_04   11

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.setBacklight(HIGH); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.print("Inicializando...");
  delay(1000);

  pinMode(botao_01, INPUT_PULLUP);  
  pinMode(botao_02, INPUT_PULLUP);  
  pinMode(botao_03, INPUT_PULLUP);  
  pinMode(botao_04, INPUT_PULLUP);  

  pinMode(numero_01, OUTPUT); //lsb  
  pinMode(numero_02, OUTPUT);  
  pinMode(numero_03, OUTPUT);  
  pinMode(numero_04, OUTPUT); //msb

  lcd.clear(); 
}

void checkValor(bool val1, bool val2, bool val3, bool val4) {

  digitalWrite(numero_01, LOW);
  digitalWrite(numero_02, LOW);
  digitalWrite(numero_03, LOW);
  digitalWrite(numero_04, LOW);

  int somador = 0;
  if (val1 == false) {
    somador = somador + 8;
    digitalWrite(numero_04, HIGH);
  } 
  if (val2 == false) {
    somador = somador + 4;
    digitalWrite(numero_03, HIGH);
  } 
  if (val3 == false) {
    somador = somador + 2;
    digitalWrite(numero_02, HIGH);
  } 
  if (val4 == false) {
    somador = somador + 1;
    digitalWrite(numero_01, HIGH);
  } 

  lcd.clear();
  lcd.print("TOTAL: ");
  lcd.setCursor(7, 0);
  lcd.print(somador);

  if (somador >= 10) {
    lcd.setCursor(0, 1);
    lcd.print("Valor incorreto!");
  }

  delay(tempo);

  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Informar valor:"); 

  bool bit_8 = digitalRead(botao_04);       
  bool bit_4 = digitalRead(botao_03);       
  bool bit_2 = digitalRead(botao_02); 
  bool bit_1 = digitalRead(botao_01); 

  checkValor(bit_8, bit_4, bit_2, bit_1);
}
