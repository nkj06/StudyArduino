// 조이스틱
int jg = A0; // gnd
int jv = A1; // vcc
int jx = A2; // x좌표
int jy = A3; // y좌표
int jsw = A4; //switch

void setup() {
  pinMode(jg, OUTPUT);
  pinMode(jv, OUTPUT);
  pinMode(jx, INPUT);
  pinMode(jy, INPUT);
  pinMode(jsw, INPUT_PULLUP);

  Serial.begin(9600);
  digitalWrite(jv, HIGH);
  digitalWrite(jg, LOW);
}

void loop() {
  int vrx =map(analogRead(jx), 0, 1023, -1, 2);
  int vry = map(analogRead(jy), 0, 1023, -1, 2);
  int vsw = digitalRead(jsw);
  
  Serial.print("X축 : ");
  Serial.println(vrx);
  Serial.print("Y축 : ");
  Serial.println(vry);
  Serial.print("sw : ");
  Serial.println(vsw);
  delay(1000);

  if(vsw == 0){
    Serial.println("reset");
  }
}
