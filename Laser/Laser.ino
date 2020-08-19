int vccPin = 12; // vcc는 전력 5V
int gndPin = 11; // gnd 전류가 모이는 곳 0V
int outPin = 13; // 레이저 발사

void setup() {
  pinMode(vccPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(outPin, OUTPUT);
  digitalWrite(vccPin, HIGH);
  digitalWrite(gndPin, LOW);
  digitalWrite(outPin, LOW); // 초기화 
}

void loop() {
  digitalWrite(outPin, HIGH);
  delay(5000); // 5초
  digitalWrite(outPin, LOW);
  delay(1000); // 1초
}
