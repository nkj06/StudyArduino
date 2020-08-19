int analog = A0;
int ground = A1;
int vcc = A2;
int data = A3;

void setup() {
  pinMode(analog, INPUT);
  pinMode(ground, OUTPUT);
  pinMode(vcc, OUTPUT);
  pinMode(data, OUTPUT);

  digitalWrite(ground, LOW);
  digitalWrite(vcc, HIGH);

  Serial.begin(9600);
}

void loop() {
  int val = analogRead(analog);
  Serial.println(val);
}
