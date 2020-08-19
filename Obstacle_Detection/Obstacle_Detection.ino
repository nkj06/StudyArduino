int sensorpin = 4; // 센서값을 읽을 단자 설정
int val; // 센서값
 
void setup () {
  pinMode (sensorpin, INPUT); // 센서값을 인풋으로 설정

  Serial.begin(9600);
}
 
void loop () {
  val = digitalRead (sensorpin); // 센서값을 읽어옴
  if (val == 0) { // 장애물 감지 안됨
    Serial.println("Safe");
  } 
  else {
    Serial.print("Infrared = ");
    Serial.println(val);
  }
}
