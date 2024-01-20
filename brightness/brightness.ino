// store LED pin number as variable
const int LIGHT_PIN = 11;

void setup() {
  // set LED pin to output mode
  pinMode(LIGHT_PIN, OUTPUT);

  // set output of pin to be ~2.5 V
  // analogWrite(<pin number>, <value between 0 (always off) and 255 (always on)>)
  analogWrite(LIGHT_PIN, 125);  

}

void loop() {
  // ignore for now

}


