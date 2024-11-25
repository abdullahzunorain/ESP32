#define ledpin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(touchRead(T0));
  if(touchRead(T0) < 25){
    digitalWrite(ledpin, HIGH);
  }
  else{
    digitalWrite(ledpin, LOW);
  }
  delay(200);
}
