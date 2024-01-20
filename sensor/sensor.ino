const int PHOTO_PIN = A0;
int photo_value;

void setup() {
  pinMode(PHOTO_PIN, INPUT);  // set photoresistor pin to input mode

  Serial.begin(9600);

}

void loop() {
  // read voltage at photoresistor pin
  photo_value = analogRead(PHOTO_PIN);  // 0V -> reads 0; 5V -> reads 1023
  Serial.println(photo_value);

}


