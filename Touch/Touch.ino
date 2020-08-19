// 터치센서로 LED 제어
int touch = A0;

int Ground = 8;
int B = 11;

int val = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(touch, INPUT);

  pinMode(Ground, OUTPUT);
  pinMode(B, OUTPUT);

  digitalWrite(Ground, LOW);
}

void loop() {
  val = analogRead(touch);
  if(val == HIGH){
    Serial.println("Touch");
    analogWrite(B, 255);
    delay(100);
  }
  else{
    analogWrite(B, 0);
  }
}
