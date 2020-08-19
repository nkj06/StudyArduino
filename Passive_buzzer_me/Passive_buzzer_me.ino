// speaker
#define C 261 // 도
#define D 294 // 레
#define E 330 // 미
#define F 349 // 파
#define G 392 // 솔
#define A 440 // 라
#define B 493 // 시
#define Ch 523 // 도

int GNDPIN = 7;
int VCCPIN = 6;
int OUTPIN = 5;

int val = 0;
int number = 0;

int a[8] = {261,294,330,349,392,440,493,523};
int b[27] = {392,330,330,349,294,294,261,294,330,349,392,392,392,392,330,330,330,349,294,294,261,330,392,330,294,330,261};

void setup() {
  Serial.begin(9600);
  
  pinMode(GNDPIN, OUTPUT);
  pinMode(OUTPIN, OUTPUT);

  digitalWrite(GNDPIN, LOW);

}

void loop() {
  val = Serial.read(); // 시리얼통신에 입력한 값 읽어오기
  Serial.println(val);
  number = (val - '0');
  if(number == 1){
    Serial.print(number);
    Serial.println("번 도레미파솔라시도 재생");
    for(int i=0; i<8; i++)
    {
     tone(OUTPIN, a[i]);
     delay(500);
     noTone(OUTPIN);
    }
  }
  else if(number == 2){
    Serial.print(number);
    Serial.println("번 나비야 재생");
    for(int i=0; i<27; i++)
    {
     tone(OUTPIN, b[i]);
     delay(500);
     noTone(OUTPIN);
    }
  }
}
