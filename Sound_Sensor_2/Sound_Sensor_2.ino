int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read
int g = A2;
int p = A1;


void setup() {
  Serial.begin(9600);           //  setup serial
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  pinMode(analogPin, INPUT);
  digitalWrite(p, HIGH);
  digitalWrite(g, LOW);
  
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);          // debug value

  delay(500);
}
