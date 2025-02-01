# define led_1 2
# define led_2 3
# define led_3 4
# define led_4 5

# define tempo 1000

void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
}

void alterar(bool b1, bool b2, bool b3, bool b4, int tmp) {
  digitalWrite(led_1, b1);
  digitalWrite(led_2, b2);
  digitalWrite(led_3, b3);
  digitalWrite(led_4, b4);
  delay(tempo);
}

void loop() {
  alterar(false, false, false, false, tempo); // 0 --> 0000
  alterar(true, false, false, false, tempo); // 1 --> 0001
  alterar(false, true, false, false, tempo); // 2 --> 0010
  alterar(true, true, false, false, tempo); // 3 --> 0011
  alterar(false, false, true, false, tempo); // 4 --> 0100
  alterar(true, false, true, false, tempo); // 5 --> 0101
  alterar(false, true, true, false, tempo); // 6 --> 0110
  alterar(true, true, true, false, tempo); // 7 --> 0111
  alterar(false, false, false, true, tempo); // 8 --> 1000
  alterar(true, false, false, true, tempo); // 9 --> 1001
}