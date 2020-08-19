void setup() {
  Serial.begin(9600);
  int i = 2;
  do { Serial.println(i--);
  } while(i > 0);
  Serial.println("-------");
  while(i < 0){
    Serial.println(i++);
  }
  Serial.println("--end--");
}

void loop() {
  // put your main code here, to run repeatedly:

}
