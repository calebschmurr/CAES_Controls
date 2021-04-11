const int analogPin = A2;

void setup() {
  // put your setup code here, to run once:
   pinMode(analogPin, INPUT);
   Serial.begin(9600);
   
}

float multiplier = 1/41.12f;
int baseVal = 0;

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
    float value = (analogRead(analogPin) *multiplier)-baseVal;
    Serial.println(value);
    delay(100);
  }
}
