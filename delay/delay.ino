const int LIGHT_PIN = 11;

int counter = 0;

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);

  Serial.begin(9600);  
}

void loop() {
  // blink at 1 Hz
  // light on
  analogWrite(LIGHT_PIN, 255); 
  // wait
  delay(1000);  // delay(<time in milliseconds>) 
  // light off
  analogWrite(LIGHT_PIN, 0);
  // wait
  delay(1000);


  Serial.print("Counter value: ");
  Serial.println(counter);
  counter++;

}


