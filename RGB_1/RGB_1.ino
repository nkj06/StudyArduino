// LED 핀 사용하여 출력하기

int Ground = 8;
int Red = 9;
int Green = 10;
int Blue = 11;

void setup() {
  pinMode(Ground, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  digitalWrite(Ground, LOW);
}

void loop() {
  digitalWrite(Red, HIGH); // R
  delay(1000);
  digitalWrite(Red, LOW);
  
  digitalWrite(Green, HIGH); // G
  delay(1000);
  digitalWrite(Green, LOW);
  
  digitalWrite(Blue, HIGH); // B
  delay(1000);
  digitalWrite(Blue, LOW);
}
