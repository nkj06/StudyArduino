int vccPin = 13;
int gndPin = 12;
int outPin = 11;

int Value = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(vccPin, INPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(outPin, OUTPUT);

}

void loop() {
  Value = digitalRead(vccPin); // 센서값 읽음
  Serial.print("Sersor Value : ");
  Serial.println(Value, DEC);
  delay(1000);
}
