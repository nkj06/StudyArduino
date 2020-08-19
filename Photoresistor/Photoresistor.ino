// 조도센서
// 아날로그 입력의 범위는 0~1023
int sensor = A0;
int vcc = A1;
int gnd = A2;

int val = 0;

void setup(){
  Serial.begin(9600);

  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(sensor, INPUT);

  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);
}

void loop(){
  val = analogRead(sensor);
  Serial.println(val);

}
