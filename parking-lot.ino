#include <Ultrasonic.h>
#include <AccelStepper.h>

const int pin1 = 5;
const int pin2 = 4;
const int pin3 = 3;
const int pin4 = 2;

AccelStepper motor(AccelStepper::FULL4WIRE, pin1, pin3, pin, pin4);

#define TRIGGER_PIN1 11
#define ECHO_PIN1 10
#define TRIGGER_PIN2 9
#define ECHO_PIN2 8
#define TRIGGER_PIN3 7
#define ECHO_PIN3 6

Ultrasonic ultrasonic1(TRIGGER_PIN1, ECHO_PIN1);
Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);
Ultrasonic ultrasonic3(TRIGGER_PIN3, ECHO_PIN3);

int num = 0;

void setup() {
  Serial.begin(9600);
  motor.setMaxSpeed(1000);     
  motor.setAcceleration(500);  
  motor.setSpeed(500);  
}
void loop() {
  long microsec1 = ultrasonic1.timing();
  float cmMsec1 = ultrasonic1.convert(microsec1, Ultrasonic::CM);
  
  long microsec2 = ultrasonic2.timing();
  float cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);
  
  long microsec3 = ultrasonic3.timing();
  float cmMsec3 = ultrasonic3.convert(microsec3, Ultrasonic::CM);

  if (Serial.available()) {
    String receivedMessage = Serial.readString();  
    receivedMessage.trim();                        

    if (receivedMessage.equals("open")) {
      open();
    }

    if (receivedMessage.equals("close")) {
      close();
    }
  }

  if (cmMsec1 <= 5) {
    Serial.println("{\"coords\":\"-22,705076012203207 -47,65258174400175\",\"isOccupied\":1,\"vacancyNumber\":\"1\"}");
  } else {
    Serial.println("{\"coords\":\"-22,705076012203207 -47,65258174400175\",\"isOccupied\":0,\"vacancyNumber\":\"1\"}");
  }

  if (cmMsec2 <= 5) {
    Serial.println("{\"coords\":\"-22,705427771881812 -47,652544130242404\",\"isOccupied\":1,\"vacancyNumber\":\"2\"}");
  } else {
    Serial.println("{\"coords\":\"-22,705427771881812 -47,652544130242404\",\"isOccupied\":0,\"vacancyNumber\":\"2\"}");
  }

  if (cmMsec3 <= 5) {
    Serial.println("{\"coords\":\"-22,705694680527966 -47,65236571169323\",\"isOccupied\":1,\"vacancyNumber\":\"3\"}");
  } else {
    Serial.println("{\"coords\":\"-22,705694680527966 -47,65236571169323\",\"isOccupied\":0,\"vacancyNumber\":\"3\"}");
  }

  delay(1000);
}

void open() {
  motor.move(500);

  while (motor.distanceToGo() != 0) {
    motor.run();
  }
}

void close() {
  motor.move(-500);

  while (motor.distanceToGo() != 0) {
    motor.run();
  }
}
