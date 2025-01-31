# define led_1 2
# define led_2 3
# define tempo 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
}

void alterar(bool b1, bool b2, int tmp) {
  digitalWrite(led_1, b1);
  digitalWrite(led_2, b2);
  delay(tempo);
}

void loop() {
  alterar(false, false, tempo); // 1 --> 0 - 0
  alterar(false, true, tempo); //  2 --> 0 - 1
  alterar(true, false, tempo); //  3 --> 1 - 0
  alterar(true, true, tempo); //   4 --> 1 - 1
  alterar(true, false, tempo); //  3 --> 1 - 0
  alterar(false, true, tempo); //  2 --> 0 - 1
}