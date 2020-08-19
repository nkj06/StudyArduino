// 매직컵라이트
int led = 9;
int sensor = 10;
int vcc = 11;
int ground = 12;

int state = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(ground, OUTPUT);

  digitalWrite(vcc, HIGH);
  digitalWrite(ground, LOW);

  Serial.begin(9600);
}

void loop() {
  int data = digitalRead(sensor);
  if(data == HIGH) {
    if(state != data){
      Serial.print("증가 : ");
      Serial.println(data);
      for(int i=0 ; i<256 ; i++) {
        analogWrite(led, i);
        delay(10);  
      }
    }
  }
  else {
    if(state != data) {
      Serial.print("감소 : ");
      Serial.println(data);
      for(int j=255 ; j>=0 ; j--) {
        analogWrite(led, j);
        delay(10);
      }
    }
  }
  state = data;
  delay(500);
}
