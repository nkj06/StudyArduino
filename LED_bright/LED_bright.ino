// LED 밝기 조절
// LED 범위 0~255
int Ground = 10;
int Red = 11;

void setup() {
  pinMode(Ground, OUTPUT);
  pinMode(Red, OUTPUT);

  digitalWrite(Ground, LOW);
  Serial.begin(9600);
}

void loop(){
  for(int i = 0; i < 256; i++){
    analogWrite(Red, i);
    Serial.print("LED : ");
    Serial.println(i);
  }
  for(int i = 254; i > 0; i--){
    analogWrite(Red, i);
    Serial.print("LED : ");
    Serial.println(i);
  }
}
