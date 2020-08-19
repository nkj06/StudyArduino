// 아날로그 입력의 범위는 0~1023
// 조도센서
int sensor = A0;
int vcc = A1;
int gnd = A2;

// LED
int Grd = 10;
int B = 13;

int val = 0;

void setup(){
  Serial.begin(9600);

  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(sensor, INPUT);

  pinMode(Grd, OUTPUT);
  pinMode(B, OUTPUT);

  digitalWrite(Grd, LOW);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);
}

void loop(){
  val = analogRead(sensor);
  Serial.println(val);
  if (val > 300){
    Serial.print("sen : ");
    Serial.println(val);

    digitalWrite(B, HIGH);
  }
  else
  {
    digitalWrite(B, LOW);
  }

}
