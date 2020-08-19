void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  Serial.println("구구단");

  for(int i = 2; i <= 9; i++){
   Serial.print(i);
   Serial.println("단-");
   for(int j = 1; j <= 9; j++){
     Serial.print(i);
     Serial.print(" * ");
     Serial.print(j);
     Serial.print(" = ");
     Serial.println(i*j);
   }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
