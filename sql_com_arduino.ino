/*
 * Projeto integrado com Python
 */

int porta = 3;

void setup() {
  Serial.begin(9600);                       //Inicia o Monitor Serial
  pinMode(porta, INPUT_PULLUP);                 //Define o pino como entrada
}

void loop() {
  int estado = digitalRead(porta);              //Defina uma variável que realizará a leitura do botão

  if (estado == LOW) {                      //Verifica se o botão for pressionado
    Serial.println("clicado");             //Imprime a mensagem no monitor serial
    delay(500);                            //Delay de 1 segundo
  }
}