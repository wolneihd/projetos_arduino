#define LED_1_PIN 9
#define LED_2_PIN 10
#define LED_3_PIN 11

class Led {

  private:
    byte pin;

  public:
    Led(byte pin) {
      // this é o mesmo que "this" do JAVA ou "self" do python.
      this->pin = pin;
      this->init();
    }

    void init() {
      pinMode(this->pin, OUTPUT); 
      off(); // desliga o PIN ao iniciar a classe.
      Serial.prinln("Atividade realizada no led");
    }

    void on() {
      digitalWrite(this->pin, HIGH);
    }

    void off() {
      digitalWrite(this->pin, LOW);
    }

    void timeout(int tmp) {
        delay(tmp);
    }

}

void setup() {
    Led led1(LED_1_PIN);
    Led led2(LED_2_PIN);
    Led led3(LED_3_PIN);
}

void loop() {

  led1.on();
  led1.delay(1000);
  led1.off();
  led1.delay(1000);

  led2.on();
  led2.delay(1000);
  led2.off();
  led2.delay(1000);

  led3.on();
  led3.delay(1000);
  led3.off();
  led3.delay(1000);

}