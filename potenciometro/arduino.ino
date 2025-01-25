const int analogInPin = A1;
int vermelho = 2;
int amarelo = 3;
int verde = 4;
int sensorValue;
int outputValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, LOW);
}

void loop() {

  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  Serial.println(outputValue);

  if (outputValue <= 85) {
    Serial.println(outputValue);
    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
  } else if (outputValue <= 170) {
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(vermelho, LOW);
  } else {
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);    
  }
  delay(100); // Atraso maior para facilitar o monitoramento
}
