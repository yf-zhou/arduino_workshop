// night light struct - define night light functions and attributes
struct NightLight{
   int LIGHT, PHOTO;

  // set pin modes, save attributes
  void do_setup(int led, int photo){
    pinMode(led, OUTPUT);
    pinMode(photo, INPUT);

    LIGHT = led;
    PHOTO = photo;
  }

  // return true if photoresistor senses low light
  // false otherwise
  bool is_dark_out(int threshold = 200){  // default value of threshold
    if(analogRead(PHOTO) < threshold){
      return true;
    }else{
      return false;
    }
  }

  // turn light on
  void turn_light_on(){
    digitalWrite(LIGHT, HIGH);
  }

  // turn light off
  void turn_light_off(){
    digitalWrite(LIGHT, LOW);
  }
};

// set constants
const int LIGHT_PIN = 11, PHOTO_PIN = A0;
const int TOLERANCE = 200;

// create night light instance
NightLight nightlight;

void setup() {
  // setup night light object
  nightlight.do_setup(LIGHT_PIN, PHOTO_PIN);

  // begin serial communication
  Serial.begin(9600);
}

void loop() {
  // turn on light if photoresistor reads low (dark out)
  if(nightlight.is_dark_out()){
    nightlight.turn_light_on();
  }else{
    nightlight.turn_light_off();
  }

}


