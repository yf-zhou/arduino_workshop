const int LIGHT_PIN = 11, PHOTO_PIN = A0;
const int TOLERANCE = 200;

int photo_value;

void setup() {
  // set pin modes
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(PHOTO_PIN, INPUT);

  // begin serial communication
  Serial.begin(9600);
}

void loop() {
  // read photoresistor value
  photo_value = analogRead(PHOTO_PIN);

  // turn on light if photoresistor reads low (dark out)
  if(photo_value < TOLERANCE){
    digitalWrite(LIGHT_PIN, HIGH);
  }else{
    digitalWrite(LIGHT_PIN, LOW);
  }

}


