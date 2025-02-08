/*
 * Código teste para ESP32 
 * Pisca ON Board LED GPIO 2
 * ESP32 Dev Module
 * baud rate --> 921600
 * Chip is ESP32-D0WD-V3 (revision v3.1)
 */

#define LED 2

void setup() {
  // Set pin mode
  pinMode(LED,OUTPUT);
  Serial.begin(921600);
}

void loop() {
  Serial.println("teste");
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
}