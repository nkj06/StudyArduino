// 릴레이 모듈
int relay = 8; // 신호
int vcc = 9; // +
int ground = 10; // -

void setup() {
  pinMode(relay,OUTPUT);
  pinMode(vcc, OUTPUT);
  pinMode(ground, OUTPUT);

  digitalWrite(vcc, LOW);
  digitalWrite(ground, LOW); // 초기화 
}

void loop() {
  digitalWrite(relay,HIGH);
  delay(1000);

  digitalWrite(relay,LOW);
  delay(1000);

}
