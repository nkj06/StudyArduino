// speaker
#define C 261 // 도
#define D 294 // 레
#define E 330 // 미
#define F 349 // 파
#define G 392 // 솔
#define A 440 // 라
#define B 493 // 시
#define Ch 523 // 도

int GNDPIN = 2;
int VCCPIN = 1;
int OUTPIN = 0;

int a[8] = {261,294,330,349,392,440,493,523};

void setup() {
  pinMode(GNDPIN, OUTPUT);
  pinMode(OUTPIN, OUTPUT);

  digitalWrite(GNDPIN, LOW);

}

void loop() {
  for(int i=0; i<8; i++)
  {
    tone(OUTPIN, a[i]);
    delay(1000);
    noTone(OUTPIN);
  }
}
