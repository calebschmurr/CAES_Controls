const int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
   pinMode(analogPin, INPUT);
   Serial.begin(9600);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
    Serial.println(analogRead(analogPin));
    delay(500);
  }
}
