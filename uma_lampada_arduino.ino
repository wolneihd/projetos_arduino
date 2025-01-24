/*
 * Referência: https://blog.eletrogate.com/como-conectar-o-arduino-com-o-python/
 * Código foi adaptado para a minha necessidade.
 */

char cmd;                     //Define a variável dos comandos seriais
int porta = 13;

void setup() {
  Serial.begin(9600);         //Inicia o Monitor Serial
  pinMode(porta, OUTPUT);         //Define o pino como saída
  digitalWrite(porta, LOW);
}

void loop() {
  cmd = Serial.read();        //Realiza a leitura do serial
  if (cmd == 'l') {           //Se o comando for "l", liga o led
    digitalWrite(porta, HIGH); 
  }

  else if (cmd == 'd') {      //Se o comando for "d", desliga o led
    digitalWrite(porta, LOW);
  }
}