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

int memu = 0; // 메뉴

void setup() {
  Serial.begin(9600);

  pinMode(jGrd, OUTPUT);
  pinMode(jVcc, OUTPUT);
  pinMode(jVrx, INPUT);
  pinMode(jVry, INPUT);
  pinMode(jSw, INPUT_PULLUP); // pullup = 디지털에서만

  digitalWrite(jGrd, LOW);
  digitalWrite(jVcc, HIGH);
}

void loop() {
  // 조이스틱
  mx = map(analogRead(jVrx), 0, 1023, -5, 6);
  my = map(analogRead(jVry), 0, 1023, 5, -6);
  sw = digitalRead(jSw);
  
  if(!sw)
  {
    Serial.println("STOP");
    x=0;
    y=0;
    delay(500);
  }
  else
  {
    x+=mx;
    y+=my;
  }

  if(x == 0 && y == 0)
  {
    Serial.println("메뉴를 선택해주세요");
    Serial.println("왼쪽 - Melody");
    Serial.println("오른쪽 - Moodlight");
    Serial.println("위 - Security");
    Serial.println("아래 - Streetlamp");
    Serial.println("Push - STOP");
  }
  else if (x == 0 && y > 1)
  {
    Serial.println("위");
    memu = 3;
  }
  else if (x > 1 && y == 0)
  {
    Serial.println("오른쪽");
    memu = 2;
  }
  else if (x < 0 && y == 0)
  {
    Serial.println("왼쪽");
    memu = 1;
  }
  else if (x == 0 && y < 0)
  {
    Serial.println("아래");
    memu = 4;
  }

  x=0;
  y=0;

  delay(500);
}
