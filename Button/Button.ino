int btn = 4; // S signal
int vcc = 3; // VCC = 5V
int ground = 2; // GND = 0V

void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(ground, OUTPUT);
  Serial.begin(9600);
  digitalWrite(vcc, HIGH);
  digitalWrite(ground, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btn))
  {
    Serial.print("pushed = ");
    Serial.println(digitalRead(btn));
    delay
