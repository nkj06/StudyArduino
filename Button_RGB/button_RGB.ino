int btn = 7; // S signal
int vcc = 6; // VCC = 5V
int ground = 5; // GND = 0V

int Ground = 8;
int Red = 9;
int Green = 10;
int Blue = 11;

int i = 0;

void setup() {
  pinMode(btn, INPUT_PULLUP); // 디지털을 사용하겠다는 것
  pinMode(vcc, OUTPUT);
  pinMode(ground, OUTPUT);
  Serial.begin(9600);
  digitalWrite(vcc, HIGH);
  digitalWrite(ground, LOW);

  pinMode(Ground, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  digitalWrite(Ground, LOW);
}

void loop() {

  if(digitalRead(btn)){
   Serial.print("pushed = ");
   Serial.println(digitalRead(btn));
   delay(500);
  }
  else{
   if(i > 2)
   {
    i = i-3;
   }
   if (i == 0){
    digitalWrite(Red, HIGH); // R
    delay(500);
    digitalWrite(Red, LOW);
    i = i+1;
   }
   else if (i == 1){
    digitalWrite(Green, HIGH); // G
    delay(1000);
    digitalWrite(Green, LOW);
    i++;
   }
   else if (i == 2){
     digitalWrite(Blue, HIGH); // B
     delay(1000);
     digitalWrite(Blue, LOW);
     i++;
   }
  }
}
