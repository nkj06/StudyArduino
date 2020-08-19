int angle = 13;
int vcc = 12;
int ground = 11;


void setup() {
  pinMode(angle, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(ground, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int data = digitalRead(angle);
  if(data == HIGH)
  {
    Serial.println("angle");
    delay(1000);
  }
  else if(data == LOW)
  {
    Serial.println("noangle");
    delay(1000);
  }
}
