#include <DHT.h>
#define DHTTYPE DHT11

int sensor = 9;
int vcc = 10;
int ground =11;

DHT dht(sensor, DHTTYPE);

void setup() {
  pinMode(sensor, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(ground, OUTPUT);

  digitalWrite(vcc, HIGH);
  digitalWrite(ground, LOW);

  Serial.begin(9600);
  dht.begin();
}

void loop() {
    float ft = dht.readTemperature();
    float fh = dht.readHumidity();

    Serial.print("TEMP : ");
    Serial.print(ft);
    Serial.println("[c]\t");
    Serial.print("HUMI : ");
    Serial.print(fh);
    Serial.println("[%]\t");
    Serial.println("-------------------");

  delay(1000);
}
