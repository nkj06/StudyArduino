// 온습도 센서
// 툴 - 라이브러리 관리에서 DHT 검색해서 설치
#include <DHT.h>
#define DHTTYPE DHT11

int dhtPin = 8;
int vcc = 9;
int ground = 10;

DHT dht(dhtPin, DHTTYPE);

void setup() {
  Serial.begin(9600);

  pinMode(dhtPin, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(ground, OUTPUT);

  digitalWrite(vcc, HIGH);
  digitalWrite(ground, LOW);
  
  dht.begin();
}

void loop() {
  delay(1500);
  float h = dht.readHumidity(); // 습도데이터
  float t = dht.readTemperature(); // 온도 데이터
  Serial.print("습도 : ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("온도 : ");
  Serial.print(t);
  Serial.println(" C");  
}
