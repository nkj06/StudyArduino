#define C 261 // 도
#define D 294 // 레
#define E 330 // 미
#define F 349 // 파
#define G 392 // 솔
#define A 440 // 라
#define B 493 // 시
#define Ch 523 // 도

// 조이스틱
int jg = A0; // gnd
int jv = A1; // vcc
int jx = A2; // x좌표
int jy = A3; // y좌표
int jsw = A4; //switch

int x = 0;
int y = 0;
int sw = 0;
int mx = 0;
int my = 0;

// 부저
int GNDPIN = 0;
int VCCPIN = 1;
int OUTPIN = 2;

int a[8] = {261,294,330,349,392,440,493,523};

// LED
int Ground = 8;
int Red = 9;
int Green = 10;
int Blue = 11;

// 조도센서
int sensor = A0;
int vcc = A1;
int gnd = A2;

// 버튼
int btn = 5; // S signal
int v = 6; // VCC = 5V
int g = 7; // GND = 0V

// 필요한 변수
int newa = 0;
int newb = 0;

int olda = 0;
int oldb = 0;

int count = 0;

int memu = 3; // 메뉴 
int i = 0;

void setup() {
  // 조이스틱
  pinMode(jg, OUTPUT);
  pinMode(jv, OUTPUT);
  pinMode(jx, INPUT);
  pinMode(jy, INPUT);
  pinMode(jsw, INPUT_PULLUP);

  digitalWrite(jv, HIGH);
  digitalWrite(jg, LOW);
  
  // 부저
  pinMode(GNDPIN, OUTPUT);
  pinMode(OUTPIN, OUTPUT);

  digitalWrite(GNDPIN, LOW);

  // LED
  pinMode(Ground, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  digitalWrite(Ground, LOW);

  // 조도센서
  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(sensor, INPUT);

  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);

  // 버튼
  pinMode(btn, INPUT_PULLUP); // 디지털을 사용하겠다는 것
  pinMode(v, OUTPUT);
  pinMode(g, OUTPUT);

  digitalWrite(v, HIGH);
  digitalWrite(g, LOW);

  // 시리얼 통신
  Serial.begin(9600);
}

void loop() {
  // 조이스틱
  int vrx = analogRead(jx);
  int vry = analogRead(jy);
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
  
  // 조도 센서
  int val = analogRead(sensor);

  if(memu == 1){ // 왼쪽, 멜로디
    for(int i=0; i<8; i++)
    {
      tone(OUTPIN, a[i]);
      delay(1000);
      noTone(OUTPIN);
    }
  }
  else if(memu == 2){ // 무드등
    if(digitalRead(btn) == 0){
      i++;
      if(i > 3)
      {
        i = i-4;
      }
      if(i == 1){ // 빨간색
        analogWrite(Red, 255);
        analogWrite(Blue, 0);
        analogWrite(Green, 0);
      }
      else if(i == 2){ // 초록색
        analogWrite(Red, 0);
        analogWrite(Green, 255);
        analogWrite(Blue, 0);
      }
      else if(i == 3){ // 파란색
        analogWrite(Red, 0);
        analogWrite(Green, 0);
        analogWrite(Blue, 255);
      }
      else if(i == 0){ // 꺼짐
        analogWrite(Red, 0);
        analogWrite(Blue, 0);
        analogWrite(Green, 0);
      }
    }
  }

  else if(memu == 3){ // 보안 빨간불 깜빡
    if (val > 300){
      for(int i = 0; i < 8; i++){
        tone(OUTPIN, 330);
        noTone(OUTPIN);
        analogWrite(Red, 255);
        delay(5);
        analogWrite(Red, 0);
        delay(5);
      }
    }
    else{
      analogWrite(Red, 0);
    }
  }

  else if(memu == 4){ // 가로등
    if (val > 300){
      analogWrite(Blue, 255);
    }
    else{
      analogWrite(Blue, 0);
    }
  }

  delay(500);
}
