/*
 * Código teste para ESP32 
 * ESP32 Dev Module
 * baud rate --> 921600
 * Chip is ESP32-D0WD-V3 (revision v3.1)
 * receber 03 inputs
 */

#define btn_01 15
#define btn_02 2
#define btn_03 4

void setup() {
  // Set pin mode
  pinMode(btn_01, INPUT_PULLUP);
  pinMode(btn_02, INPUT_PULLUP);
  pinMode(btn_03, INPUT_PULLUP);

  // Start Serial conn
  Serial.begin(921600);
}

void loop() {
  bool positivo = digitalRead(btn_01);       
  bool neutro = digitalRead(btn_02);       
  bool negativo = digitalRead(btn_03);       

  if (positivo == true) {                    
    Serial.println("positivo clicado");
    delay(500);                            
  }
  if (neutro == true) {                    
    Serial.println("neutro clicado");  
    delay(500);                            
  }
  if (negativo == true) {                    
    Serial.println("negativo clicado"); 
    delay(500);                             
  }
}