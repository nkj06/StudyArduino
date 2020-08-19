// 조이스틱
int jGrd = A0;
int jVcc = A1;
int jVrx = A2;
int jVry = A3;
int jSw = A4;

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

int menu = 0; // 메뉴 
int i = 0;

void setup() {
  // 조이스틱
  pinMode(jGrd, OUTPUT);
  pinMode(jVcc, OUTPUT);
  pinMode(jVrx, INPUT);
  pinMode(jVry, INPUT);
  pinMode(jSw, INPUT_PULLUP); // pullup = 디지털에서만

  digitalWrite(jGrd, LOW);
  digitalWrite(jVcc, HIGH);

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
  mx = map(analogRead(jVrx), 0, 1023, -1, 2);
  my = map(analogRead(jVry), 0, 1023, 1, -2);
  sw = digitalRead(jSw);

  Serial.print("location : (");
  Serial.print(jVrx);
  Serial.print(", ");
  Serial.print(jVry);
  Serial.println(")");
}
