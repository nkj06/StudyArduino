// speaker
#define C 261 // 도
#define D 294 // 레
#define E 330 // 미
#define F 349 // 파
#define G 392 // 솔
#define A 440 // 라
#define B 493 // 시
#define Ch 523 // 도

// 불꽃감지 센서
int sensor = A0;
int ground = A1;
int vcc = A2;

int GNDPIN = 7;
int VCCPIN = 6;
int OUTPIN = 5;

int a[4] = {330,261,330,261};

void setup() {
  Serial.begin(9600);
  
  pinMode(sensor, INPUT);
  pinMode(ground, OUTPUT);
  pinMode(vcc, OUTPUT);

  digitalWrite(ground, LOW);
  digitalWrite(vcc, HIGH);

  pinMode(GNDPIN, OUTPUT);
  pinMode(OUTPIN, OUTPUT);

  digitalWrite(GNDPIN, LOW);
}

void loop() {
  int val = analogRead(sensor);
  Serial.print("value : ");
  Serial.println(val);
  delay(200);

  if (val > 900){
    Serial.println("화재 경보");
    for(int i=0; i<4; i++)
    {
      tone(OUTPIN, a[i]);
      delay(1000);
      noTone(OUTPIN);
    }
  }
}
