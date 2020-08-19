// joystick
int jGrd = A0;
int jVcc = A1;
int jVrx = A2;
int jVry = A3;
int jSw = A4;

int x = 0;
int y = 0;
int sw = 0;
int mx = 0;
int my = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(jGrd, OUTPUT);
  pinMode(jVcc, OUTPUT);
  pinMode(jVrx, INPUT);
  pinMode(jVry, INPUT);
  pinMode(jSw, INPUT_PULLUP); // pullup = 디지털에서만

  digitalWrite(jGrd, LOW);
  digitalWrite(jVcc, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  mx = map(analogRead(jVrx), 0, 1023, -5, 6);
  my = map(analogRead(jVry), 0, 1023, 5, -6);
  sw = digitalRead(jSw);
  
  if(!sw)
  {
    Serial.println("STOP");
    x=0;
    y=0;
    delay(500);
  }
  else if(sw == 1)
  {
    x+=mx;
    y+=my;
  }

  if(x == 0 && y == 0)
  {
    Serial.println("중간");
  }
  else if (x == 0 && y > 1)
  {
    Serial.println("위");
  }
  else if (x > 1 && y == 0)
  {
    Serial.println("오른쪽");
  }
  else if (x < 0 && y == 0)
  {
    Serial.println("왼쪽");
  }
  else if (x == 0 && y < 0)
  {
    Serial.println("아래");
  }

  Serial.print("location : (");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.println(")");

  delay(500);
}
