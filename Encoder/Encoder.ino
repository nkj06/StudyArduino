// 엔코더
int g = 2;
int v = 3;
int sw = 4;
int ap = 5;  //dt
int bp = 6;  //clk

int newa = 0;
int newb = 0;

int olda = 0;
int oldb = 0;

int count = 0;

void setup() {
  pinMode(g, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(sw, INPUT);
  pinMode(ap, INPUT_PULLUP);
  pinMode(bp, INPUT_PULLUP);

  digitalWrite(g, LOW);
  digitalWrite(v, HIGH);

  Serial.begin(9600);
}

void loop() {
  newa = digitalRead(ap);
  newb = digitalRead(bp);
  if(newa != olda || newb != oldb) {
    if(olda == LOW && newa == HIGH) {
      if(oldb == LOW) count++;
      else count--;
    }
  }
  olda = newa;
  oldb = newb;

  Serial.println(count);
}
