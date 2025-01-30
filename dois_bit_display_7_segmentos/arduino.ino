# define let_1 1
# define let_2 2
# define tempo 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(let_1, OUTPUT);
  pinMode(let_2, OUTPUT);
  digitalWrite(let_1, LOW);
  digitalWrite(let_2, LOW);
}

void alterar(bool b1, bool b2, int tmp) {
  digitalWrite(let_1, b1);
  digitalWrite(let_2, b2);
}

void loop() {
  alterar(false, false, tempo); // 0 - 0
  alterar(false, true, tempo); // 0 - 1
  alterar(true, false, tempo); // 1 - 0
  alterar(true, true, tempo); // 1 - 1
}