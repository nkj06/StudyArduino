int sensor = 3; // 포토인터럽터 핀 번호
int val = 0;

int Gnd = 8; // LED
int R = 9;
int G = 10;
int B = 11;

void setup() {
  Serial.begin(9600); // 시리얼 통신
  pinMode(sensor, INPUT); // 포토인터럽터 입력으로 설정
  
  pinMode(Gnd, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  val = digitalRead(sensor); // 데이터 값 읽기
  if(val == 0){ // 아무것도 없을 때
    Serial.println(val);
    digitalWrite(B, HIGH); // B
    delay(10);
  }
  else{ // 장애물 감지
    Serial.println(val);
    digitalWrite(R, HIGH); // R
    delay(10);
  }
  digitalWrite(R, LOW);
  digitalWrite(B, LOW);
  delay(10);
}
