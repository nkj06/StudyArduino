int vccPin = 13;
int gndPin = 12;
int outPin = 11;

int Ground = 4;
int Red = 5;
int Green = 6;
int Blue = 7;

int Value = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(vccPin, INPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(outPin, OUTPUT);

  pinMode(Ground, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  digitalWrite(Ground, LOW);

}

void loop() {
  Value = digitalRead(vccPin); // 센서값 읽음
  Serial.print("Sersor Value : ");
  Serial.println(Value, DEC);

  if(Value == 0){
    digitalWrite(Red, HIGH); // R
    delay(500);
    digitalWrite(Red, LOW);
  }
  else{
    digitalWrite(Blue, HIGH); // B
    delay(1000);
    digitalWrite(Blue, LOW);
  }
  delay(1000);
}
