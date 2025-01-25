/*
 * Projeto integrado com Python
 */

int porta = 3;
int sinal = 13; // sinal luminoso junto com o clique/salvamento no BD.

void setup() {
  Serial.begin(9600);
  pinMode(porta, INPUT_PULLUP);      
  pinMode(sinal, OUTPUT);
  digitalWrite(sinal, LOW);           
}

void loop() {
  int estado = digitalRead(porta);       

  if (estado == LOW) {                    
    Serial.println("clicado");  
    digitalWrite(sinal, HIGH);            
    delay(500);                            
    digitalWrite(sinal, LOW); 
  }
}