// import newping library
#include "NewPing.h"

// define pins
const int trig_pin = 11;
const int echo_pin = 10;

// motor a
const int en_a = 9;
const int in1 = 8;
const int in2 = 7;
// motor b
const int en_b = 3;
const int in3 = 5;
const int in4 = 4;

// max distance to ping for (cm)
#define MAX_DISTANCE 60
// set up newping object
NewPing sonar(trig_pin, echo_pin, MAX_DISTANCE);

void setup() {
  // motors
  pinMode(en_a, OUTPUT);
  pinMode(en_b, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // initial state
  digitalWrite(trig_pin, LOW);
  // motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // begin serial communication
  Serial.begin(9600);

}

// function prototype
void go_forwards(int speed);
void move();

int speed;

void loop() {
  // READ FROM SENSOR
  distance = sonar.ping_cm();
  // if ping reads 0, read as max
  distance = (distance == 0) ? MAX_DISTANCE : distance;
  // display
  Serial.print("distance: ");
  Serial.println(distance);

  // CONTROL WHEELS
  if(distance == 0){
    stop();
  }else{
    speed = distance / MAX_DISTANCE * 255;
    go_forwards(speed);
  }
}

void go_forwards(int speed){
  // set speed
  analogWrite(en_a, speed);
  analogWrite(en_b, speed);
  // set direction and turn on motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop(){
    // set speed
  analogWrite(en_a, 0);
  analogWrite(en_b, 0);
  // turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
