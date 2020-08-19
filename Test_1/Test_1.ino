// 엔코더
int g = 3;
int v = 4;
int esw = 5;
int ap = 6;  //dt
int bp = 7;  //clk

// LED
int Ground = 8;
int Red = 9;
int Green = 10;
int Blue = 11;

// 필요한 변수들
int newa = 0;
int newb = 0;

int olda = 0;
int oldb = 0;

int count = 0; 
int btn = 1;

void setup() {
  // 엔코더
  pinMode(g, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(esw, INPUT_PULLUP);
  pinMode(ap, INPUT_PULLUP);
  pinMode(bp, INPUT_PULLUP);

  digitalWrite(g, LOW);
  digitalWrite(v, HIGH);

  // LED
  pinMode(Ground, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  digitalWrite(Ground, LOW);

  // 시리얼
  Serial.begin(9600);
}

void loop() {
  newa = digitalRead(ap);
  newb = digitalRead(bp);
  
  if(digitalRead(esw) == 0){  // 버튼이 눌러졌을 때 
    if(btn < 4)
    {
      btn++;
    }
    else{
      btn = 1;
    }
    Serial.print("버튼이 눌러짐: ");
    Serial.println(btn);
    delay(500);
  }
  
  if(newa != olda || newb != oldb) {
    if(olda == LOW && newa == HIGH) {
      if(oldb == LOW) {
        count++;
        if(count > 255) // 밝기 최대 255
        {
          count = 255;
          Serial.println("왼쪽으로 돌려주세요");
        }
      }
      else {
        count--;
        if(count < 0) // 밝기 최소 0
        {
          Serial.println("오른쪽으로 돌려주세요");
          count = 0;
        }
      }
    }
  }
  if(btn == 1){ // 빨간색
    analogWrite(Red, count);
    analogWrite(Blue, 0);
    analogWrite(Green, 0);
  }
  else if(btn == 2){ // 초록색
    analogWrite(Green, count);
    analogWrite(Red, 0);
    analogWrite(Blue, 0);
  }
  else if(btn == 3){ // 파란색
    analogWrite(Blue, count);
    analogWrite(Red, 0);
    analogWrite(Green, 0);
  }
  else if(btn == 4){ // 꺼짐
    analogWrite(Red, 0);
    analogWrite(Blue, 0);
    analogWrite(Green, 0);
  }
  
  olda = newa;
  oldb = newb;

  Serial.println(count);
}
