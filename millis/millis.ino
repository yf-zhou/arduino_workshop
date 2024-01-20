const int LIGHT_PIN = 11;

int counter = 0;

unsigned long previous_time = 0;  // store previous timestamp
unsigned long current_time = 0;   // store current timestamp

bool light_state = 0;

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);

  Serial.begin(9600);  
}

void loop() {
  // blink at 1 Hz
  // if 1 second has passed, toggle light state
  current_time = millis();                  // get current time
  if(current_time - previous_time > 1000){  // if time elapsed is more than 1 second
    if(light_state == 0){                   // if the light is currently off
      digitalWrite(LIGHT_PIN, HIGH);        // turn the light on
      light_state = 1;                      // track light state
    }else{                                  // light is currently on
      digitalWrite(LIGHT_PIN, LOW);         // turn off light
      light_state = 0;                      // track light state
    }

    // update previous timestamp
    previous_time = current_time;
  }
  
  Serial.print("Counter value: ");
  Serial.println(counter);
  counter++;
}
