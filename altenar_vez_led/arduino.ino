# define let_1 1
# define let_2 2
# define let_3 3

void setup() {
  // put your setup code here, to run once:
  pinMode(let_1, OUTPUT);
  pinMode(let_2, OUTPUT);
  pinMode(let_3, OUTPUT);
  digitalWrite(let_1, LOW);
  digitalWrite(let_2, LOW);
  digitalWrite(let_3, LOW);
}

void alterar(bool b1, bool b2, bool b3, int tmp) {
  digitalWrite(let_1, b1);
  digitalWrite(let_2, b2);
  digitalWrite(let_3, b3);
  delay(tmp);
}

void loop() {
  alterar(true, false, false, 2000);
  alterar(false, true, false, 2000);
  alterar(false, false, true, 2000);
}