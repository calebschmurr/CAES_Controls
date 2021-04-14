const int analogPin = A2;

void setup() {
  // put your setup code here, to run once:
   pinMode(analogPin, INPUT);
   Serial.begin(9600);
   
}

float multiplier = 0.0246f;
float baseVal = 0.0552f;

void loop() {
  // put your main code here, to run repeatedly:
  while(true){
    float value = (analogRead(analogPin)*multiplier) - baseVal;
    Serial.println(value);
    //Serial.println(analogRead(analogPin));
    delay(100);
  }
}
