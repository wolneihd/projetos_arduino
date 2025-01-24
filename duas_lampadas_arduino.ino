/*
 * Referência: https://blog.eletrogate.com/como-conectar-o-arduino-com-o-python/
 * Código foi adaptado para a minha necessidade.
 */

char cmd;                     //Define a variável dos comandos seriais
int led1 = 8;
int led2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);      
  pinMode(led2, OUTPUT);      
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  cmd = Serial.read();        //Realiza a leitura do serial

  if (cmd == 'a') {           
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, LOW);
  }

  else if (cmd == 'b') {      
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  else if (cmd == 'c') {      
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW); 
  }  
}