const int LIGHT_PIN = 11;

// initialize counter variable
int counter = 0;

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);

  analogWrite(LIGHT_PIN, 125);  

  // set up Serial communication
  Serial.begin(9600);   // set baudrate to 9600 - make sure Serial Monitor matches

}

void loop() {
  // print counter value
  Serial.print("Counter value: ");
  Serial.println(counter);

  // increase counter
  counter++;

}


