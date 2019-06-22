#include "Stepper.h"

#define STEPS 2038

Stepper stepperLeft(STEPS,1,2,3,4);
Stepper stepperRight(STEPS,5,6,7,8);

int startTime;
int loopTime;
int randNumber;
int changeTime = 64000;
void setup() {
  // put your setup code here, to run once:
  startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  loopTime = millis();
  chooseMethod();
}

void chooseMethod(){
    switch(randNumber){
    case 0:
    stepperLeftForward(1);
    stepperRightForward(1);
    break;
    case 1: 
    stepperLeftForward(1);
    break;
    case 2:
    stepperRightForward(1);
    break;
    case 3:
    stepperLeftReverse(-1);'
    break;
    case 4:
    stepperRightReverse(-1);
    break;
    case 5:
    stepperLeftReverse(-1);
    stepperRightReverse(-1);
    break;
  }
  if(loopTime - startTime >= changeTime){
      randNumber = random(6);
      startTime = millis();
  }
}

void stepperLeftForward(float rpm){
  if(rpm > 0){
    stepperLeft.setSpeed(rpm);
    stepperLeft.step(2038);
  }
}

void stepperRightForward(float rpm){
  if(rpm > 0){
    stepperRight.setSpeed(rpm);
    stepperRight.step(2038);
  }
}

void stepperLeftReverse(float rpm){
  if(rpm > 0){
    stepperLeft.setSpeed(rpm);
    stepperLeft.step(-2038);
  }
}

void stepperRightReverse(float rpm){
  if(rpm > 0){
    stepperRight.setSpeed(rpm);
    stepperRight.step(-2038);
  }
}
