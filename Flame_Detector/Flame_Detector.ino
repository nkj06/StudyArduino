// 불꽃감지 센서
int sensor = A0;
int ground = A1;
int vcc = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(sensor, INPUT);
  pinMode(ground, OUTPUT);
  pinMode(vcc, OUTPUT);

  digitalWrite(ground, LOW);
  digitalWrite(vcc, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ADC_value = analogRead(sensor);
  Serial.print("ADC_value : ");
  Serial.println(ADC_value);
  delay(200);
}
