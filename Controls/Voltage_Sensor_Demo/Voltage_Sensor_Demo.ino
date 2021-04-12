const int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
   pinMode(analogPin, INPUT);
   Serial.begin(9600);
   
}

float multiplier = 0.0251f;
float baseVal = 12.823f;

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
    //float value = (analogRead(analogPin)*multiplier) - baseVal;
    //Serial.println(value);
    Serial.println(analogRead(analogPin));
    delay(100);
  }
}
